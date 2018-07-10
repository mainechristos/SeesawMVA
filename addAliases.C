void addAliasedVars(TTree *tree){
    
   
	tree->SetAlias("SingleIsoLeptonTrigAccept2016","(((((HLTIsoMu24vAccept[0]>0||HLTIsoTkMu24vAccept[0]>0)*(MuonN[0]>0&&((Alt$(LightLeptonPt[0],0)*(Alt$(LightLeptonFlavor[0],0)==2)+Alt$(LightLeptonPt[1],0)*(Alt$(LightLeptonFlavor[1],0)==2)*(((Alt$(LightLeptonFlavor[0],0)==2))==0)+Alt$(LightLeptonPt[2],0)*(Alt$(LightLeptonFlavor[2],0)==2)*(((Alt$(LightLeptonFlavor[0],0)==2)+(Alt$(LightLeptonFlavor[1],0)==2))==0)+Alt$(LightLeptonPt[3],0)*(Alt$(LightLeptonFlavor[3],0)==2)*(((Alt$(LightLeptonFlavor[0],0)==2)+(Alt$(LightLeptonFlavor[1],0)==2)+(Alt$(LightLeptonFlavor[2],0)==2))==0)))>25)*(SampleType[0]==4||SampleType[0]==-1))>0)||(((HLTEle27WPTightGsfvAccept[0]>0)*(ElectronN[0]>0&&((Alt$(LightLeptonPt[0],0)*(Alt$(LightLeptonFlavor[0],0)==1)+Alt$(LightLeptonPt[1],0)*(Alt$(LightLeptonFlavor[1],0)==1)*(((Alt$(LightLeptonFlavor[0],0)==1))==0)+Alt$(LightLeptonPt[2],0)*(Alt$(LightLeptonFlavor[2],0)==1)*(((Alt$(LightLeptonFlavor[0],0)==1)+(Alt$(LightLeptonFlavor[1],0)==1))==0)+Alt$(LightLeptonPt[3],0)*(Alt$(LightLeptonFlavor[3],0)==1)*(((Alt$(LightLeptonFlavor[0],0)==1)+(Alt$(LightLeptonFlavor[1],0)==1)+(Alt$(LightLeptonFlavor[2],0)==1))==0)))>30)*(SampleType[0]==5||SampleType[0]==-1))>0&&((HLTIsoMu24vAccept[0]>0||HLTIsoTkMu24vAccept[0]>0)*(MuonN[0]>0&&((Alt$(LightLeptonPt[0],0)*(Alt$(LightLeptonFlavor[0],0)==2)+Alt$(LightLeptonPt[1],0)*(Alt$(LightLeptonFlavor[1],0)==2)*(((Alt$(LightLeptonFlavor[0],0)==2))==0)+Alt$(LightLeptonPt[2],0)*(Alt$(LightLeptonFlavor[2],0)==2)*(((Alt$(LightLeptonFlavor[0],0)==2)+(Alt$(LightLeptonFlavor[1],0)==2))==0)+Alt$(LightLeptonPt[3],0)*(Alt$(LightLeptonFlavor[3],0)==2)*(((Alt$(LightLeptonFlavor[0],0)==2)+(Alt$(LightLeptonFlavor[1],0)==2)+(Alt$(LightLeptonFlavor[2],0)==2))==0)))>25)*(SampleType[0]==5))==0)))");
	
	tree->SetAlias("LowMassVeto","(((LightLeptonMinMOSSF[0]>12&&LightLeptonMinMOSSF[0]<=LightLeptonMinMSSSF[0])||(LightLeptonMinMSSSF[0]>12&&LightLeptonMinMSSSF[0]<LightLeptonMinMOSSF[0])))");
	
	tree->SetAlias("HasTriggerMatch_2016","((((((Sum$(ElectronDRHltEle27WPTightGsfv<0.2&&ElectronIsTight>0&&ElectronPt>30)))*(SampleType[0]==5||SampleType[0]==-1))>0)||((((Sum$(MuonDRHltIsoMu24OrTkMu24v<0.2&&MuonIsTight>0&&MuonPt>25)))*(SampleType[0]==4||SampleType[0]==-1))>0)))");
	
	tree->SetAlias("L3AboveZ","((((LightLeptonBestMOSSF[0]>(((91.1876*(1>0))+15.)*(1>0)))&&((LightLeptonN[0]==3)*(LightLeptonNOSSF[0]>0)>0)))==1&&LightLeptonN[0]==3)");
	
	tree->SetAlias("L3OnZ","(((LightLeptonBestMOSSF[0]>(((91.1876*(1>0))-15.)*(1>0))&&LightLeptonBestMOSSF[0]<(((91.1876*(1>0))+15.)*(1>0)))*(1>0))>0&&(PFMETType1[0])>100&&LightLeptonN[0]==3)");
	
	tree->SetAlias("L3BelowZ","((((LightLeptonBestMOSSF[0]<(((91.1876*(1>0))-15.)*(1>0)))&&((LightLeptonN[0]==3)*(LightLeptonNOSSF[0]>0)>0)))==1&&(PFMETType1[0])>50&&((LightLeptonN[0]==3)*(LightLeptonBestMOSSF[0]<(((91.1876*(1>0))-15.)*(1>0))&&LightLeptonMass[0]<(((91.1876*(1>0))+15.)*(1>0))&&LightLeptonMass[0]>(((91.1876*(1>0))-15.)*(1>0))&&LightLeptonNOSSF[0]>0))==0&&LightLeptonN[0]==3)");
	
	tree->SetAlias("L3OSSF0","(LightLeptonNOSSF[0]==0&&LightLeptonN[0]==3)");
	
	tree->SetAlias("L4OSSF1","(((LightLeptonN[0]==4)*(((LightLeptonN[0]==4)*(LightLeptonElectronNOSSF[0]==4||LightLeptonMuonNOSSF[0]==4||(LightLeptonElectronNOSSF[0]==1&&LightLeptonMuonNOSSF[0]==1)))==0&&LightLeptonNOSSF>0))==1&&LightLeptonN[0]==4)");

	tree->SetAlias("L4OSSF2","(((LightLeptonN[0]==4)*(LightLeptonElectronNOSSF[0]==4||LightLeptonMuonNOSSF[0]==4||(LightLeptonElectronNOSSF[0]==1&&LightLeptonMuonNOSSF[0]==1)))==1&&LightLeptonN[0]==4&&((PFMETType1[0])>50||((PFMETType1[0])<50&&((LightLeptonN[0]==4)*((((1>0)*(Alt$(LightLeptonDiMassOSSF[0],0)))>(((91.1876*(1>0))-15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[0],0)))<(((91.1876*(1>0))+15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[5],0)))>(((91.1876*(1>0))-15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[5],0)))<(((91.1876*(1>0))+15.)*(1>0)))||(((1>0)*(Alt$(LightLeptonDiMassOSSF[1],0)))>(((91.1876*(1>0))-15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[1],0)))<(((91.1876*(1>0))+15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[4],0)))>(((91.1876*(1>0))-15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[4],0)))<(((91.1876*(1>0))+15.)*(1>0)))||(((1>0)*(Alt$(LightLeptonDiMassOSSF[2],0)))>(((91.1876*(1>0))-15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[2],0)))<(((91.1876*(1>0))+15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[3],0)))>(((91.1876*(1>0))-15.)*(1>0))&&((1>0)*(Alt$(LightLeptonDiMassOSSF[3],0)))<(((91.1876*(1>0))+15.)*(1>0)))))==0)))");

	tree->SetAlias("LightLeptonTightType4DA","((((((Alt$(MuonIsTight[(LightLeptonNativeIndex[0]*(LightLeptonNativeIndex[0]>=0))],0)==1)*(LightLeptonFlavor[0]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[0]*(LightLeptonNativeIndex[0]>=0))],0.))*(LightLeptonFlavor[0]==1)))*1000+(((Alt$(MuonIsTight[(LightLeptonNativeIndex[1]*(LightLeptonNativeIndex[1]>=0))],0)==1)*(LightLeptonFlavor[1]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[1]*(LightLeptonNativeIndex[1]>=0))],0.))*(LightLeptonFlavor[1]==1)))*100+(((Alt$(MuonIsTight[(LightLeptonNativeIndex[2]*(LightLeptonNativeIndex[2]>=0))],0)==1)*(LightLeptonFlavor[2]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[2]*(LightLeptonNativeIndex[2]>=0))],0.))*(LightLeptonFlavor[2]==1)))*10+(((Alt$(MuonIsTight[(LightLeptonNativeIndex[3]*(LightLeptonNativeIndex[3]>=0))],0)==1)*(LightLeptonFlavor[3]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[3]*(LightLeptonNativeIndex[3]>=0))],0.))*(LightLeptonFlavor[3]==1))))))");
	tree->SetAlias("PULightLeptonFlavorType4D","((RecoVertexN[0])*10000)+LightLeptonFlavorType4D[0]");

	tree->SetAlias("LightLeptonNonFakeType4DA","((((((((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[0],999))),99.))<0.1))*1000+(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[1],999))),99.))<0.1))*100+(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[2],999))),99.))<0.1))*10+(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[3],999))),99.))<0.1)))*(LightLeptonN[0]>3))+((((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[0],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[0],999))),99.))<0.1))==0))*1000+((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[1],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[1],999))),99.))<0.1))==0))*100+((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[2],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[2],999))),99.))<0.1))==0))*10+((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[3],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[3],999))),99.))<0.1))==0)))*(LightLeptonN[0]>3)))*(1>0)))");

	tree->SetAlias("LightLeptonTightType3DA","((((Alt$(MuonIsTight[(LightLeptonNativeIndex[0]*(LightLeptonNativeIndex[0]>=0))],0)==1)*(LightLeptonFlavor[0]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[0]*(LightLeptonNativeIndex[0]>=0))],0.))*(LightLeptonFlavor[0]==1)))*100+(((Alt$(MuonIsTight[(LightLeptonNativeIndex[1]*(LightLeptonNativeIndex[1]>=0))],0)==1)*(LightLeptonFlavor[1]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[1]*(LightLeptonNativeIndex[1]>=0))],0.))*(LightLeptonFlavor[1]==1)))*10+(((Alt$(MuonIsTight[(LightLeptonNativeIndex[2]*(LightLeptonNativeIndex[2]>=0))],0)==1)*(LightLeptonFlavor[2]==2)+(Alt$(ElectronIsTight[(LightLeptonNativeIndex[2]*(LightLeptonNativeIndex[2]>=0))],0.))*(LightLeptonFlavor[2]==1))))");

	tree->SetAlias("PULightLeptonFlavorType3D","((RecoVertexN[0])*1000)+LightLeptonFlavorType3D[0]");

	tree->SetAlias("LightLeptonNonFakeType3DA","((((((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[0],999))),99.))<0.1))*100+(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[1],999))),99.))<0.1))*10+(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[2],999))),99.))<0.1)))*(LightLeptonN[0]==3))+((((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[0],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[0],999))),99.))<0.1))==0))*100+((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[1],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[1],999))),99.))<0.1))==0))*10+((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenPhotonDr[2],999))),99.)<0.1&&(((Alt$(((1>0)*(Alt$(LightLeptonMatchedPromptGenLeptonDr[2],999))),99.))<0.1))==0)))*(LightLeptonN[0]==3)))*(1>0)");

	tree->SetAlias("L4VLL","(LightLeptonN[0]==4&&((PFMETType1[0])>50||((PFMETType1[0])<50&&((LightLeptonN[0]==4)*(((Alt$(LightLeptonDiMassOSSF[0],0))>(91.1876-15.)&&(Alt$(LightLeptonDiMassOSSF[0],0))<(91.1876+15.)&&Alt$(LightLeptonDiMassOSSF[5],0)>(91.1876-15.)&&Alt$(LightLeptonDiMassOSSF[5],0)<(91.1876+15.))||((Alt$(LightLeptonDiMassOSSF[1],0))>(91.1876-15.)&&(Alt$(LightLeptonDiMassOSSF[1],0))<(91.1876+15.)&&Alt$(LightLeptonDiMassOSSF[4],0)>(91.1876-15.)&&Alt$(LightLeptonDiMassOSSF[4],0)<(91.1876+15.))||((Alt$(LightLeptonDiMassOSSF[2],0))>(91.1876-15.)&&(Alt$(LightLeptonDiMassOSSF[2],0))<(91.1876+15.)&&(Alt$(LightLeptonDiMassOSSF[3],0))>(91.1876-15.)&&(Alt$(LightLeptonDiMassOSSF[3],0))<(91.1876+15.))))==0)))");







	tree->SetAlias("JetAbsEta0","(1>0)*(fabs(Alt$(JetEta[0],-3.3)))");
    tree->SetAlias("JetAbsEta1","(1>0)*(fabs(Alt$(JetEta[1],-3.3)))");
    tree->SetAlias("JetAbsEta2","(1>0)*(fabs(Alt$(JetEta[2],-3.3)))");
    tree->SetAlias("JetAbsEta3","(1>0)*(fabs(Alt$(JetEta[3],-3.3)))");
    tree->SetAlias("JetAbsEta4","(1>0)*(fabs(Alt$(JetEta[4],-3.3)))");
    tree->SetAlias("JetAbsEta5","(1>0)*(fabs(Alt$(JetEta[5],-3.3)))");
    tree->SetAlias("JetAbsEta6","(1>0)*(fabs(Alt$(JetEta[6],-3.3)))");
    tree->SetAlias("JetAbsEta7","(1>0)*(fabs(Alt$(JetEta[7],-3.3)))");
    tree->SetAlias("JetAbsEta8","(1>0)*(fabs(Alt$(JetEta[8],-3.3)))");
    tree->SetAlias("JetAbsEta9","(1>0)*(fabs(Alt$(JetEta[9],-3.3)))");
    tree->SetAlias("JetAbsEta10","(1>0)*(fabs(Alt$(JetEta[10],-3.3)))");
    tree->SetAlias("JetAbsEta11","(1>0)*(fabs(Alt$(JetEta[11],-3.3)))");
    tree->SetAlias("JetAbsEta12","(1>0)*(fabs(Alt$(JetEta[12],-3.3)))");
    tree->SetAlias("JetAbsEta13","(1>0)*(fabs(Alt$(JetEta[13],-3.3)))");
    tree->SetAlias("JetAbsEta14","(1>0)*(fabs(Alt$(JetEta[14],-3.3)))");


	tree->SetAlias("JetHadronFlavour0","Alt$(JetHadronFlavour[0],-1)");
    tree->SetAlias("JetHadronFlavour1","Alt$(JetHadronFlavour[1],-1)");
    tree->SetAlias("JetHadronFlavour2","Alt$(JetHadronFlavour[2],-1)");
    tree->SetAlias("JetHadronFlavour3","Alt$(JetHadronFlavour[3],-1)");
    tree->SetAlias("JetHadronFlavour4","Alt$(JetHadronFlavour[4],-1)");
    tree->SetAlias("JetHadronFlavour5","Alt$(JetHadronFlavour[5],-1)");
    tree->SetAlias("JetHadronFlavour6","Alt$(JetHadronFlavour[6],-1)");
    tree->SetAlias("JetHadronFlavour7","Alt$(JetHadronFlavour[7],-1)");
    tree->SetAlias("JetHadronFlavour8","Alt$(JetHadronFlavour[8],-1)");
    tree->SetAlias("JetHadronFlavour9","Alt$(JetHadronFlavour[9],-1)");
    tree->SetAlias("JetHadronFlavour10","Alt$(JetHadronFlavour[10],-1)");
    tree->SetAlias("JetHadronFlavour11","Alt$(JetHadronFlavour[11],-1)");
    tree->SetAlias("JetHadronFlavour12","Alt$(JetHadronFlavour[12],-1)");
    tree->SetAlias("JetHadronFlavour13","Alt$(JetHadronFlavour[13],-1)");
    tree->SetAlias("JetHadronFlavour14","Alt$(JetHadronFlavour[14],-1)");

    tree->SetAlias("JetPt0","Alt$(JetPt[0],0)");
    tree->SetAlias("JetPt1","Alt$(JetPt[1],0)");
    tree->SetAlias("JetPt2","Alt$(JetPt[2],0)");
    tree->SetAlias("JetPt3","Alt$(JetPt[3],0)");
    tree->SetAlias("JetPt4","Alt$(JetPt[4],0)");
    tree->SetAlias("JetPt5","Alt$(JetPt[5],0)");
    tree->SetAlias("JetPt6","Alt$(JetPt[6],0)");
    tree->SetAlias("JetPt7","Alt$(JetPt[7],0)");
    tree->SetAlias("JetPt8","Alt$(JetPt[8],0)");
    tree->SetAlias("JetPt9","Alt$(JetPt[9],0)");
    tree->SetAlias("JetPt10","Alt$(JetPt[10],0)");
    tree->SetAlias("JetPt11","Alt$(JetPt[11],0)");
    tree->SetAlias("JetPt12","Alt$(JetPt[12],0)");
    tree->SetAlias("JetPt13","Alt$(JetPt[13],0)");
    tree->SetAlias("JetPt14","Alt$(JetPt[14],0)");

	 tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF0","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[0],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF1","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[1],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF2","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[2],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF3","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[3],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF4","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[4],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF5","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[5],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF6","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[6],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF7","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[7],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF8","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[8],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF9","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[9],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF10","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[10],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF11","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[11],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF12","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[12],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF13","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[13],0)");
    tree->SetAlias("JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF14","Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSFc[14],0)");

	tree->SetAlias("JetIsMediumBtag0","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[0],-1)>0.8484)*(fabs(Alt$(JetEta[0],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[0],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag1","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[1],-1)>0.8484)*(fabs(Alt$(JetEta[1],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[1],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag2","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[2],-1)>0.8484)*(fabs(Alt$(JetEta[2],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[2],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag3","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[3],-1)>0.8484)*(fabs(Alt$(JetEta[3],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[3],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag4","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[4],-1)>0.8484)*(fabs(Alt$(JetEta[4],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[4],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag5","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[5],-1)>0.8484)*(fabs(Alt$(JetEta[5],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[5],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag6","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[6],-1)>0.8484)*(fabs(Alt$(JetEta[6],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[6],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag7","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[7],-1)>0.8484)*(fabs(Alt$(JetEta[7],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[7],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag8","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[8],-1)>0.8484)*(fabs(Alt$(JetEta[8],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[8],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag9","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[9],-1)>0.8484)*(fabs(Alt$(JetEta[9],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[9],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag10","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[10],-1)>0.8484)*(fabs(Alt$(JetEta[10],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[10],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag11","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[11],-1)>0.8484)*(fabs(Alt$(JetEta[11],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[11],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag12","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[12],-1)>0.8484)*(fabs(Alt$(JetEta[12],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[12],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag13","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[13],-1)>0.8484)*(fabs(Alt$(JetEta[13],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[13],-1)==-1)");
    tree->SetAlias("JetIsMediumBtag14","(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[14],-1)>0.8484)*(fabs(Alt$(JetEta[14],-3.3))<2.4)-(Alt$(JetCombinedInclusiveSecondaryVertexV2BJetTags[14],-1)==-1)");
    
	tree->SetAlias("DataBTagProbabilityDYJet0","(1>0)*(dataBTagProbability(JetIsMediumBtag0,JetHadronFlavour0,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF0,JetPt0,JetAbsEta0,1))");
    tree->SetAlias("DataBTagProbabilityDYJet1","(1>0)*(dataBTagProbability(JetIsMediumBtag1,JetHadronFlavour1,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF1,JetPt1,JetAbsEta1,1))");
    tree->SetAlias("DataBTagProbabilityDYJet2","(1>0)*(dataBTagProbability(JetIsMediumBtag2,JetHadronFlavour2,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF2,JetPt2,JetAbsEta2,1))");
    tree->SetAlias("DataBTagProbabilityDYJet3","(1>0)*(dataBTagProbability(JetIsMediumBtag3,JetHadronFlavour3,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF3,JetPt3,JetAbsEta3,1))");
    tree->SetAlias("DataBTagProbabilityDYJet4","(1>0)*(dataBTagProbability(JetIsMediumBtag4,JetHadronFlavour4,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF4,JetPt4,JetAbsEta4,1))");
    tree->SetAlias("DataBTagProbabilityDYJet5","(1>0)*(dataBTagProbability(JetIsMediumBtag5,JetHadronFlavour5,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF5,JetPt5,JetAbsEta5,1))");
    tree->SetAlias("DataBTagProbabilityDYJet6","(1>0)*(dataBTagProbability(JetIsMediumBtag6,JetHadronFlavour6,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF6,JetPt6,JetAbsEta6,1))");
    tree->SetAlias("DataBTagProbabilityDYJet7","(1>0)*(dataBTagProbability(JetIsMediumBtag7,JetHadronFlavour7,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF7,JetPt7,JetAbsEta7,1))");
    tree->SetAlias("DataBTagProbabilityDYJet8","(1>0)*(dataBTagProbability(JetIsMediumBtag8,JetHadronFlavour8,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF8,JetPt8,JetAbsEta8,1))");
    tree->SetAlias("DataBTagProbabilityDYJet9","(1>0)*(dataBTagProbability(JetIsMediumBtag9,JetHadronFlavour9,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF9,JetPt9,JetAbsEta9,1))");
    tree->SetAlias("DataBTagProbabilityDYJet10","(1>0)*(dataBTagProbability(JetIsMediumBtag10,JetHadronFlavour10,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF10,JetPt10,JetAbsEta10,1))");
    tree->SetAlias("DataBTagProbabilityDYJet11","(1>0)*(dataBTagProbability(JetIsMediumBtag11,JetHadronFlavour11,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF11,JetPt11,JetAbsEta11,1))");
    tree->SetAlias("DataBTagProbabilityDYJet12","(1>0)*(dataBTagProbability(JetIsMediumBtag12,JetHadronFlavour12,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF12,JetPt12,JetAbsEta12,1))");
    tree->SetAlias("DataBTagProbabilityDYJet13","(1>0)*(dataBTagProbability(JetIsMediumBtag13,JetHadronFlavour13,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF13,JetPt13,JetAbsEta13,1))");
    tree->SetAlias("DataBTagProbabilityDYJet14","(1>0)*(dataBTagProbability(JetIsMediumBtag14,JetHadronFlavour14,JetCombinedInclusiveSecondaryVertexV2BJetTagsMediumSF14,JetPt14,JetAbsEta14,1))");
	
    tree->SetAlias("MCBTagProbabilityDYJet0","(1>0)*(mcBTagProbability(JetIsMediumBtag0,JetHadronFlavour0,JetPt0,JetAbsEta0,1))");
    tree->SetAlias("MCBTagProbabilityDYJet1","(1>0)*(mcBTagProbability(JetIsMediumBtag1,JetHadronFlavour1,JetPt1,JetAbsEta1,1))");
    tree->SetAlias("MCBTagProbabilityDYJet2","(1>0)*(mcBTagProbability(JetIsMediumBtag2,JetHadronFlavour2,JetPt2,JetAbsEta2,1))");
    tree->SetAlias("MCBTagProbabilityDYJet3","(1>0)*(mcBTagProbability(JetIsMediumBtag3,JetHadronFlavour3,JetPt3,JetAbsEta3,1))");
    tree->SetAlias("MCBTagProbabilityDYJet4","(1>0)*(mcBTagProbability(JetIsMediumBtag4,JetHadronFlavour4,JetPt4,JetAbsEta4,1))");
    tree->SetAlias("MCBTagProbabilityDYJet5","(1>0)*(mcBTagProbability(JetIsMediumBtag5,JetHadronFlavour5,JetPt5,JetAbsEta5,1))");
    tree->SetAlias("MCBTagProbabilityDYJet6","(1>0)*(mcBTagProbability(JetIsMediumBtag6,JetHadronFlavour6,JetPt6,JetAbsEta6,1))");
    tree->SetAlias("MCBTagProbabilityDYJet7","(1>0)*(mcBTagProbability(JetIsMediumBtag7,JetHadronFlavour7,JetPt7,JetAbsEta7,1))");
    tree->SetAlias("MCBTagProbabilityDYJet8","(1>0)*(mcBTagProbability(JetIsMediumBtag8,JetHadronFlavour8,JetPt8,JetAbsEta8,1))");
    tree->SetAlias("MCBTagProbabilityDYJet9","(1>0)*(mcBTagProbability(JetIsMediumBtag9,JetHadronFlavour9,JetPt9,JetAbsEta9,1))");
    tree->SetAlias("MCBTagProbabilityDYJet10","(1>0)*(mcBTagProbability(JetIsMediumBtag10,JetHadronFlavour10,JetPt10,JetAbsEta10,1))");
    tree->SetAlias("MCBTagProbabilityDYJet11","(1>0)*(mcBTagProbability(JetIsMediumBtag11,JetHadronFlavour11,JetPt11,JetAbsEta11,1))");
    tree->SetAlias("MCBTagProbabilityDYJet12","(1>0)*(mcBTagProbability(JetIsMediumBtag12,JetHadronFlavour12,JetPt12,JetAbsEta12,1))");
    tree->SetAlias("MCBTagProbabilityDYJet13","(1>0)*(mcBTagProbability(JetIsMediumBtag13,JetHadronFlavour13,JetPt13,JetAbsEta13,1))");
    tree->SetAlias("MCBTagProbabilityDYJet14","(1>0)*(mcBTagProbability(JetIsMediumBtag14,JetHadronFlavour14,JetPt14,JetAbsEta14,1))");

	
    tree->SetAlias("eventMCTotalBTagProbabilityDY","(1>0)*(MCBTagProbabilityDYJet0*MCBTagProbabilityDYJet1*MCBTagProbabilityDYJet2*MCBTagProbabilityDYJet3*MCBTagProbabilityDYJet4*MCBTagProbabilityDYJet5*MCBTagProbabilityDYJet6*MCBTagProbabilityDYJet7*MCBTagProbabilityDYJet8*MCBTagProbabilityDYJet9*MCBTagProbabilityDYJet10*MCBTagProbabilityDYJet11*MCBTagProbabilityDYJet12*MCBTagProbabilityDYJet13*MCBTagProbabilityDYJet14)");


	tree->SetAlias("eventDataTotalBTagProbabilityDY","(1>0)*(DataBTagProbabilityDYJet0*DataBTagProbabilityDYJet1*DataBTagProbabilityDYJet2*DataBTagProbabilityDYJet3*DataBTagProbabilityDYJet4*DataBTagProbabilityDYJet5*DataBTagProbabilityDYJet6*DataBTagProbabilityDYJet7*DataBTagProbabilityDYJet8*DataBTagProbabilityDYJet9*DataBTagProbabilityDYJet10*DataBTagProbabilityDYJet11*DataBTagProbabilityDYJet12*DataBTagProbabilityDYJet13*DataBTagProbabilityDYJet14)");
	
	tree->SetAlias("eventBTagSFDY","(1>0)*(finalBTagSF((eventDataTotalBTagProbabilityDY),eventMCTotalBTagProbabilityDY))");
    


	
	

}