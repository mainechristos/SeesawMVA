#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars.C"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars2.C"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars3.C"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars4.C"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars5.C"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars6.C"
#include "/cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars7.C"
#include "TMVA/Tools.h"


using namespace TMVA;

void runSignal(TString ifile = ""){

   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/customFunctions.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/customFudgeFactors_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/matrixMethod_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/leptonSFs_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/pileupWeights_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/triggerEffScaleFactor_2016.C");


   TMVA::Tools::Instance();
  

   TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );    


   Float_t MuonDXY0, MuonDXY1, MuonDXY2, ElectronDXY0, ElectronDXY1, ElectronDXY2, LightLeptonPhi0, LightLeptonPhi1, LightLeptonPhi2;
   Int_t LightLeptonFlavor0, LightLeptonFlavor1, LightLeptonFlavor2, LightLeptonFlavor3, LightLeptonNativeIndex0, LightLeptonNativeIndex1, LightLeptonNativeIndex2, LightLeptonNativeIndex3;
   Float_t LightLeptonLT3, LightLeptonLT4, LightLeptonMT3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonBestMOSSF, PFMETType1;
   Float_t LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonMass, LightLeptonLeptonDRmin0, LightLeptonLeptonDRmin1, LightLeptonLeptonDRmin2;
   Float_t JetN;
   Int_t LightLeptonN, LightLeptonOnZN, ElectronN, LightLeptonTightType3D, MuonN, PassBadChargedCandidateFilter, PassBadPFMuonFilter;
   Float_t PtRatio1, PtRatio2, PtRatio3, DPhi1, DPhi2,  DPhi3, DPhi4, DPhi5, DPhi6, LightLeptonDXY0, LightLeptonDXY1, LightLeptonDXY2; 
   Float_t metHtRatio, metStRatio, metLtRatio, metHtSquaredRatio, metSquaredStRatio, metLtSquaredRatio, metHtQuadRatio, metQuadStRatio, metLtQuadRatio, HT, ST, LightLeptonBestMSSSF, LightLeptonPairPt;
   Float_t PtRatio4L1, PtRatio4L2, PtRatio4L3, PtRatio4L4;
   Float_t BJetN;
   
  reader->AddVariable("LightLeptonLT := Alt$(LightLeptonLT3[0],0)", &LightLeptonLT3);
   reader->AddVariable("PFMETType1 := Alt$(PFMETType1[0],0)", &PFMETType1);
   reader->AddVariable("LightLeptonPt0 := Alt$(LightLeptonPt[0],0)", &LightLeptonPt0 );
   reader->AddVariable("LightLeptonPt1 := Alt$(LightLeptonPt[1],0)",&LightLeptonPt1);
   reader->AddVariable("LightLeptonPt2 := Alt$(LightLeptonPt[2],0)",&LightLeptonPt2);
   //reader->AddVariable("LightLeptonPt3 := Alt$(LightLeptonPt[3],0)",&LightLeptonPt3);
   reader->AddVariable("LightLeptonMT3 := Alt$(LightLeptonMT3[0],0)",&LightLeptonMT3);
   reader->AddVariable("LightLeptonEta0 := Alt$(LightLeptonEta[0],0)", &LightLeptonEta0 );
   reader->AddVariable("LightLeptonEta1 := Alt$(LightLeptonEta[1],0)",&LightLeptonEta1);
   reader->AddVariable("LightLeptonEta2 := Alt$(LightLeptonEta[2],0)",&LightLeptonEta2);
   //reader->AddVariable("LightLeptonEta3 := Alt$(LightLeptonEta[3],0)",&LightLeptonEta3);
   reader->AddVariable("LightLeptonMass := Alt$(LightLeptonMass[0],0)",&LightLeptonMass);
   reader->AddVariable("JetN := JetN[0]",&JetN);
   reader->AddVariable("BJetN := Sum$(JetCombinedInclusiveSecondaryVertexV2BJetTags>0.8484&&fabs(JetEta)<2.4)",&BJetN);
   reader->AddVariable("LightLeptonLeptonDRmin0 := Alt$(LightLeptonLeptonDRmin[0],0)", &LightLeptonLeptonDRmin0 );
   reader->AddVariable("LightLeptonBestMOSSF := Alt$(LightLeptonBestMOSSF[0],0)", &LightLeptonBestMOSSF );

   reader->AddVariable("PtRatio1 := PtRatio(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2])", &PtRatio1);
   reader->AddVariable("PtRatio2 := PtRatio(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2])", &PtRatio2);
   reader->AddVariable("PtRatio3 := PtRatio(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1])", &PtRatio3);

   //reader->AddVariable("PtRatio4L1 := PtRatio4(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L1);
   //reader->AddVariable("PtRatio4L2 := PtRatio4(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L2);
   //reader->AddVariable("PtRatio4L3 := PtRatio4(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[3])", &PtRatio4L3);
   //reader->AddVariable("PtRatio4L4 := PtRatio4(LightLeptonPt[3],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[0])", &PtRatio4L4);

   reader->AddVariable("DPhi1 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[1])", &DPhi1);
   reader->AddVariable("DPhi2 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[2])", &DPhi2);
   reader->AddVariable("DPhi3 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[0])", &DPhi3);
   //reader->AddVariable("DPhi4 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[3])", &DPhi4);
   //reader->AddVariable("DPhi5 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[3])", &DPhi5);
   //reader->AddVariable("DPhi6 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[3])", &DPhi6);

   reader->AddVariable("LightLeptonDXY0 := LightLeptonDXY(0, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])",&LightLeptonDXY0);
   reader->AddVariable("LightLeptonDXY1 := LightLeptonDXY(1, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])",&LightLeptonDXY1);
   reader->AddVariable("LightLeptonDXY2 := LightLeptonDXY(2, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])",&LightLeptonDXY2);

   reader->AddVariable("metHtRatio := metRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))", &metHtRatio);
   reader->AddVariable("metStRatio := metRatio(Alt$(PFMETType1[0],0),LightLeptonLT3[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))", &metStRatio);
   reader->AddVariable("metLtRatio := metRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT3[0],0))", &metLtRatio);

   reader->AddVariable("metHtSquaredRatio := metSquaredRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))", &metHtSquaredRatio);
   reader->AddVariable("metSquaredStRatio := metSquaredRatio(Alt$(PFMETType1[0],0),LightLeptonLT3[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))", &metSquaredStRatio);
   reader->AddVariable("metLtSquaredRatio := metSquaredRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT3[0],0))", &metLtSquaredRatio);
   
   reader->AddVariable("metHtQuadRatio := metQuadRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))", &metHtQuadRatio);
   reader->AddVariable("metQuadStRatio := metQuadRatio(Alt$(PFMETType1[0],0),LightLeptonLT3[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))", &metQuadStRatio);
   reader->AddVariable("metLtQuadRatio := metQuadRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT3[0],0))", &metLtQuadRatio);

   reader->AddVariable("HT := Alt$(Sum$(JetPt),0)",&HT);
   reader->AddVariable("ST := Alt$(LightLeptonLT3[0],0)+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0)",&ST);
   reader->AddVariable("LightLeptonBestMSSSF := Alt$(LightLeptonBestMSSSF[0],0)",&LightLeptonBestMSSSF);
   reader->AddVariable("LightLeptonPairPt := Alt$(LightLeptonPairPt[0],0)",&LightLeptonPairPt);
   
   // --- Book the MVA methods

   TString dir    = "/cms/mchristos/ANN/Seesaw/2016/92X/weights/";
   TString prefix = "2017_TMVA_optimized";



   reader->BookMVA( "BDTG method",  "/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/dl/weights/92X_Seesaw_optimized1_a_BDT1.weights.xml");

   vector<double>  vecBDTG; 
  
   TFile *input(0);
   TString fname = ifile;   
   input = TFile::Open(fname);

   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;
   
   // --- Event loop

   // Prepare the event tree
   std::cout << "--- Select Signal sample" << std::endl;
   TTree *tree = (TTree*)input->Get("rootTupleTreeVeryLoose/tree");
   TTreeReader myReader(tree);
   TH1I *histo= new TH1I();
   histo = (TH1I*)input->Get("veryLooseDileptonEventFilter/EventCount/EventCounter");   
    
 
   TTreeReaderValue<vector<Float_t>> inMuonDXY(myReader, "MuonDXY");
   TTreeReaderValue<vector<Float_t>> inElectronDXY(myReader, "ElectronDXY");
   TTreeReaderValue<vector<Float_t>> inLightLeptonPhi(myReader, "LightLeptonPhi");
   TTreeReaderValue<vector<Int_t>> inLightLeptonFlavor(myReader, "LightLeptonFlavor");
   TTreeReaderValue<vector<Int_t>> inLightLeptonNativeIndex(myReader, "LightLeptonNativeIndex");
   TTreeReaderValue<vector<Float_t>> inLightLeptonBestMOSSF(myReader, "LightLeptonBestMOSSF");
   TTreeReaderValue<vector<Float_t>> inPFMETType1(myReader, "PFMETType1");
   TTreeReaderValue<vector<Float_t>> inLightLeptonPt(myReader, "LightLeptonPt");
   TTreeReaderValue<vector<Float_t>> inLightLeptonEta(myReader, "LightLeptonEta");
   TTreeReaderValue<vector<Float_t>> inJetEta(myReader, "JetEta");
   TTreeReaderValue<vector<Float_t>> inJetCombinedInclusiveSecondaryVertexV2BJetTags(myReader, "JetCombinedInclusiveSecondaryVertexV2BJetTags");
   TTreeReaderValue<vector<Int_t>> inJetN(myReader, "JetN");
   TTreeReaderValue<vector<Float_t>> inLightLeptonLeptonDRmin(myReader, "LightLeptonLeptonDRmin");
   TTreeReaderValue<vector<Float_t>> inLightLeptonMass(myReader, "LightLeptonMass");
   TTreeReaderValue<vector<Float_t>> inLightLeptonLT3(myReader, "LightLeptonLT3");
   TTreeReaderValue<vector<Float_t>> inLightLeptonLT4(myReader, "LightLeptonLT4");
   TTreeReaderValue<vector<Float_t>> inLightLeptonMT3(myReader, "LightLeptonMT3");
   TTreeReaderValue<vector<Int_t>> inLightLeptonN(myReader, "LightLeptonN");
   TTreeReaderValue<vector<Int_t>> inLightLeptonOnZN(myReader, "LightLeptonOnZN");
   TTreeReaderValue<vector<Int_t>> inElectronN(myReader, "ElectronN");
   TTreeReaderValue<vector<Int_t>> inMuonN(myReader, "MuonN");
   TTreeReaderValue<vector<Int_t>> inPassBadChargedCandidateFilter(myReader, "PassBadChargedCandidateFilter");
   TTreeReaderValue<vector<Int_t>> inPassBadPFMuonFilter(myReader, "PassBadPFMuonFilter");
   TTreeReaderValue<vector<Float_t>> inJetPt(myReader, "JetPt");
   TTreeReaderValue<vector<Float_t>> inLightLeptonBestMSSSF(myReader, "LightLeptonBestMSSSF");
   TTreeReaderValue<vector<Float_t>> inLightLeptonPairPt(myReader, "LightLeptonPairPt");

   


   TFile *endfile = new TFile("/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Signal/SIGMAplusSIGMA-HH/BDTtree.root","RECREATE");   
   
   endfile->cd();
   endfile->mkdir("veryLooseDileptonEventFilter/");
   endfile->cd();
   endfile->mkdir("veryLooseDileptonEventFilter/EventCount/");
   endfile->cd("veryLooseDileptonEventFilter/EventCount/");

   histo->Write();
   endfile->cd();

   endfile->mkdir("rootTupleTreeVeryLoose/");
   endfile->cd("rootTupleTreeVeryLoose/");
   TTree *found_back_tree = tree->CloneTree(0);

   std::vector<double> *BDTResponse = new std::vector<double>(0);
   found_back_tree->Branch("BDT",&BDTResponse);

   std::vector<float> vecVar(4); // vector for EvaluateMVA tests

   std::cout << "--- Processing: " << tree->GetEntries() << " events" << std::endl;
   TStopwatch sw;
   sw.Start();
   int count = 0;
   
   while (myReader.Next()) {

      if (count%1000 == 0) std::cout << "--- ... Processing event: " << count << std::endl;
      
      //This will get entries to fill nonspecified branches in the cloned tree.
      tree->GetEntry(count);
      
      HT=0;
      for(std::vector<float>::iterator jetpt = inJetPt->begin(); jetpt != inJetPt->end(); ++jetpt){
         HT += *jetpt;
      }
      if(inMuonDXY->size()>=3){
         MuonDXY0 = inMuonDXY->at(0);
         MuonDXY1 = inMuonDXY->at(1);
         MuonDXY2 = inMuonDXY->at(2);
      }else if(inMuonDXY->size()==2){
         MuonDXY0 = inMuonDXY->at(0);
         MuonDXY1 = inMuonDXY->at(1);
         MuonDXY2 = 0;
      }else if(inMuonDXY->size()==1){
         MuonDXY0 = inMuonDXY->at(0);
         MuonDXY1 = 0;
         MuonDXY2 = 0;
      }else{
         MuonDXY0 = 0;
         MuonDXY1 = 0;
         MuonDXY2 = 0;
      }

      if(inElectronDXY->size()>=3){
         ElectronDXY0 = inElectronDXY->at(0);
         ElectronDXY1 = inElectronDXY->at(1);
         ElectronDXY2 = inElectronDXY->at(2);
      }else if(inElectronDXY->size()==2){
         ElectronDXY0 = inElectronDXY->at(0);
         ElectronDXY1 = inElectronDXY->at(1);
         ElectronDXY2 = 0;
      }else if(inElectronDXY->size()==1){
         ElectronDXY0 = inElectronDXY->at(0);
         ElectronDXY1 = 0;
         ElectronDXY2 = 0;
      }else{
         ElectronDXY0 = 0;
         ElectronDXY1 = 0;
         ElectronDXY2 = 0;
      }
      if(inLightLeptonPhi->size()>=3){
         LightLeptonPhi0 = inLightLeptonPhi->at(0);
         LightLeptonPhi1 = inLightLeptonPhi->at(1);
         LightLeptonPhi2 = inLightLeptonPhi->at(2);
      }else if(inLightLeptonPhi->size()==2){
         LightLeptonPhi0 = inLightLeptonPhi->at(0);
         LightLeptonPhi1 = inLightLeptonPhi->at(1);
         LightLeptonPhi2 = 0;
      }else if(inLightLeptonPhi->size()==1){
         LightLeptonPhi0 = inLightLeptonPhi->at(0);
         LightLeptonPhi1 = 0;
         LightLeptonPhi2 = 0;
      }else{
         LightLeptonPhi0 = 0;
         LightLeptonPhi1 = 0;
         LightLeptonPhi2 = 0;
      }


      if(inLightLeptonBestMSSSF->empty()){
         LightLeptonBestMSSSF = 0;
      }else{
         LightLeptonBestMSSSF = inLightLeptonBestMSSSF->at(0);
      }


      if(inLightLeptonPairPt->empty()){
         LightLeptonPairPt = 0;
      }else{
         LightLeptonPairPt = inLightLeptonPairPt->at(0);
      }
      if(inLightLeptonLeptonDRmin->size()>=3){
         LightLeptonLeptonDRmin0 = inLightLeptonLeptonDRmin->at(0);
         LightLeptonLeptonDRmin1 = inLightLeptonLeptonDRmin->at(1);
         LightLeptonLeptonDRmin2 = inLightLeptonLeptonDRmin->at(2);
      }else if(inLightLeptonLeptonDRmin->size()==2){
         LightLeptonLeptonDRmin0 = inLightLeptonLeptonDRmin->at(0);
         LightLeptonLeptonDRmin1 = inLightLeptonLeptonDRmin->at(1);
         LightLeptonLeptonDRmin2 = 0;
      }else if(inLightLeptonLeptonDRmin->size()==1){
         LightLeptonLeptonDRmin0 = inLightLeptonLeptonDRmin->at(0);
         LightLeptonLeptonDRmin1 = 0;
         LightLeptonLeptonDRmin2 = 0;
      }else{
         LightLeptonLeptonDRmin0 = 0;
         LightLeptonLeptonDRmin1 = 0;
         LightLeptonLeptonDRmin2 = 0;
      }

      if(inLightLeptonMT3->empty()){
         LightLeptonMT3 = 0;
      }else{
         LightLeptonMT3 = inLightLeptonMT3->at(0);
      }
      LightLeptonOnZN = inLightLeptonOnZN->at(0);

      //START
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


      if(inLightLeptonLT3->empty()){
         LightLeptonLT3 = 0;
      }else{
         LightLeptonLT3 = inLightLeptonLT3->at(0);
      }

      if(inLightLeptonLT4->empty()){
         LightLeptonLT4 = 0;
      }else{
         LightLeptonLT4 = inLightLeptonLT4->at(0);
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

      PtRatio1 = PtRatio(LightLeptonPt0,LightLeptonPt1,LightLeptonPt2);
      PtRatio2 = PtRatio(LightLeptonPt1,LightLeptonPt0,LightLeptonPt2);
      PtRatio3 = PtRatio(LightLeptonPt2,LightLeptonPt0,LightLeptonPt1);

      PtRatio4L1 = PtRatio4(LightLeptonPt0,LightLeptonPt1,LightLeptonPt2,LightLeptonPt3);
      PtRatio4L2 = PtRatio4(LightLeptonPt1,LightLeptonPt0,LightLeptonPt2,LightLeptonPt3);
      PtRatio4L3 = PtRatio4(LightLeptonPt2,LightLeptonPt0,LightLeptonPt1,LightLeptonPt3);
      PtRatio4L4 = PtRatio4(LightLeptonPt3,LightLeptonPt1,LightLeptonPt2,LightLeptonPt0);


      DPhi1 = DeltaPhi(LightLeptonEta0,LightLeptonEta1);
      DPhi2 = DeltaPhi(LightLeptonEta1,LightLeptonEta2);
      DPhi3 = DeltaPhi(LightLeptonEta2,LightLeptonEta0);
      DPhi4 = DeltaPhi(LightLeptonEta0,LightLeptonEta3);
      DPhi5 = DeltaPhi(LightLeptonEta1,LightLeptonEta3);
      DPhi6 = DeltaPhi(LightLeptonEta2,LightLeptonEta3);

      LightLeptonDXY0 = LightLeptonDXY(0, MuonDXY0,MuonDXY1,MuonDXY2, ElectronDXY0,ElectronDXY1,ElectronDXY2, LightLeptonFlavor0, LightLeptonNativeIndex0);
      LightLeptonDXY1 = LightLeptonDXY(1, MuonDXY0,MuonDXY1,MuonDXY2, ElectronDXY0,ElectronDXY1,ElectronDXY2, LightLeptonFlavor0, LightLeptonNativeIndex0);
      LightLeptonDXY2 = LightLeptonDXY(2, MuonDXY0,MuonDXY1,MuonDXY2, ElectronDXY0,ElectronDXY1,ElectronDXY2, LightLeptonFlavor0, LightLeptonNativeIndex0);

      ST=LightLeptonLT4+PFMETType1+HT;

      metHtRatio=metRatio(PFMETType1,HT);
      metStRatio=metRatio(PFMETType1,ST);
      metLtRatio=metRatio(PFMETType1,LightLeptonLT4);

      metHtSquaredRatio=metSquaredRatio(PFMETType1,HT);
      metSquaredStRatio=metSquaredRatio(PFMETType1,ST);
      metLtSquaredRatio=metSquaredRatio(PFMETType1,LightLeptonLT4);

      metHtQuadRatio=metQuadRatio(PFMETType1,HT);
      metQuadStRatio=metQuadRatio(PFMETType1,ST);
      metLtQuadRatio=metQuadRatio(PFMETType1,LightLeptonLT4);

      BJetN = 0;
      int countEta=0;
      for(std::vector<float>::iterator tag = inJetCombinedInclusiveSecondaryVertexV2BJetTags->begin(); tag != inJetCombinedInclusiveSecondaryVertexV2BJetTags->end(); ++tag){
         if(*tag>.84&&fabs(inJetEta->at(countEta))<2.4){
            BJetN++;
         }
         countEta++;
      }


      double result =  reader->EvaluateMVA( "BDTG method" );
      BDTResponse->clear();
      BDTResponse->push_back(result);
      if (result > -0.1153) vecBDTG.push_back(count);
      found_back_tree->Fill();
      count++;
   }
   
   // Get elapsed time
   sw.Stop();
   std::cout << "--- End of event loop: "; sw.Print();

   
   std::cout << "Printing out all passed events... " << std::endl;
   

   std::cout << "BDT: \n"<< vecBDTG.size() << "\t passed events" << std::endl;

   
   found_back_tree->Write();
   

   
   endfile->Close();               
  
   delete reader;
    


}

void Seesaw_Application_signal( TString myMethodList = "" ) 
{   

   TMVA::Tools::Instance();



   std::cout << std::endl;
   std::cout << "==> Start TMVAClassificationApplication" << std::endl;

   TString back_name = "/cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Signal/SIGMAplusSIGMA-HH/analysisTree.root";


   runSignal(back_name);
   std::cout << "==> TMVAClassificationApplication is done!" << endl << std::endl;
} 

