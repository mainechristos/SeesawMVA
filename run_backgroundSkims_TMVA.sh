#!/bin/bash
# reads signal input file and generates new file with BDT variable
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
export COIN_FULL_INDIRECT_RENDERING=1
echo $VO_CMS_SW_DIR
source $VO_CMS_SW_DIR/cmsset_default.sh
cd /users/h2/mchristos/software/CMSSW_7_6_3_patch2
export SCRAM_ARCH=slc6_amd64_gcc493
export DISPLAY=localhost:0.0
eval `scramv1 runtime -sh`
mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds 
echo $1
echo $2
echo $3
mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1
cd /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1
cp /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/makeSkims_TMVA.C /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1/makeSkims_TMVA.C
sed -i "s/QQQ/$1/g;" /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1/makeSkims_TMVA.C
sed -i "s/VVV/$2/g;" /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1/makeSkims_TMVA.C
sed -i "s/RRR/$3/g;" /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1/makeSkims_TMVA.C
root -l -q /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/TMVA/Backgrounds/$1/makeSkims_TMVA.C