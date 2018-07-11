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
#include "addAliases.C"
#include "TMVA/TMVAGui.h"
#include "TMVA/Tools.h"



void Seesaw_Training_4L( TString myMethodList = "" )
{
   //gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/92X/addAliases.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/customFunctions.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/customFudgeFactors_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/matrixMethod_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/leptonSFs_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/pileupWeights_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/software/pyPlotter/tools/triggerEffScaleFactor_2016.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars2.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars3.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars4.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars5.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars6.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars7.C");
   
   TMVA::Tools::Instance();
   std::map<std::string,int> Use;

   if (myMethodList != "") {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

      std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
      for (UInt_t i=0; i<mlist.size(); i++) {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end()) {
            std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
            std::cout << std::endl;
            return;
         }
         Use[regMethod] = 1;
      }
   }

   TString outfileName( "class_perf/92X_Seesaw_4L_optimized.root" );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   TMVA::Factory *factory = new TMVA::Factory( "92X_Seesaw_4L_optimized", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;P;G;D,D:AnalysisType=Classification" );

   TMVA::DataLoader* dl = new TMVA::DataLoader("dl");
   
   //dl->AddVariable("Alt$(LightLeptonLT4[0],0)");
   dl->AddVariable("Alt$(PFMETType1[0],0)");
   dl->AddVariable("Alt$(LightLeptonPt[0],0)");
   dl->AddVariable("Alt$(LightLeptonPt[1],0)");
   dl->AddVariable("Alt$(LightLeptonPt[2],0)");
   dl->AddVariable("Alt$(LightLeptonPt[3],0)");
   //dl->AddVariable("Alt$(LightLeptonMT3[0],0)");
   dl->AddVariable("Alt$(LightLeptonEta[0],0)");
   dl->AddVariable("Alt$(LightLeptonEta[1],0)");
   dl->AddVariable("Alt$(LightLeptonEta[2],0)");
   dl->AddVariable("Alt$(LightLeptonEta[3],0)");
   dl->AddVariable("Alt$(LightLeptonMass[0],0)");
   dl->AddVariable("JetN[0]");
   dl->AddVariable("Sum$(JetCombinedInclusiveSecondaryVertexV2BJetTags>0.8484&&fabs(JetEta)<2.4)");
   dl->AddVariable("Alt$(LightLeptonLeptonDRmin[0],0)");
   dl->AddVariable("Alt$(LightLeptonBestMOSSF[0],0)");

   dl->AddVariable("PtRatio4(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[3])");
   dl->AddVariable("PtRatio4(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2],LightLeptonPt[3])");
   dl->AddVariable("PtRatio4(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[3])");
   dl->AddVariable("PtRatio4(LightLeptonPt[3],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[0])");


   dl->AddVariable("DeltaPhi(LightLeptonEta[0],LightLeptonEta[1])");
   dl->AddVariable("DeltaPhi(LightLeptonEta[1],LightLeptonEta[2])");
   dl->AddVariable("DeltaPhi(LightLeptonEta[2],LightLeptonEta[0])");
   dl->AddVariable("DeltaPhi(LightLeptonEta[0],LightLeptonEta[3])");
   dl->AddVariable("DeltaPhi(LightLeptonEta[1],LightLeptonEta[3])");
   dl->AddVariable("DeltaPhi(LightLeptonEta[2],LightLeptonEta[3])");

   //dl->AddVariable("LightLeptonDXY(0, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])");
   //dl->AddVariable("LightLeptonDXY(1, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])");
   //dl->AddVariable("LightLeptonDXY(2, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])");
   //dl->AddVariable("LightLeptonDXY(3, Alt$(MuonDXY[0],0),Alt$(MuonDXY[1],0),Alt$(MuonDXY[2],0), Alt$(ElectronDXY[0],0),Alt$(ElectronDXY[1],0),Alt$(ElectronDXY[2],0), LightLeptonFlavor[0], LightLeptonNativeIndex[0])");

   //dl->AddVariable("metRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))");
   //dl->AddVariable("metStRatio := metRatio(Alt$(PFMETType1[0],0),LightLeptonLT4[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))");
   //dl->AddVariable("metRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT4[0],0))");

   //dl->AddVariable("metSquaredRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))");
   //dl->AddVariable("metSquaredRatio(Alt$(PFMETType1[0],0),LightLeptonLT4[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))");
   //dl->AddVariable("metSquaredRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT4[0],0))");
   
   //dl->AddVariable("metQuadRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))");
   //dl->AddVariable("metQuadRatio(Alt$(PFMETType1[0],0),LightLeptonLT4[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))");
   //dl->AddVariable("metQuadRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT4[0],0))");
   
   dl->AddVariable("Alt$(Sum$(JetPt),0)");
   dl->AddVariable("Alt$(LightLeptonLT4[0],0)+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0)");
   dl->AddVariable("Alt$(LightLeptonBestMSSSF[0],0)");
   dl->AddVariable("Alt$(LightLeptonPairPt[0],0)");


   std::string mass = "140";
   int nleptons = 4;
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

   TString Weight ="";
   TString WeightMisId = "";
   
   if(nleptons==4){
      Weight = "Weight*(LightLeptonNonFakeType4DA==1111)";
      WeightMisId = "Weight*(LightLeptonNonFakeType4DA<1111)";

   }else if (nleptons==3){
      Weight = "Weight*(LightLeptonNonFakeType3DA==111)";
      WeightMisId = "Weight*(LightLeptonNonFakeType3DA<111)";
   }

   

   //TCut mycuts = "((L3AboveZ||L3OnZ||L3BelowZ||L3OSSF0)&&LightLeptonPairDR[0]>0.4&&LightLeptonN[0]==3&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)";

   //TCut mycutb = "((L3AboveZ||L3OnZ||L3BelowZ||L3OSSF0)&&LightLeptonPairDR[0]>0.4&&LightLeptonN[0]==3&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0)";

   TCut mycuts = "(L4OSSF1||L4OSSF2)&&LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0&&L4VLL";

   TCut mycutb = "(L4OSSF1||L4OSSF2)&&LightLeptonPairDR[0]>0.4&&SingleIsoLeptonTrigAccept2016>0&&LowMassVeto==1&&HasTriggerMatch_2016>0&&L4VLL";


   

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
      ss >> xsec;    //don't need to use, already in the skims
      ss >> br;
      ss >> filter_eff;
      ss >> k_factor;         //reads process name and other numbers into respective variables


      std::string in = "TMVA/Signal/"+process+"/shortTree_4L.root";
      const char *sig_name = in.c_str();
      TFile *sig_input = TFile::Open( sig_name );     //opens signal file matching process name

      std::cout << "--- Using signal input file: " << sig_input->GetName() <<         std::endl;
      // --- Register the training and test trees
      TTree *signal     = (TTree*)sig_input->Get("tree");     //gets signal tree
      addAliasedVars(signal);
      
      cout<<"XSEC      BR          Filter_eff  K Factor  (Ignore if using \"Weight\" as weight)"<<endl;
      cout << xsec <<"   "<< br << "    "<<filter_eff<<"   "<< k_factor <<endl;
      

      TH1D *EventsSignal= new TH1D("EventsSignal","EventsSignal",60,0,600);
      signal->Draw("LightLeptonPt>>EventsSignal",mycuts*Weight);

      signal_events += EventsSignal->Integral();

      EventsSignal->Scale(lumi);
      finalhisto_signal->Add(EventsSignal);

      dl->SetSignalWeightExpression(Weight);
      dl->AddSignalTree    ( signal,      1 );
      

   }

   

   /////////////////////////////
   // Add MC Background Trees //
   /////////////////////////////

   //background weight expression (see key.txt for dataType of different files)

   



   
   std::ifstream infileb("backgrounds_TMVA_4L.txt");
   std::string lineb;
   std::getline(infileb, lineb);    //throws away first line which includes titles

   while (std::getline(infileb, lineb)) {    

      std::string bg;
      std::string bundleName;
      float back_xsec;      
      
      std::istringstream ss(lineb);       
      
      ss >> bg;
      ss >> back_xsec;  //don't need to use with skims!!!! IGNORE
      ss >> bundleName;
      std::string in;

      
      // if file is ttbar or dy, it is store in a different directory than all other MCs!
      
      in = "TMVA/Backgrounds/"+bg+"/shortTree_4L.root";
      const char *back_name = in.c_str();
      TFile *back_input = TFile::Open( back_name ); 
      
      std::cout << "--- Using background input file: " << back_input->GetName() <<         std::endl;
      cout<<"XSEC      Bundle Name (XSEC ALREADY INCLUDED IN WEIGHT!)"<<endl;
      cout << back_xsec <<"   "<< bundleName <<endl;
      
      //Get ttree and event count histo
      TTree *background = (TTree*)back_input->Get("tree");
      addAliasedVars(background);
      

      TH1D *backgroundEvents= new TH1D("backgroundEvents","backgroundEvents",60,0,600);
      TH1D *MisIdEvents= new TH1D("MisIdEvents","MisIdEvents",60,0,600);
      
      //if file is not DY, then it gets written into background histo
      if(bundleName.find("dy") == std::string::npos){
         background->Draw("LightLeptonPt>>backgroundEvents",mycutb*Weight);
      }
      // All files are written into MisID histo with fakes req.
      background->Draw("LightLeptonPt>>MisIdEvents",mycutb*WeightMisId);

      //check bundle name and add events to appropriate histo
      if(bundleName.find("xg") != std::string::npos){
         xg_events += backgroundEvents->Integral();
         misid_events += MisIdEvents->Integral();

         backgroundEvents->Scale(lumi);
         MisIdEvents->Scale(lumi);
         cout<<xg_events*lumi<<endl;
         finalhisto_xg->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      
      }else if(bundleName.find("wz") != std::string::npos){
         wz_events += backgroundEvents->Integral();
         misid_events += MisIdEvents->Integral();

         backgroundEvents->Scale(lumi);
         MisIdEvents->Scale(lumi);

         finalhisto_wz->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("zz") != std::string::npos){
         zz_events += backgroundEvents->Integral();
         misid_events += MisIdEvents->Integral();

         backgroundEvents->Scale(lumi);
         MisIdEvents->Scale(lumi);

         finalhisto_zz->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("vvv") != std::string::npos){
         vvv_events += backgroundEvents->Integral();
         misid_events += MisIdEvents->Integral();

         backgroundEvents->Scale(lumi);
         MisIdEvents->Scale(lumi);

         finalhisto_vvv->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("ttv") != std::string::npos){
         ttv_events += backgroundEvents->Integral();
         misid_events += MisIdEvents->Integral();

         backgroundEvents->Scale(lumi);
         MisIdEvents->Scale(lumi);

         finalhisto_ttv->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("higgs") != std::string::npos){
         higgs_events += backgroundEvents->Integral();
         misid_events += MisIdEvents->Integral();

         backgroundEvents->Scale(lumi);
         MisIdEvents->Scale(lumi);

         finalhisto_higgs->Add(backgroundEvents);
         finalhisto_misid->Add(MisIdEvents);
      }else if(bundleName.find("dy") != std::string::npos){
         misid_events += MisIdEvents->Integral();

         MisIdEvents->Scale(lumi);

         finalhisto_misid->Add(MisIdEvents);
      }

      dl->SetBackgroundWeightExpression("Weight");
      dl->AddBackgroundTree ( background, 1); 
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

   
   
   
   
   
   //hstack->Add(finalhisto_wz);
   
   
   
   
   
   
   hstack->Add(finalhisto_xg);
   hstack->Add(finalhisto_wz);
   hstack->Add(finalhisto_misid);
   hstack->Add(finalhisto_vvv);
   hstack->Add(finalhisto_higgs);
   hstack->Add(finalhisto_ttv);
   hstack->Add(finalhisto_zz);
   
   
   
   
   
   
   
   
   
   TCanvas *cst = new TCanvas("cst","stacked hists",10,10,700,700);

   gPad->SetLogy();
   hstack->Draw("BAR");

   finalhisto_signal->Draw("same");
   finalhisto_signal->SetLineColor(kYellow);
   finalhisto_signal->SetLineWidth(2);
   hstack->GetXaxis()->SetTitle("P_{T} 1st lepton (GeV)");
   cst->Update();

   TLegend *legend=new TLegend(0.5,0.5,.9,.9);
   legend->SetHeader("Training Inputs"); // option "C" allows to center the header
   legend->AddEntry(finalhisto_zz,("ZZ - Integral: "+std::to_string(finalhisto_zz->Integral())).c_str());
   legend->AddEntry(finalhisto_ttv,("ttV - Integral: "+std::to_string(finalhisto_ttv->Integral())).c_str());
   legend->AddEntry(finalhisto_higgs,("Higgs - Integral: "+std::to_string(finalhisto_higgs->Integral())).c_str());
   legend->AddEntry(finalhisto_vvv,("VVV - Integral: "+std::to_string(finalhisto_vvv->Integral())).c_str());
   legend->AddEntry(finalhisto_wz,("WZ - Integral: "+std::to_string(finalhisto_wz->Integral())).c_str());
   legend->AddEntry(finalhisto_misid,("MisId - Integral: "+std::to_string(finalhisto_misid->Integral())).c_str());
   legend->AddEntry(finalhisto_xg,("XG - Integral: "+std::to_string(finalhisto_xg->Integral())).c_str());
   legend->AddEntry(finalhisto_signal,("Sigma_{380} - Integral: "+std::to_string(finalhisto_signal->Integral())).c_str());
   

   //legend->AddEntry(finalhisto_wz,("WZ - Integral: "+std::to_string(finalhisto_wz->Integral())).c_str());
   
   
   
   
   
   
   
   
   legend->AddEntry(finalhisto_signal,("Sigma_{140} - Integral: "+std::to_string(finalhisto_signal->Integral())).c_str());
   
   legend->Draw();

   cst->SaveAs("preTraining.png");


   cout<<"Prepare Training and Testing Trees:"<<endl;
   dl->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

   //factory->BookMethod( dl, TMVA::Types::kBDT, "Identity", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "PCA", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6::VarTransform=P" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6::VarTransform=G" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT1", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "Identity", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=100:MaxDepth=6::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "PCA", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=100:MaxDepth=6::VarTransform=P" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "Deco", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=100:MaxDepth=6::VarTransform=D" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=100:MaxDepth=6::VarTransform=G" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT3", "!H:!V:NTrees=150:MinNodeSize=7.5%:BoostType=Grad:Shrinkage=1:nCuts=5:MaxDepth=4::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "Identity", "!H:!V:NTrees=10:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "Decorrelation", "!H:!V:NTrees=150:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "PCA", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4::VarTransform=I" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT3", "!H:!V:NTrees=150:MinNodeSize=7.5%:BoostType=Grad:Shrinkage=1:nCuts=5:MaxDepth=4::VarTransform=G" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "Decorrelation", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6::VarTransform=D" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT1", "!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6::VarTransform=G" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT2", "!H:!V:NTrees=850:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6::VarTransform=G" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "BDT3", "!H:!V:NTrees=850:MinNodeSize=7.5%:BoostType=Grad:Shrinkage=.7:nCuts=5:MaxDepth=4" );

   //GRADIENT BOOSTING

   //shrinkage
  /*
  factory->BookMethod( dl, TMVA::Types::kBDT, "shrinkage .01","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=.01:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "shrinkage .1","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=.1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "shrinkage .3","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=.3:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "shrinkage .5","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=.5:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "shrinkage .7","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=.7:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "shrinkage 1","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   */
   
   //ncuts
   /*
   factory->BookMethod( dl, TMVA::Types::kBDT, "100 cuts","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=100:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "50 cuts","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=50:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "20 cuts","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "10 cuts","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=10:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "5 cuts","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=5:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "1 cut","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=1:MaxDepth=6" );
   */
   
   //depth
   /*
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 1","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=1" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 2","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 4","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 6","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 8","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=8" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 10","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=10" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 20","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=20" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "depth 100","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=100" );
   */
   
   //ntrees
   /*
   factory->BookMethod( dl, TMVA::Types::kBDT, "150 trees","!H:!V:NTrees=150:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6"  );
   factory->BookMethod( dl, TMVA::Types::kBDT, "450 trees","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6"  );
   factory->BookMethod( dl, TMVA::Types::kBDT, "850 trees","!H:!V:NTrees=850:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6"  );
   factory->BookMethod( dl, TMVA::Types::kBDT, "1000 trees","!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6"  );
   factory->BookMethod( dl, TMVA::Types::kBDT, "2000 trees","!H:!V:NTrees=2000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6"  );
   factory->BookMethod( dl, TMVA::Types::kBDT, "50 trees","!H:!V:NTrees=50:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6"  );
   */
   

   //minNodePercentage
   /*
   factory->BookMethod( dl, TMVA::Types::kBDT, "1%","!H:!V:NTrees=450:MinNodeSize=1.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "2.5%","!H:!V:NTrees=450:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "5.0%","!H:!V:NTrees=450:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "7.5%","!H:!V:NTrees=450:MinNodeSize=7.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "20%","!H:!V:NTrees=450:MinNodeSize=20.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   factory->BookMethod( dl, TMVA::Types::kBDT, "30%","!H:!V:NTrees=450:MinNodeSize=30.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=6" );
   */
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();



   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;


   delete factory;

   // Launch the GUI for the root macros
   if (!gROOT->IsBatch()){;
         TMVA::TMVAGui( outfileName );
   }
   

}