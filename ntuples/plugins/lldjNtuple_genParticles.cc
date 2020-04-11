#include "2018lldj/ntuples/interface/lldjNtuple.h"
#include "2018lldj/ntuples/interface/GenParticleParentage.h"
#include <TMath.h>
#include <TLorentzVector.h>

using namespace std;

bool ctauWeight = false; //Determine whether to weight or not weight the SigMC
float targetdist = 30; //To weight it, determine the target distance

//Recommended targetdist range : 10mm sample->1mm<ct<10mm
			//	 100mm sample->10mm<ct<100mm
			//	 1000mm	samplet->100mm<ct<1000mm


//Variables for branches
vector<int>   llpId;
vector<int>   llpStatus;
vector<float> llpPt;
vector<float> llpEta;
vector<float> llpPhi;
vector<float> llpMass;
vector<int>   llpDaughterId;
vector<int>   llpDaughterStatus;
vector<float> llpDaughterPt;
vector<float> llpDaughterEta;
vector<float> llpDaughterPhi;
vector<float> llpDaughterMass;
vector<float> toppts;
vector<float> Decaydist;
vector<float> Simweight;
//vector<float> ctauEventWeight;
Float_t ctauEventWeight;


float gen_Z_mass;
float gen_Z_energy;
float gen_Z_pt;
float gen_Z_eta;
float gen_Z_phi;
float gen_Z_dauther1_Id;
float gen_Z_dauther2_Id;

std::vector<float> gen_lep_energy;
std::vector<float> gen_lep_pt;
std::vector<float> gen_lep_eta;
std::vector<float> gen_lep_phi;
std::vector<int>   gen_lep_Id;
std::vector<int>   gen_lep_momId;

vector<float> llpvX;
vector<float> llpvY;
vector<float> llpvZ;
vector<float> llpDaughtervX;
vector<float> llpDaughtervY;
vector<float> llpDaughtervZ;
void lldjNtuple::branchesGenPart(TTree* tree) {

  tree->Branch("llpId",             &llpId);
  tree->Branch("llpStatus",         &llpStatus);
  tree->Branch("llpPt",             &llpPt);
  tree->Branch("llpEta",            &llpEta);
  tree->Branch("llpPhi",            &llpPhi);
  tree->Branch("llpMass",           &llpMass);
  tree->Branch("llpDaughterId",     &llpDaughterId);
  tree->Branch("llpDaughterStatus", &llpDaughterStatus);
  tree->Branch("llpDaughterPt",     &llpDaughterPt);
  tree->Branch("llpDaughterEta",    &llpDaughterEta);
  tree->Branch("llpDaughterPhi",    &llpDaughterPhi);
  tree->Branch("llpDaughterMass",   &llpDaughterMass);
  tree->Branch("toppts",            &toppts);
  if (ctauWeight) {tree->Branch("Decaydist",         &Decaydist);
  tree->Branch("Simweight",         &Simweight);
  tree->Branch("ctauEventWeight",   &ctauEventWeight);
}

  //z-boson
  tree->Branch("gen_Z_mass",           &gen_Z_mass);
  tree->Branch("gen_Z_energy",         &gen_Z_energy);
  tree->Branch("gen_Z_pt",             &gen_Z_pt);
  tree->Branch("gen_Z_eta",            &gen_Z_eta);
  tree->Branch("gen_Z_phi",            &gen_Z_phi);
  tree->Branch("gen_Z_dauther1_Id",    &gen_Z_dauther1_Id);
  tree->Branch("gen_Z_dauther2_Id",    &gen_Z_dauther2_Id);

  //gen_leptons
  tree->Branch("gen_lep_energy",   &gen_lep_energy);
  tree->Branch("gen_lep_pt",       &gen_lep_pt);
  tree->Branch("gen_lep_eta",      &gen_lep_eta);
  tree->Branch("gen_lep_phi",      &gen_lep_phi);
  tree->Branch("gen_lep_Id",       &gen_lep_Id);
  tree->Branch("gen_lep_momId",    &gen_lep_momId);

  tree->Branch("llpvX",             &llpvX);
  tree->Branch("llpvY",             &llpvY);
  tree->Branch("llpvZ",             &llpvZ);
  tree->Branch("llpDaughtervX",             &llpDaughtervX);
  tree->Branch("llpDaughtervY",             &llpDaughtervY);
  tree->Branch("llpDaughtervZ",             &llpDaughtervZ);

}

const reco::GenParticle* findFirstMotherWithDifferentID(const reco::GenParticle* particle){

  if( particle == 0 ){
    printf("ERROR! null candidate pointer, this should never happen\n");
    return 0;
  }

  // Is this the first parent with a different ID? If yes, return, otherwise
  // go deeper into recursion
  if (particle->numberOfMothers() > 0 && particle->pdgId() != 0) {
    if (particle->pdgId() == particle->mother(0)->pdgId()
	&& particle->mother(0)->status() != 11  // prevent infinite loop for sherpa documentation gluons
	) {
      return findFirstMotherWithDifferentID((reco::GenParticle*)particle->mother(0));
    } else {
      return (reco::GenParticle*)particle->mother(0);
    }
  }

  return 0;
}

auto sort_genlep = []( std::pair<TLorentzVector,std::pair<int,int> > a,
   std::pair<TLorentzVector,std::pair<int,int> > b )
   { return a.first.Pt() > b.first.Pt() ?  true : false; };

void fillLeptonGenInfo(edm::Handle<vector<reco::GenParticle> > genParticlesHandle)
{
  //-------------------------
  //find leptons and Z
  //-------------------------
  std::vector< std::pair< TLorentzVector, std::pair<int,int> > > gen_leptons;
  for(const auto &ip : *genParticlesHandle )
  {
    //-------------------------
    //find leptons
    //-------------------------
    if( (abs(ip.pdgId()) == 11 || abs(ip.pdgId()) == 13 || abs(ip.pdgId()) == 15)
     && ip.isLastCopy() )
    {
      const reco::GenParticle* mother = findFirstMotherWithDifferentID(&ip);
      if( abs(mother->pdgId()) > 50 ) continue;//remove leptons from mesons
      TLorentzVector lepton;
      lepton.SetPtEtaPhiM(ip.pt(), ip.eta(), ip.phi(), ip.mass());
      gen_leptons.push_back(std::make_pair(lepton, std::make_pair(ip.pdgId(),mother->pdgId()) ) );
    }
    //-------------------------
    //find Z
    //-------------------------
    if( abs(ip.pdgId() == 23) && ip.isLastCopy() )
    {
      gen_Z_mass   = ip.mass();
      gen_Z_energy = ip.energy();
      gen_Z_pt     = ip.pt();
      gen_Z_eta    = ip.eta();
      gen_Z_phi    = ip.phi();

      if( ip.numberOfDaughters() >= 2 )
      {
        gen_Z_dauther1_Id = (ip.daughter(0))->pdgId();
        gen_Z_dauther2_Id = (ip.daughter(1))->pdgId();
      }
      else if ( ip.numberOfDaughters() == 1 )
      {
        gen_Z_dauther1_Id = (ip.daughter(0))->pdgId();
      }

    }
  }//end gen-particle loop

  std::sort(gen_leptons.begin(), gen_leptons.end(), sort_genlep);
  for( auto& gen_lep : gen_leptons )
  {
    gen_lep_energy.push_back( gen_lep.first.E() );
    gen_lep_pt.push_back( gen_lep.first.Pt() );
    gen_lep_eta.push_back( gen_lep.first.Eta() );
    gen_lep_phi.push_back( gen_lep.first.Phi() );
    gen_lep_Id.push_back( gen_lep.second.first );
    gen_lep_momId.push_back( gen_lep.second.second );
  }

};

void ResetVariables()
{
   gen_Z_mass   = -999.;
   gen_Z_energy = -999.;
   gen_Z_pt     = -999.;
   gen_Z_eta    = -999.;
   gen_Z_phi    = -999.;
   gen_Z_dauther1_Id = -999;
   gen_Z_dauther2_Id = -999;

   gen_lep_energy.clear();
   gen_lep_pt.clear();
   gen_lep_eta.clear();
   gen_lep_phi.clear();
   gen_lep_Id.clear();
   gen_lep_momId.clear();

};

void lldjNtuple::fillGenPart(const edm::Event& e) {

  //Initialize -- set numbers to e.g. 0 and clear vectors
  ResetVariables();//initialize lepton and z variables
  llpId.clear();
  llpStatus.clear();
  llpPt.clear();
  llpEta.clear();
  llpPhi.clear();
  llpMass.clear();
  llpDaughterId.clear();
  llpDaughterStatus.clear();
  llpDaughterPt.clear();
  llpDaughterEta.clear();
  llpDaughterPhi.clear();
  llpDaughterMass.clear();
  toppts.clear();
  if (ctauWeight){Decaydist.clear();
  Simweight.clear();
  ctauEventWeight = 0.0;
}

  llpvX.clear();
  llpvY.clear();
  llpvZ.clear();
  llpDaughtervX.clear();
  llpDaughtervY.clear();
  llpDaughtervZ.clear();

  //Gen particles handle
  edm::Handle<vector<reco::GenParticle> > genParticlesHandle;
  e.getByToken(genParticlesCollection_, genParticlesHandle);
  float totEventWeight =1.0;

  //-----------------
  //fill lepton and z
  //-----------------
  fillLeptonGenInfo(genParticlesHandle);

  //Loop over gen particles
  for (vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {

    reco::GenParticleRef partRef = reco::GenParticleRef(genParticlesHandle,
							ip-genParticlesHandle->begin());
    genpartparentage::GenParticleParentage particleHistory(partRef);

    //Save top particles
    if( abs(ip->pdgId()) == 6 && ip->isLastCopy() ){
     toppts.push_back( ip->pt() );
    }
    //Save long lived BSM particles
    if( abs(ip->pdgId()) == 9000006 ){
      llpId.push_back(      ip->pdgId() );
      llpStatus.push_back(  ip->status() );
      llpPt.push_back(      ip->pt()    );
      llpEta.push_back(     ip->eta()   );
      llpPhi.push_back(     ip->phi()   );
      llpMass.push_back(    ip->mass()  );
      llpvX.push_back(    ip->vx()  );
      llpvY.push_back(    ip->vy()  );
      llpvZ.push_back(    ip->vz()  );
      TVector3 mother,daughter,diff;
      for(size_t j=0; j<ip->numberOfDaughters(); ++j){
	const reco::Candidate* d = ip->daughter(j);
	  llpDaughtervX.push_back(d->vx());
	  llpDaughtervY.push_back(d->vy());
	  llpDaughtervZ.push_back(d->vz());
	  mother.SetXYZ(ip->vx(),ip->vy(),ip->vz());
	  daughter.SetXYZ(d->vx(),d->vy(),d->vz());
   	  diff.SetXYZ(mother.X()-daughter.X(),mother.Y()-daughter.Y(),mother.Z()-daughter.Z());
	}

	TLorentzVector scalar;
	scalar.SetPtEtaPhiM(ip->pt(),ip->eta(),ip->phi(),ip->mass());
	float dist = diff.Mag()/(scalar.Gamma()*abs(scalar.Beta()));
        if(ctauWeight){Decaydist.push_back(dist);
	float weight = calculatectauEventWeight(dist);
	Simweight.push_back(weight);
        totEventWeight *= weight;}
    }
    else if ( particleHistory.hasRealParent() ) {
      reco::GenParticleRef momRef = particleHistory.parent();
      if ( momRef.isNonnull() && momRef.isAvailable() ) {
	if( abs(momRef->pdgId()) == 9000006 ){
	  llpDaughterId.push_back(     ip->pdgId() );
	  llpDaughterStatus.push_back( ip->status() );
	  llpDaughterPt.push_back(     ip->pt()    );
	  llpDaughterEta.push_back(    ip->eta()   );
	  llpDaughterPhi.push_back(    ip->phi()   );
	  llpDaughterMass.push_back(   ip->mass()  );
	}
      }
    }

  }//end gen loop
  float TTSF = 1.;
  if(toppts.size() == 2){
   TTSF = TTSF * exp( 0.0615 - 0.0005*toppts.at(0)) * exp( 0.0615 - 0.0005*toppts.at(1));
  }
  hTTSF_->Fill( TTSF );
  if(ctauWeight) ctauEventWeight = totEventWeight;

}

Float_t lldjNtuple::calculatectauEventWeight( float dist )
{
 float weight, factor;
if (targetdist<10 && 1 < targetdist) {
	factor = 10./targetdist;
        weight = factor*exp(-1*(factor-1)*dist);
}
else if (targetdist<100 && 10 < targetdist) {
	factor = 100./targetdist;
        weight = factor*exp(-.1*(factor-1)*dist);
}

else if (targetdist<1000 && 100< targetdist) {
	factor = 1000./targetdist;
        weight = factor*exp(-.01*(factor-1)*dist);
}
else  {
    std::cerr << "Targetdist out of range. Please read insturction for targetdist range for each SigMC sample." <<std::endl;
   abort();
	}
 return weight;
 }
