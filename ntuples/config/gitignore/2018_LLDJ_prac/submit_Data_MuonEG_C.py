if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from httplib import HTTPException

    from CRABClient.UserUtilities import config
    config = config()
    
    from multiprocessing import Process

    # Common configuration

    config.General.workArea           = 'crabsubmits_2018_LLDJ_prac'
    config.General.transferLogs       = False
    config.JobType.pluginName         = 'Analysis' # PrivateMC
    config.JobType.psetName           = 'run_data_102XAOD.py'
    #config.JobType.inputFiles         = [INPUTFILES]
    config.JobType.allowUndistributedCMSSW = True
    config.JobType.sendExternalFolder = True
    config.JobType.maxMemoryMB        = 3000
    #config.JobType.maxJobRuntimeMin   = MAXTM
    config.JobType.numCores           = 4
    #config.JobType.priority           = 50 # default=10, first 10 jobs=20
    config.Data.inputDBS              = 'global'    
    config.Data.splitting             = 'Automatic' # 'LumiBased' EventBased, FileBased, LumiBased (1 lumi ~= 300 events)
    config.Data.totalUnits            = -1
    config.Data.publication           = False
    #config.Data.publication           = True
    #config.Data.publishWithGroupName  = True
    config.Site.storageSite           = 'T3_US_FNALLPC'

    #config.Data.useParent             = True
    config.Data.ignoreLocality         = True
    config.Site.whitelist = ["T2_US*"]

    def submit(config):
        try:
            crabCommand('submit', config = config)
            #crabCommand('submit', config = config, dryrun=True)
        except HTTPException, hte:
            print hte.headers

    # dataset dependent configuration

    config.General.requestName = 'Data_MuonEG_C'
    config.Data.unitsPerJob    = 180
    config.Data.inputDataset   = '/MuonEG/Run2018C-17Sep2018-v1/AOD'
    config.Data.lumiMask = '/uscms/home/skim2/nobackup/2018-LLDJ_slc6_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/jsons/Cert_314472-325175_13TeV_PromptReco_Collisions18_JSON.txt'
    config.Data.outLFNDirBase  = '/store/group/lpchbb/LLDJntuples/2018_LLDJ_prac'
    p = Process(target=submit, args=(config,))
    p.start()
    p.join()
