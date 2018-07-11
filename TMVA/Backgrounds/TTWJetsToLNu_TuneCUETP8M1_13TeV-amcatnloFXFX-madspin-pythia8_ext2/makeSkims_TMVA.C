#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

#include "/cms/mchristos/ANN/Seesaw/2016/92X/addAliases.C"
#include "/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/EvalWeights.C"
#include "/cms/mchristos/software/pyPlotter/tools/customFunctions.C"
#include "/cms/mchristos/software/pyPlotter/tools/customFudgeFactors_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/matrixMethod_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/leptonSFs_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/pileupWeights_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/triggerEffScaleFactor_2016.C"

float dataType1Weight(int dataType, int Event, int LS, float LightLeptonTightTypeA, float LightLeptonLT3, float PFMETType1, float LightLeptonEta0, float LightLeptonEta1, float LightLeptonEta2, float LightLeptonEta3, float LightLeptonPt0, float LightLeptonPt1, float LightLeptonPt2, float LightLeptonPt3, int PULightLeptonFlavorType, int LightLeptonFlavorType3D, int LightLeptonFlavorType4D,int GenPileUpInteractionsTrue, int LightLeptonNonFakeTypeA, int LightLeptonN ){
	
	//dataType==1 weights are (Event%2 weight)*(MC weights)
	float weight = 0;

	if(LightLeptonN==3){
		
		weight = (2*((Event+LS)%2==0)*(LightLeptonTightTypeA==111)*(leptonSF3D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,PULightLeptonFlavorType))*(trigEffSF3D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonFlavorType3D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	
	}else if(LightLeptonN==4){
		
		weight = 2*((Event+LS)%2==0)*((LightLeptonTightTypeA==1111)*(leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType))*(trigEffSF4D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonFlavorType4D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	}

	
	return weight;
}
float dataType4Weight(int dataType, int Event, int LS, float LightLeptonTightTypeA, float LightLeptonLT3, float PFMETType1, float LightLeptonEta0, float LightLeptonEta1, float LightLeptonEta2, float LightLeptonEta3, float LightLeptonPt0, float LightLeptonPt1, float LightLeptonPt2, float LightLeptonPt3, int PULightLeptonFlavorType, int LightLeptonFlavorType3D, int LightLeptonFlavorType4D,int GenPileUpInteractionsTrue, int LightLeptonNonFakeTypeA, int LightLeptonN, int JetN ){
	
	float weight = 0;

	if(LightLeptonN==3){
		
		weight = 2*((Event+LS)%2==0)*((LightLeptonTightTypeA==111)*(leptonSF3D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,PULightLeptonFlavorType))*(trigEffSF3D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonFlavorType3D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)))*(jetWeights_WZ_powheg_2016(JetN));
	
	}else if(LightLeptonN==4){
		weight = 2*((Event+LS)%2==0)*((LightLeptonTightTypeA==1111)*(leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType))*(trigEffSF4D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonFlavorType4D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	}

	
	return weight;
}
float dataType5Weight(int dataType, int Event, int LS, float LightLeptonTightTypeA, float LightLeptonLT3, float PFMETType1, float LightLeptonEta0, float LightLeptonEta1, float LightLeptonEta2, float LightLeptonEta3, float LightLeptonPt0, float LightLeptonPt1, float LightLeptonPt2, float LightLeptonPt3, int PULightLeptonFlavorType, int LightLeptonFlavorType3D, int LightLeptonFlavorType4D,int GenPileUpInteractionsTrue, int LightLeptonNonFakeTypeA, int LightLeptonN){
	
	float weight = 0;

	if(LightLeptonN==3){
		
		weight = ((LightLeptonTightTypeA==111)*(leptonSF3D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,PULightLeptonFlavorType))*(trigEffSF3D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonFlavorType3D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue))*(LightLeptonNonFakeTypeA<111));
	
	}else if(LightLeptonN==4){
		weight = ((LightLeptonTightTypeA==1111)*(leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType))*(trigEffSF4D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonFlavorType4D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	}

	
	return weight;
}
float dataType6Weight(int dataType, int Event, int LS, float LightLeptonTightTypeA, float LightLeptonLT3, float PFMETType1, float LightLeptonEta0, float LightLeptonEta1, float LightLeptonEta2, float LightLeptonEta3, float LightLeptonPt0, float LightLeptonPt1, float LightLeptonPt2, float LightLeptonPt3, int PULightLeptonFlavorType, int LightLeptonFlavorType3D, int LightLeptonFlavorType4D,int GenPileUpInteractionsTrue, int LightLeptonNonFakeTypeA, int LightLeptonN){
	
	float weight = 0;

	if(LightLeptonN==3){
		
		weight = ((LightLeptonTightTypeA==111)*(leptonSF3D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,PULightLeptonFlavorType))*(trigEffSF3D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonFlavorType3D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	
	}else if(LightLeptonN==4){
		weight = ((LightLeptonTightTypeA==1111)*(leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType))*(trigEffSF4D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonFlavorType4D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	}

	
	return weight;
}
float dataType7Weight(int dataType, int Event, int LS, float LightLeptonTightTypeA, float LightLeptonLT3, float PFMETType1, float LightLeptonEta0, float LightLeptonEta1, float LightLeptonEta2, float LightLeptonEta3, float LightLeptonPt0, float LightLeptonPt1, float LightLeptonPt2, float LightLeptonPt3, int PULightLeptonFlavorType, int LightLeptonFlavorType3D, int LightLeptonFlavorType4D,int GenPileUpInteractionsTrue, int LightLeptonNonFakeTypeA, int LightLeptonN){
	
	float weight = 0;

	if(LightLeptonN==3){
		
		weight = ((LightLeptonTightTypeA==111)*(leptonSF3D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,PULightLeptonFlavorType))*(trigEffSF3D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonFlavorType3D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	
	}else if(LightLeptonN==4){
		weight = ((LightLeptonTightTypeA==1111)*(leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType))*(trigEffSF4D(LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonFlavorType4D))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue)));
	}

	if(LightLeptonN==4&&leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType)>0){
		cout<<(leptonSF4D(LightLeptonPt0,LightLeptonEta0,LightLeptonPt1,LightLeptonEta1,LightLeptonPt2,LightLeptonEta2,LightLeptonPt3,LightLeptonEta3,PULightLeptonFlavorType))<<endl;
	}
	return weight;
}
void makeSkims_TMVA(){
	int nleptons = 3;
		//All of the variables we need to calculate the weights
	float PFMETType1, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonLT3;
	double dataType;
	float LightLeptonMass, LightLeptonBestMOSSF, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3;
	float LightLeptonMinMOSSF, LightLeptonMinMSSSF, ElectronDRHltEle27WPTightGsfv, ElectronPt;
	float MuonDRHltIsoMu24OrTkMu24v, MuonPt;
	float LightLeptonDiMassOSSF0, LightLeptonDiMassOSSF1, LightLeptonDiMassOSSF2, LightLeptonDiMassOSSF3;
	float LightLeptonDiMassOSSF4, LightLeptonDiMassOSSF5;
	float LightLeptonMatchedPromptGenLeptonDr0, LightLeptonMatchedPromptGenLeptonDr1, LightLeptonMatchedPromptGenLeptonDr2;
	float LightLeptonMatchedPromptGenLeptonDr3;
	float LightLeptonMatchedPromptGenPhotonDr0, LightLeptonMatchedPromptGenPhotonDr1, LightLeptonMatchedPromptGenPhotonDr2;
	float LightLeptonMatchedPromptGenPhotonDr3;
	int LightLeptonN, MuonN, ElectronN , HLTIsoMu24vAccept, HLTIsoTkMu24vAccept;
	int LightLeptonFlavor0, LightLeptonFlavor1, LightLeptonFlavor2, LightLeptonFlavor3, SampleType, HLTEle27WPTightGsfvAccept;
	int ElectronIsTight0, ElectronIsTight1, ElectronIsTight2, ElectronIsTight3;
	int MuonIsTight0,MuonIsTight1,MuonIsTight2,MuonIsTight3, LightLeptonNativeIndex0, LightLeptonNativeIndex1;
	int LightLeptonNativeIndex2, LightLeptonNativeIndex3;
	int RecoVertexN, LightLeptonFlavorType4D, LightLeptonFlavorType3D, LightLeptonNOSSF, GenPileUpInteractionsTrue, JetN;
	unsigned LS, Event;

	
		//Get input tree and add aliases to it
	TFile *input(0);
	TString fname = "";
	std::string label ="TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext2";   

	if( (label.find("TTJets_Dilept") != std::string::npos) || (label.find("DYJets") != std::string::npos) ){
        fname = "/cms/mchristos/ANN/Seesaw/2016/92X/MC_TTbarDY/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext2/analysisTree.root";   

      }else{
        fname = "/cms/mchristos/ANN/Seesaw/2016/92X/MC_notTTbarDY/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext2/analysisTree.root";   
     }

	input = TFile::Open(fname);
	std::cout << "--- Using input file: " << input->GetName() << std::endl;
	cout<<endl;
	float fileWeight;
	float xsec = 0.2043*.55;
	TTree *tree = (TTree*)input->Get("rootTupleTreeVeryLoose/tree");
	addAliasedVars(tree);
	TTreeReader myReader(tree);
	TH1I *histo= new TH1I();
   	histo = (TH1I*)input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");
	cout<<"--- Entries in tree: "<<tree->GetEntries()<<endl;
	EventCount = (TH1I*)input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");  
    double nevents = EventCount->GetBinContent(1);
    fileWeight = xsec/nevents;
    


		//Turn off all branches and then activate only the ones we want either for analysis or weights
	tree->SetBranchStatus("*",0);
	tree->SetBranchStatus("LightLeptonLT3",1);
	tree->SetBranchStatus("PFMETType1",1);
	tree->SetBranchStatus("LightLeptonPt",1);
	tree->SetBranchStatus("LightLeptonMT3",1);
	tree->SetBranchStatus("LightLeptonEta",1);
	tree->SetBranchStatus("LightLeptonMass",1);
	tree->SetBranchStatus("JetCombinedInclusiveSecondaryVertexV2BJetTags",1);
	tree->SetBranchStatus("JetEta",1);
	tree->SetBranchStatus("LightLeptonLeptonDRmin",1);
	tree->SetBranchStatus("LightLeptonBestMOSSF",1);
	tree->SetBranchStatus("JetPt",1);
	tree->SetBranchStatus("LightLeptonBestMSSSF",1);
	tree->SetBranchStatus("LightLeptonPairPt",1);
	tree->SetBranchStatus("LightLeptonPairDR",1);
	tree->SetBranchStatus("LightLeptonCharge",1);
	tree->SetBranchStatus("LightLeptonN",1);
	tree->SetBranchStatus("MuonN",1);
	tree->SetBranchStatus("ElectronN",1);
	tree->SetBranchStatus("LightLeptonIsTight",1);
	tree->SetBranchStatus("LightLeptonOnZN",1);
	tree->SetBranchStatus("LightLeptonPhi",1);
	tree->SetBranchStatus("HLTIsoMu24vAccept",1);
	tree->SetBranchStatus("HLTIsoTkMu24vAccept",1);
	tree->SetBranchStatus("LightLeptonFlavor",1);
	tree->SetBranchStatus("SampleType",1);
	tree->SetBranchStatus("HLTEle27WPTightGsfvAccept",1);
	tree->SetBranchStatus("LightLeptonMinMOSSF",1);
	tree->SetBranchStatus("LightLeptonMinMSSSF",1);
	tree->SetBranchStatus("ElectronDRHltEle27WPTightGsfv",1);
	tree->SetBranchStatus("ElectronIsTight",1);
	tree->SetBranchStatus("ElectronPt",1);
	tree->SetBranchStatus("MuonDRHltIsoMu24OrTkMu24v",1);
	tree->SetBranchStatus("MuonIsTight",1);
	tree->SetBranchStatus("MuonPt",1);
	tree->SetBranchStatus("LightLeptonNOSSF",1);
	tree->SetBranchStatus("LightLeptonDiMassOSSF",1);
	tree->SetBranchStatus("LightLeptonNativeIndex",1);
	tree->SetBranchStatus("RecoVertexN",1);
	tree->SetBranchStatus("LightLeptonFlavorType4D",1);
	tree->SetBranchStatus("LightLeptonMatchedPromptGenLeptonDr",1);
	tree->SetBranchStatus("LightLeptonMatchedPromptGenPhotonDr",1);
	tree->SetBranchStatus("LightLeptonFlavorType3D",1);
	tree->SetBranchStatus("LS",1);
	tree->SetBranchStatus("Event",1);
	tree->SetBranchStatus("dataType",1);
	tree->SetBranchStatus("GenPileUpInteractionsTrue",1);
	tree->SetBranchStatus("JetN",1);
	tree->SetBranchStatus("LightLeptonElectronNOSSF",1);
	tree->SetBranchStatus("LightLeptonMuonNOSSF",1);
	tree->SetBranchStatus("MuonDXY",1);
	tree->SetBranchStatus("ElectronDXY",1);



		//File where final analysis tree will be stored
	TFile *endfile;
	if(nleptons==4){
		endfile = new TFile("/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext2/shortTree_4L.root","RECREATE");
	}
	else if(nleptons==3){
		endfile = new TFile("/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_ext2/shortTree_3L.root","RECREATE");
	}

		//Clone tree shortTree from original tree which will have only activated branches. Add weight branch to store by-event weights
	TTree *shortTree = tree->CloneTree(0);
	std::vector<double> *weight = new std::vector<double>(0);
	shortTree->Branch("Weight",&weight);


	TTreeReaderValue<vector<Float_t>> inPFMETType1(myReader, "PFMETType1");
	TTreeReaderValue<vector<Float_t>> inLightLeptonPt(myReader, "LightLeptonPt");
	TTreeReaderValue<vector<Float_t>> inLightLeptonMass(myReader, "LightLeptonMass");
	TTreeReaderValue<vector<Float_t>> inLightLeptonBestMOSSF(myReader, "LightLeptonBestMOSSF");
	TTreeReaderValue<vector<Int_t>> inLightLeptonN(myReader, "LightLeptonN");
	TTreeReaderValue<vector<Int_t>> inMuonN(myReader, "MuonN");
	TTreeReaderValue<vector<Int_t>> inElectronN(myReader, "ElectronN");
	TTreeReaderValue<vector<Int_t>> inHLTIsoMu24vAccept(myReader, "HLTIsoMu24vAccept");
	TTreeReaderValue<vector<Int_t>> inHLTIsoTkMu24vAccept(myReader, "HLTIsoTkMu24vAccept");
	TTreeReaderValue<vector<Int_t>> inLightLeptonFlavor(myReader, "LightLeptonFlavor");
	TTreeReaderValue<vector<Int_t>> inSampleType(myReader, "SampleType");
	TTreeReaderValue<vector<Int_t>> inHLTEle27WPTightGsfvAccept(myReader, "HLTEle27WPTightGsfvAccept");
	TTreeReaderValue<vector<Float_t>> inLightLeptonMinMOSSF(myReader, "LightLeptonMinMOSSF");
	TTreeReaderValue<vector<Float_t>> inLightLeptonMinMSSSF(myReader, "LightLeptonMinMSSSF");
	TTreeReaderValue<vector<Float_t>> inElectronDRHltEle27WPTightGsfv(myReader, "ElectronDRHltEle27WPTightGsfv");
	TTreeReaderValue<vector<Int_t>> inElectronIsTight(myReader, "ElectronIsTight");
	TTreeReaderValue<vector<Float_t>> inElectronPt(myReader, "ElectronPt");
	TTreeReaderValue<vector<Float_t>> inMuonDRHltIsoMu24OrTkMu24v(myReader, "MuonDRHltIsoMu24OrTkMu24v");
	TTreeReaderValue<vector<Int_t>> inMuonIsTight(myReader, "MuonIsTight");
	TTreeReaderValue<vector<Float_t>> inMuonPt(myReader, "MuonPt");
	TTreeReaderValue<vector<Int_t>> inLightLeptonNOSSF(myReader, "LightLeptonNOSSF");
	TTreeReaderValue<vector<Float_t>> inLightLeptonDiMassOSSF(myReader, "LightLeptonDiMassOSSF");
	TTreeReaderValue<vector<Int_t>> inLightLeptonNativeIndex(myReader, "LightLeptonNativeIndex");
	TTreeReaderValue<vector<Int_t>> inRecoVertexN(myReader, "RecoVertexN");
	TTreeReaderValue<vector<Int_t>> inLightLeptonFlavorType4D(myReader, "LightLeptonFlavorType4D");
	TTreeReaderValue<vector<Float_t>> inLightLeptonMatchedPromptGenLeptonDr(myReader, "LightLeptonMatchedPromptGenLeptonDr");
	TTreeReaderValue<vector<Float_t>> inLightLeptonMatchedPromptGenPhotonDr(myReader, "LightLeptonMatchedPromptGenPhotonDr");
	TTreeReaderValue<vector<Int_t>> inLightLeptonFlavorType3D(myReader, "LightLeptonFlavorType3D");
	TTreeReaderValue<vector<unsigned>> inLS(myReader, "LS");
	TTreeReaderValue<vector<unsigned>> inEvent(myReader, "Event");
	TTreeReaderValue<vector<Double_t>> indataType(myReader, "dataType");
	TTreeReaderValue<vector<Float_t>> inLightLeptonLT3(myReader, "LightLeptonLT3");
	TTreeReaderValue<vector<Float_t>> inLightLeptonEta(myReader, "LightLeptonEta");
	TTreeReaderValue<vector<Float_t>> inGenPileUpInteractionsTrue(myReader, "GenPileUpInteractionsTrue");
	TTreeReaderValue<vector<Int_t>> inJetN(myReader, "JetN");



		//Begin loop over tree
	int count = 0;
	float sum_of_weights = 0;
	int countcheck = 0;
	std::cout << "--- Processing: " << tree->GetEntries() << " events" << std::endl;

	while (myReader.Next()) {

		tree->GetEntry(count);
		if (count%1000 == 0) std::cout << "--- ... Processing event: " << count << std::endl;



		if(inPFMETType1->empty()){
			PFMETType1 = 0;
		}else{
			PFMETType1 = inPFMETType1->at(0);
		}

		if(inLightLeptonMass->empty()){
			LightLeptonMass = 0;
		}else{
			LightLeptonMass = inLightLeptonMass->at(0);
		}

		if(inLightLeptonBestMOSSF->empty()){
			LightLeptonBestMOSSF = 0;
		}else{
			LightLeptonBestMOSSF = inLightLeptonBestMOSSF->at(0);
		}

		if(inLightLeptonN->empty()){
			LightLeptonN = 0;
		}else{
			LightLeptonN = inLightLeptonN->at(0);
		}


		if(inMuonN->empty()){
			MuonN = 0;
		}else{
			MuonN = inMuonN->at(0);
		}

		if(inElectronN->empty()){
			ElectronN = 0;
		}else{
			ElectronN = inElectronN->at(0);
		}

		if(inHLTIsoMu24vAccept->empty()){
			HLTIsoMu24vAccept = 0;
		}else{
			HLTIsoMu24vAccept = inHLTIsoMu24vAccept->at(0);
		}

		if(inHLTIsoTkMu24vAccept->empty()){
			HLTIsoTkMu24vAccept = 0;
		}else{
			HLTIsoTkMu24vAccept = inHLTIsoTkMu24vAccept->at(0);
		}

		if(inLightLeptonMinMOSSF->empty()){
			LightLeptonMinMOSSF = 0;
		}else{
			LightLeptonMinMOSSF = inLightLeptonMinMOSSF->at(0);
		}

		if(inLightLeptonMinMSSSF->empty()){
			LightLeptonMinMSSSF = 0;
		}else{
			LightLeptonMinMSSSF = inLightLeptonMinMSSSF->at(0);
		}

		if(inElectronDRHltEle27WPTightGsfv->empty()){
			ElectronDRHltEle27WPTightGsfv = 0;
		}else{
			ElectronDRHltEle27WPTightGsfv = inElectronDRHltEle27WPTightGsfv->at(0);
		}

		if(inElectronPt->empty()){
			ElectronPt = 0;
		}else{
			ElectronPt = inElectronPt->at(0);
		}

		if(inMuonDRHltIsoMu24OrTkMu24v->empty()){
			MuonDRHltIsoMu24OrTkMu24v = 0;
		}else{
			MuonDRHltIsoMu24OrTkMu24v = inMuonDRHltIsoMu24OrTkMu24v->at(0);
		}

		if(inMuonPt->empty()){
			MuonPt = 0;
		}else{
			MuonPt = inMuonPt->at(0);
		}


		if(inSampleType->empty()){
			SampleType = 0;
		}else{
			SampleType = inSampleType->at(0);
		}

		if(inHLTEle27WPTightGsfvAccept->empty()){
			HLTEle27WPTightGsfvAccept = 0;
		}else{
			HLTEle27WPTightGsfvAccept = inHLTEle27WPTightGsfvAccept->at(0);
		}

		if(inRecoVertexN->empty()){
			RecoVertexN = 0;
		}else{
			RecoVertexN = inRecoVertexN->at(0);
		}

		if(inLightLeptonFlavorType4D->empty()){
			LightLeptonFlavorType4D = 0;
		}else{
			LightLeptonFlavorType4D = inLightLeptonFlavorType4D->at(0);
		}

		if(inLightLeptonFlavorType3D->empty()){
			LightLeptonFlavorType3D = 0;
		}else{
			LightLeptonFlavorType3D = inLightLeptonFlavorType3D->at(0);
		}

		if(inLightLeptonNOSSF->empty()){
			LightLeptonNOSSF = 0;
		}else{
			LightLeptonNOSSF = inLightLeptonNOSSF->at(0);
		}

		if(inLS->empty()){
			LS = 0;
		}else{
			LS = inLS->at(0);
		}

		if(inEvent->empty()){
			Event = 0;
		}else{
			Event = inEvent->at(0);
		}

		if(indataType->empty()){
			dataType = 0;
		}else{
			dataType = indataType->at(0);
		}

		if(inLightLeptonLT3->empty()){
			LightLeptonLT3 = 0;
		}else{
			LightLeptonLT3 = inLightLeptonLT3->at(0);
		}

		if(inGenPileUpInteractionsTrue->empty()){
			GenPileUpInteractionsTrue = 0;
		}else{
			GenPileUpInteractionsTrue = inGenPileUpInteractionsTrue->at(0);
		}

		if(inJetN->empty()){
			JetN = 0;
		}else{
			JetN = inJetN->at(0);
		}

		if(inLightLeptonPt->size()>=4){
			LightLeptonPt0 = inLightLeptonPt->at(0);
			LightLeptonPt1 = inLightLeptonPt->at(1);
			LightLeptonPt2 = inLightLeptonPt->at(2);
			LightLeptonPt3 = inLightLeptonPt->at(3);
		}else if(inLightLeptonPt->size()==3){
			LightLeptonPt0 = inLightLeptonPt->at(0);
			LightLeptonPt1 = inLightLeptonPt->at(1);
			LightLeptonPt2 = inLightLeptonPt->at(2);
			LightLeptonPt3 = 0;
		}else if(inLightLeptonPt->size()==2){
			LightLeptonPt0 = inLightLeptonPt->at(0);
			LightLeptonPt1 = inLightLeptonPt->at(1);
			LightLeptonPt2 = 0;
			LightLeptonPt3 = 0;
		}else if(inLightLeptonPt->size()==1){
			LightLeptonPt0 = inLightLeptonPt->at(0);
			LightLeptonPt1 = 0;
			LightLeptonPt2 = 0;
			LightLeptonPt3 = 0;
		}else{
			LightLeptonPt0 = 0;
			LightLeptonPt1 = 0;
			LightLeptonPt2 = 0;
			LightLeptonPt3 = 0;
		}

		if(inLightLeptonEta->size()>=4){
			LightLeptonEta0 = inLightLeptonEta->at(0);
			LightLeptonEta1 = inLightLeptonEta->at(1);
			LightLeptonEta2 = inLightLeptonEta->at(2);
			LightLeptonEta3 = inLightLeptonEta->at(3);
		}else if(inLightLeptonEta->size()==3){
			LightLeptonEta0 = inLightLeptonEta->at(0);
			LightLeptonEta1 = inLightLeptonEta->at(1);
			LightLeptonEta2 = inLightLeptonEta->at(2);
			LightLeptonEta3 = 0;
		}else if(inLightLeptonEta->size()==2){
			LightLeptonEta0 = inLightLeptonEta->at(0);
			LightLeptonEta1 = inLightLeptonEta->at(1);
			LightLeptonEta2 = 0;
			LightLeptonEta3 = 0;
		}else if(inLightLeptonEta->size()==1){
			LightLeptonEta0 = inLightLeptonEta->at(0);
			LightLeptonEta1 = 0;
			LightLeptonEta2 = 0;
			LightLeptonEta3 = 0;
		}else{
			LightLeptonEta0 = 0;
			LightLeptonEta1 = 0;
			LightLeptonEta2 = 0;
			LightLeptonEta3 = 0;
		}

		if(inMuonIsTight->size()>=4){
			MuonIsTight0 = inMuonIsTight->at(0);
			MuonIsTight1 = inMuonIsTight->at(1);
			MuonIsTight2 = inMuonIsTight->at(2);
			MuonIsTight3 = inMuonIsTight->at(3);
		}else if(inMuonIsTight->size()==3){
			MuonIsTight0 = inMuonIsTight->at(0);
			MuonIsTight1 = inMuonIsTight->at(1);
			MuonIsTight2 = inMuonIsTight->at(2);
			MuonIsTight3 = 0;
		}else if(inMuonIsTight->size()==2){
			MuonIsTight0 = inMuonIsTight->at(0);
			MuonIsTight1 = inMuonIsTight->at(1);
			MuonIsTight2 = 0;
			MuonIsTight3 = 0;
		}else if(inMuonIsTight->size()==1){
			MuonIsTight0 = inMuonIsTight->at(0);
			MuonIsTight1 = 0;
			MuonIsTight2 = 0;
			MuonIsTight3 = 0;
		}else{
			MuonIsTight0 = 0;
			MuonIsTight1 = 0;
			MuonIsTight2 = 0;
			MuonIsTight3 = 0;
		}

		if(inElectronIsTight->size()>=4){
			ElectronIsTight0 = inElectronIsTight->at(0);
			ElectronIsTight1 = inElectronIsTight->at(1);
			ElectronIsTight2 = inElectronIsTight->at(2);
			ElectronIsTight3 = inElectronIsTight->at(3);
		}else if(inElectronIsTight->size()==3){
			ElectronIsTight0 = inElectronIsTight->at(0);
			ElectronIsTight1 = inElectronIsTight->at(1);
			ElectronIsTight2 = inElectronIsTight->at(2);
			ElectronIsTight3 = 0;
		}else if(inElectronIsTight->size()==2){
			ElectronIsTight0 = inElectronIsTight->at(0);
			ElectronIsTight1 = inElectronIsTight->at(1);
			ElectronIsTight2 = 0;
			ElectronIsTight3 = 0;
		}else if(inElectronIsTight->size()==1){
			ElectronIsTight0 = inElectronIsTight->at(0);
			ElectronIsTight1 = 0;
			ElectronIsTight2 = 0;
			ElectronIsTight3 = 0;
		}else{
			ElectronIsTight0 = 0;
			ElectronIsTight1 = 0;
			ElectronIsTight2 = 0;
			ElectronIsTight3 = 0;
		}


		if(inLightLeptonDiMassOSSF->size()>=6){
			LightLeptonDiMassOSSF0 = inLightLeptonDiMassOSSF->at(0);
			LightLeptonDiMassOSSF1 = inLightLeptonDiMassOSSF->at(1);
			LightLeptonDiMassOSSF2 = inLightLeptonDiMassOSSF->at(2);
			LightLeptonDiMassOSSF3 = inLightLeptonDiMassOSSF->at(3);
			LightLeptonDiMassOSSF4 = inLightLeptonDiMassOSSF->at(4);
			LightLeptonDiMassOSSF5 = inLightLeptonDiMassOSSF->at(5);
		}else if(inLightLeptonDiMassOSSF->size()==5){
			LightLeptonDiMassOSSF0 = inLightLeptonDiMassOSSF->at(0);
			LightLeptonDiMassOSSF1 = inLightLeptonDiMassOSSF->at(1);
			LightLeptonDiMassOSSF2 = inLightLeptonDiMassOSSF->at(2);
			LightLeptonDiMassOSSF3 = inLightLeptonDiMassOSSF->at(3);
			LightLeptonDiMassOSSF4 = inLightLeptonDiMassOSSF->at(4);
			LightLeptonDiMassOSSF5 = 0;
		}else if(inLightLeptonDiMassOSSF->size()==4){
			LightLeptonDiMassOSSF0 = inLightLeptonDiMassOSSF->at(0);
			LightLeptonDiMassOSSF1 = inLightLeptonDiMassOSSF->at(1);
			LightLeptonDiMassOSSF2 = inLightLeptonDiMassOSSF->at(2);
			LightLeptonDiMassOSSF3 = inLightLeptonDiMassOSSF->at(3);
			LightLeptonDiMassOSSF4 = 0;
			LightLeptonDiMassOSSF5 = 0;
		}else if(inLightLeptonDiMassOSSF->size()==3){
			LightLeptonDiMassOSSF0 = inLightLeptonDiMassOSSF->at(0);
			LightLeptonDiMassOSSF1 = inLightLeptonDiMassOSSF->at(1);
			LightLeptonDiMassOSSF2 = inLightLeptonDiMassOSSF->at(2);
			LightLeptonDiMassOSSF3 = 0;
			LightLeptonDiMassOSSF4 = 0;
			LightLeptonDiMassOSSF5 = 0;
		}else if(inLightLeptonDiMassOSSF->size()==2){
			LightLeptonDiMassOSSF0 = inLightLeptonDiMassOSSF->at(0);
			LightLeptonDiMassOSSF1 = inLightLeptonDiMassOSSF->at(1);
			LightLeptonDiMassOSSF2 = 0;
			LightLeptonDiMassOSSF3 = 0;
			LightLeptonDiMassOSSF4 = 0;
			LightLeptonDiMassOSSF5 = 0;
		}else if(inLightLeptonDiMassOSSF->size()==1){
			LightLeptonDiMassOSSF0 = inLightLeptonDiMassOSSF->at(0);
			LightLeptonDiMassOSSF1 = 0;
			LightLeptonDiMassOSSF2 = 0;
			LightLeptonDiMassOSSF3 = 0;
			LightLeptonDiMassOSSF4 = 0;
			LightLeptonDiMassOSSF5 = 0;
		}else{
			LightLeptonDiMassOSSF0 = 0;
			LightLeptonDiMassOSSF1 = 0;
			LightLeptonDiMassOSSF2 = 0;
			LightLeptonDiMassOSSF3 = 0;
			LightLeptonDiMassOSSF4 = 0;
			LightLeptonDiMassOSSF5 = 0;
		}

		if(inLightLeptonMatchedPromptGenLeptonDr->size()>=4){
			LightLeptonMatchedPromptGenLeptonDr0 = inLightLeptonMatchedPromptGenLeptonDr->at(0);
			LightLeptonMatchedPromptGenLeptonDr1 = inLightLeptonMatchedPromptGenLeptonDr->at(1);
			LightLeptonMatchedPromptGenLeptonDr2 = inLightLeptonMatchedPromptGenLeptonDr->at(2);
			LightLeptonMatchedPromptGenLeptonDr3 = inLightLeptonMatchedPromptGenLeptonDr->at(3);
		}else if(inLightLeptonMatchedPromptGenLeptonDr->size()==3){
			LightLeptonMatchedPromptGenLeptonDr0 = inLightLeptonMatchedPromptGenLeptonDr->at(0);
			LightLeptonMatchedPromptGenLeptonDr1 = inLightLeptonMatchedPromptGenLeptonDr->at(1);
			LightLeptonMatchedPromptGenLeptonDr2 = inLightLeptonMatchedPromptGenLeptonDr->at(2);
			LightLeptonMatchedPromptGenLeptonDr3 = 999;
		}else if(inLightLeptonMatchedPromptGenLeptonDr->size()==2){
			LightLeptonMatchedPromptGenLeptonDr0 = inLightLeptonMatchedPromptGenLeptonDr->at(0);
			LightLeptonMatchedPromptGenLeptonDr1 = inLightLeptonMatchedPromptGenLeptonDr->at(1);
			LightLeptonMatchedPromptGenLeptonDr2 = 999;
			LightLeptonMatchedPromptGenLeptonDr3 = 999;
		}else if(inLightLeptonMatchedPromptGenLeptonDr->size()==1){
			LightLeptonMatchedPromptGenLeptonDr0 = inLightLeptonMatchedPromptGenLeptonDr->at(0);
			LightLeptonMatchedPromptGenLeptonDr1 = 999;
			LightLeptonMatchedPromptGenLeptonDr2 = 999;
			LightLeptonMatchedPromptGenLeptonDr3 = 999;
		}else{
			LightLeptonMatchedPromptGenLeptonDr0 = 999;
			LightLeptonMatchedPromptGenLeptonDr1 = 999;
			LightLeptonMatchedPromptGenLeptonDr2 = 999;
			LightLeptonMatchedPromptGenLeptonDr3 = 999;
		}

		if(inLightLeptonMatchedPromptGenPhotonDr->size()>=4){
			LightLeptonMatchedPromptGenPhotonDr0 = inLightLeptonMatchedPromptGenPhotonDr->at(0);
			LightLeptonMatchedPromptGenPhotonDr1 = inLightLeptonMatchedPromptGenPhotonDr->at(1);
			LightLeptonMatchedPromptGenPhotonDr2 = inLightLeptonMatchedPromptGenPhotonDr->at(2);
			LightLeptonMatchedPromptGenPhotonDr3 = inLightLeptonMatchedPromptGenPhotonDr->at(3);
		}else if(inLightLeptonMatchedPromptGenPhotonDr->size()==3){
			LightLeptonMatchedPromptGenPhotonDr0 = inLightLeptonMatchedPromptGenPhotonDr->at(0);
			LightLeptonMatchedPromptGenPhotonDr1 = inLightLeptonMatchedPromptGenPhotonDr->at(1);
			LightLeptonMatchedPromptGenPhotonDr2 = inLightLeptonMatchedPromptGenPhotonDr->at(2);
			LightLeptonMatchedPromptGenPhotonDr3 = 999;
		}else if(inLightLeptonMatchedPromptGenPhotonDr->size()==2){
			LightLeptonMatchedPromptGenPhotonDr0 = inLightLeptonMatchedPromptGenPhotonDr->at(0);
			LightLeptonMatchedPromptGenPhotonDr1 = inLightLeptonMatchedPromptGenPhotonDr->at(1);
			LightLeptonMatchedPromptGenPhotonDr2 = 999;
			LightLeptonMatchedPromptGenPhotonDr3 = 999;
		}else if(inLightLeptonMatchedPromptGenPhotonDr->size()==1){
			LightLeptonMatchedPromptGenPhotonDr0 = inLightLeptonMatchedPromptGenPhotonDr->at(0);
			LightLeptonMatchedPromptGenPhotonDr1 = 999;
			LightLeptonMatchedPromptGenPhotonDr2 = 999;
			LightLeptonMatchedPromptGenPhotonDr3 = 999;
		}else{
			LightLeptonMatchedPromptGenPhotonDr0 = 999;
			LightLeptonMatchedPromptGenPhotonDr1 = 999;
			LightLeptonMatchedPromptGenPhotonDr2 = 999;
			LightLeptonMatchedPromptGenPhotonDr3 = 999;
		}

		if(inLightLeptonFlavor->size()>=4){
			LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
			LightLeptonFlavor1 = inLightLeptonFlavor->at(1);
			LightLeptonFlavor2 = inLightLeptonFlavor->at(2);
			LightLeptonFlavor3 = inLightLeptonFlavor->at(3);
		}else if(inLightLeptonFlavor->size()==3){
			LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
			LightLeptonFlavor1 = inLightLeptonFlavor->at(1);
			LightLeptonFlavor2 = inLightLeptonFlavor->at(2);
			LightLeptonFlavor3 = 0;
		}else if(inLightLeptonFlavor->size()==2){
			LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
			LightLeptonFlavor1 = inLightLeptonFlavor->at(1);
			LightLeptonFlavor2 = 0;
			LightLeptonFlavor3 = 0;
		}else if(inLightLeptonFlavor->size()==1){
			LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
			LightLeptonFlavor1 = 0;
			LightLeptonFlavor2 = 0;
			LightLeptonFlavor3 = 0;
		}else{
			LightLeptonFlavor0 = 0;
			LightLeptonFlavor1 = 0;
			LightLeptonFlavor2 = 0;
			LightLeptonFlavor3 = 0;
		}

		if(inLightLeptonNativeIndex->size()>=4){
			LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
			LightLeptonNativeIndex1 = inLightLeptonNativeIndex->at(1);
			LightLeptonNativeIndex2 = inLightLeptonNativeIndex->at(2);
			LightLeptonNativeIndex3 = inLightLeptonNativeIndex->at(3);
		}else if(inLightLeptonNativeIndex->size()==3){
			LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
			LightLeptonNativeIndex1 = inLightLeptonNativeIndex->at(1);
			LightLeptonNativeIndex2 = inLightLeptonNativeIndex->at(2);
			LightLeptonNativeIndex3 = 0;
		}else if(inLightLeptonNativeIndex->size()==2){
			LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
			LightLeptonNativeIndex1 = inLightLeptonNativeIndex->at(1);
			LightLeptonNativeIndex2 = 0;
			LightLeptonNativeIndex3 = 0;
		}else if(inLightLeptonNativeIndex->size()==1){
			LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
			LightLeptonNativeIndex1 = 0;
			LightLeptonNativeIndex2 = 0;
			LightLeptonNativeIndex3 = 0;
		}else{
			LightLeptonNativeIndex0 = 0;
			LightLeptonNativeIndex1 = 0;
			LightLeptonNativeIndex2 = 0;
			LightLeptonNativeIndex3 = 0;
		}
		





		//Assign and write weight into shortTree
		float EventWeight;


		int LightLeptonTightTypeA;
		int PULightLeptonFlavorType;
		int LightLeptonNonFakeTypeA;
		if(LightLeptonN==3){
			LightLeptonTightTypeA = makeLightLeptonTightType3DA(inMuonIsTight, inElectronIsTight, LightLeptonFlavor0, LightLeptonFlavor1, LightLeptonFlavor2, LightLeptonNativeIndex0, LightLeptonNativeIndex1, LightLeptonNativeIndex2);
			PULightLeptonFlavorType = makePULightLeptonFlavorType3D(RecoVertexN, LightLeptonFlavorType3D);
			LightLeptonNonFakeTypeA = makeLightLeptonNonFakeType3DA(LightLeptonMatchedPromptGenLeptonDr0, LightLeptonMatchedPromptGenLeptonDr1, LightLeptonMatchedPromptGenLeptonDr2, LightLeptonN, LightLeptonMatchedPromptGenPhotonDr0, LightLeptonMatchedPromptGenPhotonDr1, LightLeptonMatchedPromptGenPhotonDr2);
		}else if(LightLeptonN==4){
			LightLeptonTightTypeA = makeLightLeptonTightType4DA(inMuonIsTight, inElectronIsTight, LightLeptonFlavor0, LightLeptonFlavor1, LightLeptonFlavor2, LightLeptonFlavor3, LightLeptonNativeIndex0, LightLeptonNativeIndex1, LightLeptonNativeIndex2, LightLeptonNativeIndex3);
			PULightLeptonFlavorType = makePULightLeptonFlavorType4D(RecoVertexN, LightLeptonFlavorType4D);
			LightLeptonNonFakeTypeA = makeLightLeptonNonFakeType4DA(LightLeptonMatchedPromptGenLeptonDr0, LightLeptonMatchedPromptGenLeptonDr1, LightLeptonMatchedPromptGenLeptonDr2, LightLeptonMatchedPromptGenLeptonDr3, LightLeptonN, LightLeptonMatchedPromptGenPhotonDr0, LightLeptonMatchedPromptGenPhotonDr1, LightLeptonMatchedPromptGenPhotonDr2, LightLeptonMatchedPromptGenPhotonDr3);
		}
		if(PULightLeptonFlavorType>45&&LightLeptonN==4){
			countcheck++;

		}
		

		if(dataType==1){
			EventWeight = dataType1Weight(dataType, Event, LS, LightLeptonTightTypeA, LightLeptonLT3, PFMETType1, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, PULightLeptonFlavorType, LightLeptonFlavorType3D, LightLeptonFlavorType4D,GenPileUpInteractionsTrue, LightLeptonNonFakeTypeA, LightLeptonN );

		}else if(dataType==4){
			EventWeight = dataType4Weight(dataType, Event, LS, LightLeptonTightTypeA, LightLeptonLT3, PFMETType1, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, PULightLeptonFlavorType, LightLeptonFlavorType3D, LightLeptonFlavorType4D,GenPileUpInteractionsTrue, LightLeptonNonFakeTypeA, LightLeptonN, JetN );

		}else if(dataType==5){
			EventWeight = dataType5Weight(dataType, Event, LS, LightLeptonTightTypeA, LightLeptonLT3, PFMETType1, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, PULightLeptonFlavorType, LightLeptonFlavorType3D, LightLeptonFlavorType4D,GenPileUpInteractionsTrue, LightLeptonNonFakeTypeA, LightLeptonN);
		}else if(dataType==6){
			EventWeight = dataType6Weight(dataType, Event, LS, LightLeptonTightTypeA, LightLeptonLT3, PFMETType1, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, PULightLeptonFlavorType, LightLeptonFlavorType3D, LightLeptonFlavorType4D,GenPileUpInteractionsTrue, LightLeptonNonFakeTypeA, LightLeptonN);
		}else if(dataType==7){
			EventWeight = dataType7Weight(dataType, Event, LS, LightLeptonTightTypeA, LightLeptonLT3, PFMETType1, LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, PULightLeptonFlavorType, LightLeptonFlavorType3D, LightLeptonFlavorType4D,GenPileUpInteractionsTrue, LightLeptonNonFakeTypeA, LightLeptonN);
			
		}

		weight->clear();
		weight->push_back(EventWeight*fileWeight);
		//cout<<EventWeight<<endl;
		shortTree->Fill();
		count++;


	}

	TTree *analysisTree;
	analysisTree = shortTree->CopyTree("(LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0&&L4VLL>0)||((L3AboveZ||L3OnZ||L3BelowZ||L3OSSF0)&&LightLeptonPairDR[0]>0.4&&LightLeptonN[0]==3&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)");
	    //Copy only events in shortTree satisfying SR selections fro and copy them into analysis Tree

	analysisTree->Write();
	endfile->Close(); 
	cout<<countcheck<<endl;

}