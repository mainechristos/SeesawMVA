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
cd -
mkdir TMVA/Backgrounds 
echo $1
echo $2
echo $3
mkdir TMVA/Backgrounds/$1
cp makeSkims_TMVA.C TMVA/Backgrounds/$1/makeSkims_TMVA.C
sed -i "s/QQQ/$1/g;" TMVA/Backgrounds/$1/makeSkims_TMVA.C
sed -i "s/VVV/$2/g;" TMVA/Backgrounds/$1/makeSkims_TMVA.C
sed -i "s/RRR/$3/g;" TMVA/Backgrounds/$1/makeSkims_TMVA.C
root -l -q TMVA/Backgrounds/$1/makeSkims_TMVA.C