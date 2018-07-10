#!/usr/bin/env python
from setup.pyPlotter import *
# ---------------------------------------------------------------------------------
gROOT.ProcessLineSync('.L tools/customFunctions.C')
gROOT.ProcessLineSync('.L tools/customFudgeFactors_2016.C')
gROOT.ProcessLineSync('.L tools/matrixMethod_2016.C')
gROOT.ProcessLineSync('.L tools/leptonSFs_2016.C')
gROOT.ProcessLineSync('.L tools/pileupWeights_2016.C')
gROOT.ProcessLineSync('.L tools/triggerEffScaleFactor_2016.C')
# ---------------------------------------------------------------------------------
print "runPlotter.py BEGIN"


# ---------------------------------------------------------------------------------
#   Analysis name, used to create the output directory & files
# ---------------------------------------------------------------------------------
pset.analysis="L4All_2016"

pset.fraction = 1.0
pset.hpuName = ""

# ---------------------------------------------------------------------------------
#   Global selection settings
# ---------------------------------------------------------------------------------
pset.globalselection="(L4OSSF1||L4OSSF2)&&LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0&&L4VLL>0"


# ---------------------------------------------------------------------------------
#   Variable settings
# ---------------------------------------------------------------------------------
pset.setAliases=True # WARNING:: See alias definitions here: tools/Aliases.py
pset.variables=[#Parameters: VariableName, nBins, xLow, xHigh, custom xLabel, isDiscrete/isContinuous
# WARNING:: Discrete variables need to be defined with bins of width 1, centered on integer numbers; i.e. bin at "2" should have a low-edge at 1.5, and high-edge at 2.5
("BDT",27,-1,.8,"BDT",pset.isContinuous)
,("L4OSSF1",2,-0.5,1.5,"L4OSSF1",pset.isDiscrete)
,("L4OSSF2",2,-0.5,1.5,"L4OSSF2",pset.isDiscrete)
,("BJetN",3,-0.5,2.5,"No. of b-Jets",pset.isDiscrete)
,("JetN[0]",6,-0.5,5.5,"No. of Jets",pset.isDiscrete)
,("MET",36,0,900,"E_{T}^{miss} (GeV)",pset.isContinuous)
,("HT",40,0,1000,"H_{T} (GeV)",pset.isContinuous)
,("LT4D",40,0,1000,"L_{T} (GeV)",pset.isContinuous)
,("LTplusMET4D",40,0,1000,"L_{T} + E_{T}^{miss} (GeV)",pset.isContinuous)
,("LightLeptonBestMOSSF[0]",30,0,300,"M_{OSSF} (GeV)",pset.isContinuous)
,("LightLeptonMinMOSSF[0]",30,0,150,"M_{OSSF}^{min} (GeV)",pset.isContinuous)
,("LightLeptonMass[0]",40,0,1000,"M_{4L} (GeV)",pset.isContinuous)
,("LightLeptonPairMass[0]",30,0,150,"Closest Dilepton Pair Mass (GeV)",pset.isContinuous)
,("LightLeptonPairDR[0]",50,0,5,"Minimum #DeltaR^{Leptons}",pset.isContinuous)
,("LightLeptonPairPt[0]",50,0,500,"Closest Dilepton Pair P_{T} (GeV)",pset.isContinuous)
,("LightLeptonPt[0]",60,0,600,"1st Lepton P_{T} (GeV)",pset.isContinuous)
,("LightLeptonPt[1]",50,0,500,"2nd Lepton P_{T} (GeV)",pset.isContinuous)
,("LightLeptonPt[2]",40,0,400,"3rd Lepton P_{T} (GeV)",pset.isContinuous)
,("LightLeptonPt[3]",30,0,200,"4th Lepton P_{T} (GeV)",pset.isContinuous)
,("LightLeptonEta[0]",14,-3.5,3.5,"1st Lepton #eta",pset.isContinuous)
,("LightLeptonEta[1]",14,-3.5,3.5,"2nd Lepton #eta",pset.isContinuous)
,("LightLeptonEta[2]",14,-3.5,3.5,"3rd Lepton #eta",pset.isContinuous)
,("LightLeptonEta[3]",14,-3.5,3.5,"4th Lepton #eta",pset.isContinuous)
]


# ---------------------------------------------------------------------------------
#   Local selection settings (these cuts act on the THn defined by pset.variables)
# ---------------------------------------------------------------------------------
pset.localselection=[ #Example line: "parameter1>cut1&&parameter2<cut2&&parameter3==cut3"
# WARNING:: Only use the following (in)equality relations: "<", ">", "=="    (== is for discrete variables only).
# WARNING:: Multiple local selection cuts cannot be applied on the same variable, i.e. MET>50 && MET<100 is dis-allowed! 
#           Instead, define and use an alias such as isMET50to100=(MET>50&&MET<100). See tools/Aliases.py for alias definitions.
# WARNING:: "1" is the no-local-selection case.
"1"
,"L4OSSF1==1"
,"L4OSSF2==1"
]


# ---------------------------------------------------------------------------------
#   May be used to save time if the THn's corresponding to the variables and globalselection already exist
# ---------------------------------------------------------------------------------
pset.usePrecomputedRootFile=False


# ---------------------------------------------------------------------------------
#   Input settings
# ---------------------------------------------------------------------------------
tr      = "rootTupleTreeVeryLoose/tree"      # main analysis tree name
#
pset.lumi=35867. # Luminosity in /pb
# WARNING:: "Data" is a special keyword for process name, everything else is user-defined.
# WARNING:: Xsec, NormFudge/Weight, and RelFlatUnc parameters are dummy values for data. They are **not** applied.
# WARNING:: Input files are defined here: https://twiki.cern.ch/twiki/bin/viewauth/CMS/RutgersMultileptonSampleProcessing
# WARNING:: When self-referencing is used in inputs declaration, Xsec, NormFudge/Weight, and RelFlatUnc. are taken from the parent "bundle".
#
pset.inputs = [ #Parameters: Name, Xsec (pb), File, NormFudge/Weight, RelFlatUnc., TechnicalSelection, TTreeName
("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016B-03Feb2017_ver2-v2_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016C-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016D-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016E-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016F-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016G-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016H-03Feb2017_ver2-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleElectron/Run2016H-03Feb2017_ver3-v1_MINIAOD/BDTtree.root",1,0,"1",tr)

,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016B-03Feb2017_ver2-v2_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016C-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016D-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016E-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016F-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016G-03Feb2017-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016H-03Feb2017_ver2-v1_MINIAOD/BDTtree.root",1,0,"1",tr)
,("Data",1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/SingleMuon/Run2016H-03Feb2017_ver3-v1_MINIAOD/BDTtree.root",1,0,"1",tr)

,("MisID",1,"Data",1,0,"1",tr)

#,("X+G",5765.4*0.19,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_HCALDebug_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1_MINIAODSIM/BDTtree.root",0.78,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",5765.4,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_ext2/BDTtree.root",0.78,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",18610,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/BDTtree.root",0.78,0,"(LightLeptonNonFakeType4DA==1111)",tr)
#,("X+G",18610*0.39,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1_MINIAODSIM/BDTtree.root",0.78,0,"(LightLeptonNonFakeType4DA==1111)",tr)
#,("X+G",87.31*0.21,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTJets_Dilept_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1_MINIAODSIM/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",87.31,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTJets_Dilept_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8_ext1/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",19.56,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
#,("X+G",19.56*0.38,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1_MINIAODSIM/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",19.56,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
#,("X+G",19.56*0.37,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1_MINIAODSIM/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",12.178,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WWTo2L2Nu_13TeV-powheg/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111*((Event+LS)%2==1))",tr)
,("X+G",0.007868,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WmWmJJ_13TeV-powheg-pythia8_TuneCUETP8M1/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",0.02093,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WpWpJJ_13TeV-powheg-pythia8_TuneCUETP8M1/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",0.1703,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WWTo2L2Nu_DoubleScattering_13TeV-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",5.606,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
#,("X+G",0.564*0.16,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ZZTo2L2Nu_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1_MINIAODSIM/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",0.564,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ZZTo2L2Nu_13TeV_powheg_pythia8_ext1/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("X+G",3.22,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ZZTo2L2Q_13TeV_powheg_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)

,("X+G",4.42965,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8/BDTtree.root",1.07*2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",0.2086,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",0.2043*0.45,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext1/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",0.09418,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/tZq_ll_4f_13TeV-amcatnlo-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("X+G",0.0004812,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTTJ_TuneCUETP8M2T4_13TeV-madgraph-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
    
#,("ZZ",1.256*1.1*0.07,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ZZTo4L_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1_MINIAODSIM/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("ZZ",1.256*1.1,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ZZTo4L_13TeV_powheg_pythia8_ext1/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("ZZ",0.003194*1.7,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluToContinToZZTo2e2mu_13TeV_MCFM701_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ZZ",0.003194*1.7,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluToContinToZZTo2e2tau_13TeV_MCFM701_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ZZ",0.003194*1.7,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluToContinToZZTo2mu2tau_13TeV_MCFM701_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ZZ",0.001586*1.7,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluToContinToZZTo4e_13TeV_MCFM701_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ZZ",0.001586*1.7,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluToContinToZZTo4mu_13TeV_MCFM701_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ZZ",0.001586*1.7,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluToContinToZZTo4tau_13TeV_MCFM701_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)

,("VVV",0.1651,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("VVV",0.05565,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("VVV",0.01398,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.2043*0.55,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext2/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.0493,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTZToLL_M-1to10_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
#,("ttV",0.2529*0.15,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8_ext1/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("ttV",0.2529*0.44/(.44+.41),"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8_ext2/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("ttV",0.2529*0.41/(.44+.41),"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8_ext3/BDTtree.root",1,0,"(LightLeptonNonFakeType4DA==1111)",tr)
,("ttV",0.01103,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ST_tWll_5f_LO_13TeV_MadGraph_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.009103,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTTT_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.0008612,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTTW_TuneCUETP8M2T4_13TeV-madgraph-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.007834,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTWW_TuneCUETP8M2T4_13TeV-madgraph-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.002938,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTWZ_TuneCUETP8M2T4_13TeV-madgraph-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("ttV",0.001563,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/TTZZ_TuneCUETP8M2T4_13TeV-madgraph-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)

,("Higgs",0.2151,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Higgs",0.01212,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Higgs",0.001034,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/VBF_HToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Higgs",0.000324,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/bbH_HToZZTo4L_M125_13TeV_JHUgenV702_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Higgs",0.9561,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)

,("Sigma_{140}",0.4703344788,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0WW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.05127915563,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0WZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.005904311342,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0WH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.5035330036,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0ZW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.08478189001,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0ZZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.007294416902,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0ZH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.03905786602,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0HW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.006908202988,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0HZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.0006156937566,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA0HH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.2769087751,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0WW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.02992507266,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0WZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.003455117085,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0WH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.2955708757,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0ZW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.04952027834,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0ZZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.004300168543,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0ZH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.0229464984,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0HW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.004058349774,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0HZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.0003600996885,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMA-SIGMA0HH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.04550718412,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-WW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.1429040654,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-WZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.0141833623,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-WH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.1433054813,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-ZW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.1342067206,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-ZZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.01146443851,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-ZH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.01414322071,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-HW/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.01142028276,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-HZ/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
,("Sigma_{140}",0.0008508679325,"/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-HH/BDTtree.root",2,0,"(LightLeptonNonFakeType4DA==1111)*((Event+LS)%2==1)",tr)
]


# ---------------------------------------------------------------------------------
#   Dynamic Weight settings - not applied to **Data**
# ---------------------------------------------------------------------------------
pset.commonMCWeights=[ #Weights for PU, lepton SF, etc.
"(LightLeptonTightType4DA==1111)"
,"(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))"
,"(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonEta[3], LightLeptonFlavorType4D[0]))"
,"pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])" 
]
pset.bundleWeights=[ #Weights for nJets, etc.
("Data","(LightLeptonTightType4DA==1111)")
,("MisID","(MatrixMethodWeight4D(LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonJetPt1, LightLeptonJetPt2, LightLeptonJetPt3, HighPurityTrackN, LightLeptonTightFlavorEtaType4DA, standardVersionSmartMM))")
,("ZZ","((1>0)*0.99)")
,("ttV","((1>0)*0.99)")
,("ZZ","((1>0))")
,("X+G","(1>0)*(eventBTagSFDY)")
,("ZZ","(1>0)*(eventBTagSFZZ)")
,("ttV","(1>0)*(eventBTagSFTTZ)")
,("VVV","(1>0)*(eventBTagSFWZ)")
,("Higgs","(1>0)*(eventBTagSFZZ)")
,("Sigma_{140}","(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonEta[3], LightLeptonFlavorType4D[0]))")
]


# ---------------------------------------------------------------------------------
#   Plot settings
# ---------------------------------------------------------------------------------
pset.useCustomXlabels=True
pset.showSelection=True
pset.usePoissonErrorBarsOnData=True # see: https://twiki.cern.ch/twiki/bin/viewauth/CMS/PoissonErrorBars
pset.doRatio=True
pset.doZscore=False #works only when doRatio is enabled.
pset.usePublicationStyle=False
pset.overlayBundles=["Sigma_{140}"]
pset.bundleColors=["Data==1","X+G==435","ZZ==616","VVV==874","ttV==855","Higgs==803","MisID==800"]# applied only if all bundles defined above are accounted for!
#    INFO:: Root colors: (https://root.cern.ch/doc/master/pict1_TColor_002.png)
#              kWhite =0,   kBlack =1,   kGray=920,
#              kRed   =632, kGreen =416, kBlue=600, kYellow=400, kMagenta=616, kCyan=432,
#              kOrange=800, kSpring=820, kTeal=840, kAzure =860, kViolet =880, kPink=900.


# ---------------------------------------------------------------------------------
#   Force-reset event weights to 1 everywhere. **DO NOT USE**
# ---------------------------------------------------------------------------------
pset.useUnityWeights=False


# ---------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------
runPlotter(pset,args)
# ---------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------


print "runPlotter.py END"
# ---------------------------------------------------------------------------------
