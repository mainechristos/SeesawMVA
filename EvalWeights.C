float makeLightLeptonTightType3DA( TTreeReaderValue<vector<Int_t>> &inMuonIsTight, TTreeReaderValue<vector<Int_t>>  &inElectronIsTight, int LightLeptonFlavor0, int  LightLeptonFlavor1,  int LightLeptonFlavor2, int  LightLeptonNativeIndex0, int  LightLeptonNativeIndex1, int  LightLeptonNativeIndex2){
	
	float type = 0.0;
	int MuonIsTight0 = 0;
	int ElectronIsTight0 = 0;
	int MuonIsTight1 = 0;
	int ElectronIsTight1 = 0;
	int MuonIsTight2 = 0;
	int ElectronIsTight2 = 0;
	
	if( (LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)) >= inMuonIsTight->size()){
		MuonIsTight0 = 0;
	}else{
		MuonIsTight0 = inMuonIsTight->at((LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)));
	}
	if( (LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)) >= inMuonIsTight->size()){
		MuonIsTight1 = 0;
	}else{
		MuonIsTight1 = inMuonIsTight->at((LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)));
	}
	if( (LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)) >= inMuonIsTight->size()){
		MuonIsTight2 = 0;
	}else{
		MuonIsTight2 = inMuonIsTight->at((LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)));
	}

	if( (LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)) >= inElectronIsTight->size()){
		ElectronIsTight0 = 0;
	}else{
		ElectronIsTight0 = inElectronIsTight->at((LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)));
	}
	if( (LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)) >= inElectronIsTight->size()){
		ElectronIsTight1 = 0;
	}else{
		ElectronIsTight1 = inElectronIsTight->at((LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)));
	}
	if( (LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)) >= inElectronIsTight->size()){
		ElectronIsTight2 = 0;
	}else{
		ElectronIsTight2 = inElectronIsTight->at((LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)));
	}

	type = ((((MuonIsTight0==1)*(LightLeptonFlavor0==2)+(ElectronIsTight0)*(LightLeptonFlavor0==1)))*100+(((MuonIsTight1==1)*(LightLeptonFlavor1==2)+(ElectronIsTight1)*(LightLeptonFlavor1==1)))*10+(((MuonIsTight2==1)*(LightLeptonFlavor2==2)+(ElectronIsTight2)*(LightLeptonFlavor2==1))));

	return type;
}
float makePULightLeptonFlavorType3D(int RecoVertexN, int LightLeptonFlavorType3D){
	float type = 0.0;
	type = ((RecoVertexN)*1000)+LightLeptonFlavorType3D;
	return type;
}
float makeLightLeptonNonFakeType3DA(float LightLeptonMatchedPromptGenLeptonDr0,float LightLeptonMatchedPromptGenLeptonDr1, float LightLeptonMatchedPromptGenLeptonDr2, int LightLeptonN, float LightLeptonMatchedPromptGenPhotonDr0, float LightLeptonMatchedPromptGenPhotonDr1, float LightLeptonMatchedPromptGenPhotonDr2){
	float type = 0.0;
	type = ((((((LightLeptonMatchedPromptGenLeptonDr0)<0.1))*100+(((LightLeptonMatchedPromptGenLeptonDr1)<0.1))*10+(((LightLeptonMatchedPromptGenLeptonDr2)<0.1)))*(LightLeptonN==3))+((((LightLeptonMatchedPromptGenPhotonDr0<0.1&&(((LightLeptonMatchedPromptGenLeptonDr0)<0.1))==0))*100+((LightLeptonMatchedPromptGenPhotonDr1<0.1&&(((LightLeptonMatchedPromptGenLeptonDr1)<0.1))==0))*10+((LightLeptonMatchedPromptGenPhotonDr2<0.1&&(((LightLeptonMatchedPromptGenLeptonDr2)<0.1))==0)))*(LightLeptonN==3)));
	return type;
}
float makeLightLeptonTightType4DA( TTreeReaderValue<vector<Int_t>> &inMuonIsTight, TTreeReaderValue<vector<Int_t>>  &inElectronIsTight, int LightLeptonFlavor0, int  LightLeptonFlavor1,  int LightLeptonFlavor2, int LightLeptonFlavor3, int  LightLeptonNativeIndex0, int  LightLeptonNativeIndex1, int  LightLeptonNativeIndex2, int  LightLeptonNativeIndex3){
	float type = 0.0;

	int MuonIsTight0 = 0;
	int ElectronIsTight0 = 0;
	int MuonIsTight1 = 0;
	int ElectronIsTight1 = 0;
	int MuonIsTight2 = 0;
	int ElectronIsTight2 = 0;
	int MuonIsTight3 = 0;
	int ElectronIsTight3 = 0;
	
	if( (LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)) >= inMuonIsTight->size()){
		MuonIsTight0 = 0;
	}else{
		MuonIsTight0 = inMuonIsTight->at((LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)));
	}
	if( (LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)) >= inMuonIsTight->size()){
		MuonIsTight1 = 0;
	}else{
		MuonIsTight1 = inMuonIsTight->at((LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)));
	}
	if( (LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)) >= inMuonIsTight->size()){
		MuonIsTight2 = 0;
	}else{
		MuonIsTight2 = inMuonIsTight->at((LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)));
	}
	if( (LightLeptonNativeIndex3*(LightLeptonNativeIndex3>=0)) >= inMuonIsTight->size()){
		MuonIsTight3 = 0;
	}else{
		MuonIsTight3 = inMuonIsTight->at((LightLeptonNativeIndex3*(LightLeptonNativeIndex3>=0)));
	}

	if( (LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)) >= inElectronIsTight->size()){
		ElectronIsTight0 = 0;
	}else{
		ElectronIsTight0 = inElectronIsTight->at((LightLeptonNativeIndex0*(LightLeptonNativeIndex0>=0)));
	}
	if( (LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)) >= inElectronIsTight->size()){
		ElectronIsTight1 = 0;
	}else{
		ElectronIsTight1 = inElectronIsTight->at((LightLeptonNativeIndex1*(LightLeptonNativeIndex1>=0)));
	}
	if( (LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)) >= inElectronIsTight->size()){
		ElectronIsTight2 = 0;
	}else{
		ElectronIsTight2 = inElectronIsTight->at((LightLeptonNativeIndex2*(LightLeptonNativeIndex2>=0)));
	}
	if( (LightLeptonNativeIndex3*(LightLeptonNativeIndex3>=0)) >= inElectronIsTight->size()){
		ElectronIsTight3 = 0;
	}else{
		ElectronIsTight3 = inElectronIsTight->at((LightLeptonNativeIndex3*(LightLeptonNativeIndex3>=0)));
	}
	
	type = ((((((MuonIsTight0==1)*(LightLeptonFlavor0==2)+(ElectronIsTight0)*(LightLeptonFlavor0==1)))*1000+(((MuonIsTight1==1)*(LightLeptonFlavor1==2)+(ElectronIsTight1)*(LightLeptonFlavor1==1)))*100+(((MuonIsTight2==1)*(LightLeptonFlavor2==2)+(ElectronIsTight2)*(LightLeptonFlavor2==1)))*10+(((MuonIsTight3==1)*(LightLeptonFlavor3==2)+(ElectronIsTight3)*(LightLeptonFlavor3==1))))));
	
	return type;
}
float makePULightLeptonFlavorType4D(int RecoVertexN, int LightLeptonFlavorType4D){
	float type = 0.0;
	type = ((RecoVertexN)*10000)+LightLeptonFlavorType4D;
	return type;
}
float makeLightLeptonNonFakeType4DA(float LightLeptonMatchedPromptGenLeptonDr0,float LightLeptonMatchedPromptGenLeptonDr1, float LightLeptonMatchedPromptGenLeptonDr2, float LightLeptonMatchedPromptGenLeptonDr3, int LightLeptonN, float LightLeptonMatchedPromptGenPhotonDr0, float LightLeptonMatchedPromptGenPhotonDr1, float LightLeptonMatchedPromptGenPhotonDr2, float LightLeptonMatchedPromptGenPhotonDr3){
	float type = 0.0;
	type = ((((((((LightLeptonMatchedPromptGenLeptonDr0)<0.1))*1000+(((LightLeptonMatchedPromptGenLeptonDr1)<0.1))*100+(((LightLeptonMatchedPromptGenLeptonDr2)<0.1))*10+(((LightLeptonMatchedPromptGenLeptonDr3)<0.1)))*(LightLeptonN>3))+((((LightLeptonMatchedPromptGenPhotonDr0<0.1&&(((LightLeptonMatchedPromptGenLeptonDr0)<0.1))==0))*1000+((LightLeptonMatchedPromptGenPhotonDr1<0.1&&(((LightLeptonMatchedPromptGenLeptonDr1)<0.1))==0))*100+((LightLeptonMatchedPromptGenPhotonDr2<0.1&&(((LightLeptonMatchedPromptGenLeptonDr2)<0.1))==0))*10+((LightLeptonMatchedPromptGenPhotonDr3<0.1&&(((LightLeptonMatchedPromptGenLeptonDr3)<0.1))==0)))*(LightLeptonN>3)))));
	return type;
}