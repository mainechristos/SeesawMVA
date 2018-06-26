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
mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds 
echo $1
echo $2
mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds/$1
cd /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds/$1
cp /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/makeSkims_pyPlotter.C /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds/$1/makeSkims_pyPlotter.C
sed -i "s/QQQ/$1/g;" /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds/$1/makeSkims_pyPlotter.C
sed -i "s/VVV/$2/g;" /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds/$1/makeSkims_pyPlotter.C
root -l -q /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/pyPlotter/Backgrounds/$1/makeSkims_pyPlotter.C