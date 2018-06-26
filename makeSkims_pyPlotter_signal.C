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


void makeSkims_pyPlotter_signal(){



	
		//Get input tree and add aliases to it
	TFile *input(0);
	TString fname = "";
	std::string label ="QQQ";   

    fname = "/cms/mchristos/ANN/Seesaw/2016/92X/Signal/140/SeesawTypeIII_QQQ_M-140_13TeV-madgraph/analysisTree.root";  
	input = TFile::Open(fname);
	std::cout << "--- Using input file: " << input->GetName() << std::endl;
	cout<<endl;
	float fileWeight;
	float xsec = VVV;
	TTree *tree = (TTree*)input->Get("rootTupleTreeVeryLoose/tree");
	addAliasedVars(tree);
	TTreeReader myReader(tree);
	TH1I *EventCount= new TH1I();
   	histo = (TH1I*)input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");
	cout<<"--- Entries in tree: "<<tree->GetEntries()<<endl;
	EventCount = (TH1I*)input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");  
    double nevents = EventCount->GetBinContent(1);
    fileWeight = 1;


		//File where final analysis tree will be stored
	TFile *endfile = new TFile("/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Signal/QQQ/analysisTree.root","RECREATE");

	endfile->cd();
   	endfile->mkdir("veryLooseDileptonEventFilter/");
   	endfile->cd();
   	endfile->mkdir("veryLooseDileptonEventFilter/EventCount/");
   	endfile->cd("veryLooseDileptonEventFilter/EventCount/");

   	histo->Write();

   	endfile->cd();

    endfile->mkdir("rootTupleTreeVeryLoose/");
    endfile->cd("rootTupleTreeVeryLoose/");

	TTree *analysisTree = tree->CopyTree("((L4OSSF1||L4OSSF2)&&L4VLL==1&&LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)||((L3AboveZ||L3OnZ||L3BelowZ||L3OSSF0)&&LightLeptonPairDR[0]>0.4&&LightLeptonN[0]==3&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)");
	analysisTree->Write();
	endfile->Close(); 


}