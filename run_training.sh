#!/bin/bash
# reads signal input file and generates new file with BDT variable
#mkdir /cms/mchristos/ANN/Seesaw/2016/92X/outFiles/SeesawTMVAClassificationApplication$1/Background
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
export COIN_FULL_INDIRECT_RENDERING=1
echo $VO_CMS_SW_DIR
source $VO_CMS_SW_DIR/cmsset_default.sh
cd /cms/mchristos/software/CMSSW_9_3_2/src 
export SCRAM_ARCH=slc6_amd64_gcc493
export DISPLAY=localhost:0.0
eval `scramv1 runtime -sh`
cd /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims
root -l -b -q /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/Seesaw_Training_3L.C > depth.txt
