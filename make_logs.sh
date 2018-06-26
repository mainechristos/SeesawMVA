#!/bin/bash
# reads signal input file and generates new file with BDT variable
#mkdir /cms/mchristos/ANN/Seesaw/2016/outFiles/SeesawTMVAClassificationApplication$1/Signal
while read p 
do
  echo $p
  mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_$1/SingleElectron/$p
  mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_$1/SingleElectron/$p/logs/
done </cms/mchristos/ANN/Seesaw/2016/92X/data.txt
