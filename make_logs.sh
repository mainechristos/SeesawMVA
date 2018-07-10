#!/bin/bash
# reads signal input file and generates new file with BDT variable
#mkdir /cms/mchristos/ANN/Seesaw/2016/outFiles/SeesawTMVAClassificationApplication$1/Signal
while read p 
do
  echo $p
  mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/$p
  mkdir /cms/mchristos/ANN/Seesaw/2016/92X/TMVAskims/outFiles/Seesaw_Application_1/Background/$p/logs/
done </cms/mchristos/ANN/Seesaw/2016/92X/backgrounds.txt
