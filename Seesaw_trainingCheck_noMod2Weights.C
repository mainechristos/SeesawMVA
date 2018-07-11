#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"


#include "/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/addAliases.C"
#include "/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/EvalWeights.C"
#include "/cms/mchristos/software/pyPlotter/tools/customFunctions.C"
#include "/cms/mchristos/software/pyPlotter/tools/customFudgeFactors_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/matrixMethod_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/leptonSFs_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/pileupWeights_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/triggerEffScaleFactor_2016.C"
#include "/cms/mchristos/software/pyPlotter/tools/bTagSF.C"




void Seesaw_trainingCheck_noMod2Weights( TString myMethodList = "" )
{

   std::string mass = "140";
   int nleptons = 3;
   float lumi = 35867.;
   gStyle->SetOptStat(0);

   TH1D *finalhisto_signal = new TH1D("finalhisto_signal","finalhisto_signal",60,0,600);
   TH1D *finalhisto_wz = new TH1D("finalhisto_wz","finalhisto_wz",60,0,600);
   TH1D *finalhisto_zz = new TH1D("finalhisto_zz","finalhisto_zz",60,0,600);
   TH1D *finalhisto_ttv = new TH1D("finalhisto_ttv","finalhisto_ttv",60,0,600);
   TH1D *finalhisto_xg = new TH1D("finalhisto_xg","finalhisto_xg",60,0,600);
   TH1D *finalhisto_vvv = new TH1D("finalhisto_vvv","finalhisto_vvv",60,0,600);
   TH1D *finalhisto_higgs = new TH1D("finalhisto_higgs","finalhisto_higgs",60,0,600);
   TH1D *finalhisto_misid = new TH1D("finalhisto_higgs","finalhisto_higgs",60,0,600);

   TString backgroundExpression ="";
   TString MisIdExpression = "";
   TString signalExpression = "";


   if(nleptons==4){

      backgroundExpression += "(dataType==1)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA==1111)";

      backgroundExpression += "+(dataType==4)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA==1111)";

      backgroundExpression += "+(dataType==5)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA==1111)";

      backgroundExpression += "+(dataType==6)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA==1111)";

      backgroundExpression += "+(dataType==7)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA==1111)";

      MisIdExpression += "(dataType==1)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA<1111)";

      MisIdExpression += "+(dataType==4)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA<1111)";

      MisIdExpression += "+(dataType==5)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA<1111)";

      MisIdExpression += "+(dataType==6)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA<1111)";

      MisIdExpression += "+(dataType==7)*(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA<1111)";

      signalExpression += "(LightLeptonTightType4DA==1111)*(leptonSF4D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],LightLeptonPt[3],LightLeptonEta[3],PULightLeptonFlavorType4D))*(trigEffSF4D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonPt[3], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2],LightLeptonEta[3], LightLeptonFlavorType4D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType4DA==1111)";

   }if(nleptons==3){
      
      backgroundExpression += "(dataType==1)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA==111)";

      backgroundExpression +="+(dataType==4)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType3DA==111)*(jetWeights_WZ_powheg_2016(JetN[0]))*(LightLeptonNonFakeType3DA==111)";

      //backgroundExpression += "+(dataType==5)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA==111)";

      backgroundExpression +="+(dataType==6)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA==111)";

      backgroundExpression +="+(dataType==7)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA==111)";

      
      MisIdExpression += "(dataType==1)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA<111)";

      MisIdExpression +="+(dataType==4)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType3DA<111)*(jetWeights_WZ_powheg_2016(JetN[0]))*(LightLeptonNonFakeType3DA==111)";

      MisIdExpression +="+(dataType==5)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA<111)";

      MisIdExpression +="+(dataType==6)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA<111)";

      MisIdExpression +="+(dataType==7)*(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*(pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0]))*(LightLeptonNonFakeType3DA<111)";
      signalExpression += "(LightLeptonTightType3DA==111)*(leptonSF3D(LightLeptonPt[0],LightLeptonEta[0],LightLeptonPt[1],LightLeptonEta[1],LightLeptonPt[2],LightLeptonEta[2],PULightLeptonFlavorType3D))*(trigEffSF3D(LightLeptonPt[0], LightLeptonPt[1], LightLeptonPt[2], LightLeptonEta[0], LightLeptonEta[1], LightLeptonEta[2], LightLeptonFlavorType3D[0]))*pileupWeightsOffXsecMinus5(GenPileUpInteractionsTrue[0])*(LightLeptonNonFakeType3DA==111)";

   }

   TCut mycuts = "";
   TCut mycutb = "";
   
   if(nleptons ==4){
      mycuts += "LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0&&L4VLL>0";
      mycutb += "LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0&&L4VLL>0";
   }else if(nleptons ==3){
      mycuts += "((L3AboveZ||L3OnZ||L3BelowZ||L3OSSF0)&&LightLeptonPairDR[0]>0.4&&LightLeptonN[0]==3&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)";
      mycutb += "((L3AboveZ||L3OnZ||L3BelowZ||L3OSSF0)&&LightLeptonPairDR[0]>0.4&&LightLeptonN[0]==3&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)";
   }
   

   double signal_events = 0.0;
   double wz_events = 0.0;
   double zz_events = 0.0;
   double ttv_events= 0.0;
   double xg_events= 0.0;
   double vvv_events=0.0;
   double higgs_events=0.0;
   double misid_events=0.0;

   //////////////////////////
   // Adding signal Trees //
   //////////////////////////

   std::ifstream infileXsecs("/cms/mchristos/ANN/Seesaw/2016/test/xsecfiles/XSEC_140.txt");
   std::string lines;

   std::getline(infileXsecs, lines);    //throws away first line which includes titles

   while (std::getline(infileXsecs, lines)) {    //loops through remaining lines in xsecs file

      std::string process;
      double xsec, br,filter_eff, k_factor;     //variables to store xsec, branching ratio, filter efficiency, and k factor
      
      std::istringstream ss(lines);       //takes each line and converts to string
      ss >> process;
      ss >> xsec;
      ss >> br;
      ss >> filter_eff;
      ss >> k_factor;         //reads process name and other numbers into respective variables



      TH1I *EventCountSignal1= new TH1I();

      std::string in = "/cms/mchristos/ANN/Seesaw/2016/92X/Signal/140/SeesawTypeIII_"+process+"_M-140_13TeV-madgraph/analysisTree.root";
      const char *sig_name = in.c_str();
      TFile *sig_input = TFile::Open( sig_name );     //opens signal file matching process name

      std::cout << "--- Using signal input file: " << sig_input->GetName() <<         std::endl;
      // --- Register the training and test trees
      TTree *signal     = (TTree*)sig_input->Get("rootTupleTreeVeryLoose/tree");     //gets signal tree
      addAliasedVars(signal);
      EventCountSignal1 = (TH1I*)sig_input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");
      double nSignal1 = EventCountSignal1->GetBinContent(1);
      
      cout<<"XSEC      BR          Filter_eff  K Factor"<<endl;
      cout << xsec <<"   "<< br << "    "<<filter_eff<<"   "<< k_factor <<endl;
      Double_t sig_xsec = xsec*br*filter_eff*k_factor;

      Double_t sig_getweight = signal->GetWeight();
      cout <<"Signal Weight: "<<sig_getweight<<endl;


      Double_t signalWeight     = sig_xsec*sig_getweight;      //calculates signal weight

      TH1D *EventsSignal1= new TH1D("EventsSignal1","EventsSignal1",60,0,600);
      signal->Draw("(LightLeptonPt)>>EventsSignal1",mycuts*signalExpression);

      signal_events += EventsSignal1->Integral()*sig_xsec/nSignal1;

      EventsSignal1->Scale(sig_xsec/nSignal1*lumi);
      finalhisto_signal->Add(EventsSignal1);
      

   }

   

   /////////////////////////////
   // Add MC Background Trees //
   /////////////////////////////

   //background weight expression (see key.txt for dataType of different files)

   


   std::string infileb_3L = "backgrounds_TMVA.txt";
   std::string infileb_4L = "backgrounds_TMVA_4L.txt";

   const char *bg_name;
   
   if (nleptons == 4){
      bg_name = infileb_4L.c_str();
   }else if(nleptons ==3){
      bg_name = infileb_3L.c_str();

   }



   std::ifstream infileb (bg_name);

   std::string lineb;
   std::getline(infileb, lineb);    //throws away first line which includes titles

   while (std::getline(infileb, lineb)) {    

      std::string bg;
      std::string bundleName;
      float back_xsec;      
      
      std::istringstream ss(lineb);       
      
      ss >> bg;
      ss >> back_xsec;
      ss >> bundleName;
      std::string in;

      
      // if file is ttbar or dy, it is store in a different directory than all other MCs!
      if( (bg.find("TTJets_Dilept") != std::string::npos) || (bg.find("DYJets") != std::string::npos) ){
         in = "/cms/mchristos/ANN/Seesaw/2016/92X/MC_TTbarDY/"+bg+"/analysisTree.root";
      }else{
         in = "/cms/mchristos/ANN/Seesaw/2016/92X/MC_notTTbarDY/"+bg+"/analysisTree.root";
      }

      const char *back_name = in.c_str();
      TFile *back_input = TFile::Open( back_name ); 
      
      std::cout << "--- Using background input file: " << back_input->GetName() <<         std::endl;
      cout<<"XSEC      Bundle Name"<<endl;
      cout << back_xsec <<"   "<< bundleName <<endl;
      
      //Get ttree and event count histo
      TTree *background = (TTree*)back_input->Get("rootTupleTreeVeryLoose/tree");
      addAliasedVars(background);
      TH1I *EventCount = new TH1I();
      EventCount = (TH1I*)back_input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");
      
      //calculate by-file weight (should include sf/ any constant weights in pyPlotter)
      double n = EventCount->GetBinContent(1);
      Double_t backgroundWeight = back_xsec/n;
      cout<<"BG Weight: "<<backgroundWeight<<endl;
      

      TH1D *backgroundEvents= new TH1D("backgroundEvents","backgroundEvents",60,0,600);
      TH1D *MisIdEvents= new TH1D("MisIdEvents","MisIdEvents",60,0,600);
      
      // All files are written into MisID histo with fakes req.
      background->Draw("(LightLeptonPt)>>backgroundEvents",mycutb*backgroundExpression);
      background->Draw("(LightLeptonPt)>>MisIdEvents",mycutb*MisIdExpression);
      
      


      //check bundle name and add events to appropriate histo
      if(bundleName.find("xg") != std::string::npos){
         xg_events += backgroundEvents->Integral()*backgroundWeight;
         misid_events += MisIdEvents->Integral()*backgroundWeight;
         cout<<"This probably won't work: "<<backgroundEvents->Integral()<<endl;
         backgroundEvents->Scale(backgroundWeight*lumi);
         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_xg->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("wz") != std::string::npos){
         wz_events += backgroundEvents->Integral()*backgroundWeight;
         misid_events += MisIdEvents->Integral()*backgroundWeight;

         backgroundEvents->Scale(backgroundWeight*lumi);
         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_wz->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("zz") != std::string::npos){
         zz_events += backgroundEvents->Integral()*backgroundWeight;
         misid_events += MisIdEvents->Integral()*backgroundWeight;

         backgroundEvents->Scale(backgroundWeight*lumi);
         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_zz->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("vvv") != std::string::npos){
         vvv_events += backgroundEvents->Integral()*backgroundWeight;
         misid_events += MisIdEvents->Integral()*backgroundWeight;

         backgroundEvents->Scale(backgroundWeight*lumi);
         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_vvv->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("ttv") != std::string::npos){
         ttv_events += backgroundEvents->Integral()*backgroundWeight;
         misid_events += MisIdEvents->Integral()*backgroundWeight;

         backgroundEvents->Scale(backgroundWeight*lumi);
         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_ttv->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("higgs") != std::string::npos){
         higgs_events += backgroundEvents->Integral()*backgroundWeight;
         misid_events += MisIdEvents->Integral()*backgroundWeight;

         backgroundEvents->Scale(backgroundWeight*lumi);
         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_higgs->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("dy") != std::string::npos){
         misid_events += MisIdEvents->Integral()*backgroundWeight;
         cout<<"This probably won't work: "<<backgroundEvents->Integral()<<endl;

         MisIdEvents->Scale(backgroundWeight*lumi);

         finalhisto_misid->Add(MisIdEvents);
      }       
   }
   
   cout<<"Signal Events: "<<signal_events<<endl;
   cout<<"WZ Events: "<<wz_events*lumi<<endl;
   cout<<"ZZ Events: "<<zz_events*lumi<<endl;
   cout<<"ttV Events: "<<ttv_events*lumi<<endl;
   cout<<"X+G Events: "<<xg_events*lumi<<endl;
   cout<<"VVV Events: "<<vvv_events*lumi<<endl;
   cout<<"Higgs Events: "<<higgs_events*lumi<<endl;

   //Make stacked histo (for pyPlotter comparison)
   THStack *hstack = new THStack("hstack","Stacked histograms");

   
   finalhisto_xg->SetFillColor(435);
   finalhisto_xg->SetMarkerColor(435);
   finalhisto_xg->Draw();


   finalhisto_wz->SetFillColor(626);
   finalhisto_wz->SetMarkerColor(626);
   finalhisto_wz->Draw();

   finalhisto_zz->SetFillColor(616);
   finalhisto_zz->SetMarkerColor(616);
   finalhisto_zz->Draw();

   finalhisto_ttv->SetFillColor(855);
   finalhisto_ttv->SetMarkerColor(855);
   finalhisto_ttv->Draw();

   finalhisto_vvv->SetFillColor(874);
   finalhisto_vvv->SetMarkerColor(874);
   finalhisto_vvv->Draw();

   finalhisto_higgs->SetFillColor(803);
   finalhisto_higgs->SetMarkerColor(803);
   finalhisto_higgs->Draw();

   finalhisto_misid->SetFillColor(800);
   finalhisto_misid->SetMarkerColor(800);
   finalhisto_misid->Draw();

   finalhisto_signal->SetFillColor(633);
   finalhisto_signal->SetMarkerColor(633);
   finalhisto_signal->Draw();

   cout<<finalhisto_vvv->Integral()<<endl;
   cout<<finalhisto_higgs->Integral()<<endl;
   cout<<finalhisto_zz->Integral()<<endl;
   cout<<finalhisto_ttv->Integral()<<endl;
   cout<<finalhisto_xg->Integral()<<endl;
   cout<<finalhisto_wz->Integral()<<endl;
   cout<<finalhisto_misid->Integral()<<endl;
   cout<<finalhisto_signal->Integral()<<endl;

   hstack->Add(finalhisto_vvv);
   hstack->Add(finalhisto_higgs);
   hstack->Add(finalhisto_zz);
   hstack->Add(finalhisto_ttv);
   hstack->Add(finalhisto_xg);
   hstack->Add(finalhisto_wz);
   hstack->Add(finalhisto_misid);
   
   
   
   
   
   
   
   
   
   
   
   TCanvas *cst = new TCanvas("cst","stacked hists",10,10,700,700);

   gPad->SetLogy();
   hstack->Draw("BAR");

   finalhisto_signal->Draw("same");
   finalhisto_signal->SetLineColor(kYellow);
   finalhisto_signal->SetLineWidth(2);
   hstack->GetXaxis()->SetTitle("P_{T} (GeV)");
   cst->Update();

   TLegend *legend=new TLegend(0.5,0.5,.9,.9);
   legend->SetHeader("Training Inputs"); // option "C" allows to center the header
   legend->AddEntry(finalhisto_misid,("MisId - Integral: "+std::to_string(finalhisto_misid->Integral())).c_str());
   legend->AddEntry(finalhisto_wz,("WZ - Integral: "+std::to_string(finalhisto_wz->Integral())).c_str());
   legend->AddEntry(finalhisto_xg,("XG - Integral: "+std::to_string(finalhisto_xg->Integral())).c_str());
   legend->AddEntry(finalhisto_ttv,("ttV - Integral: "+std::to_string(finalhisto_ttv->Integral())).c_str());
   legend->AddEntry(finalhisto_zz,("ZZ - Integral: "+std::to_string(finalhisto_zz->Integral())).c_str());
   
   legend->AddEntry(finalhisto_higgs,("Higgs - Integral: "+std::to_string(finalhisto_higgs->Integral())).c_str());
   legend->AddEntry(finalhisto_vvv,("VVV - Integral: "+std::to_string(finalhisto_vvv->Integral())).c_str());
   
   
   
   legend->AddEntry(finalhisto_signal,("Sigma_{380} - Integral: "+std::to_string(finalhisto_signal->Integral())).c_str());
   
   legend->Draw();

   cst->SaveAs("3L_noMod2Weights.png");
   

}

