#!/bin/bash

# Connect to different ssh addresses

case ${1} in
  "uboone")       echo "> ssh -X -Y sporzio@uboonegpvm01.fnal.gov"
                  ssh -X -Y sporzio@uboonegpvm01.fnal.gov ;;
  "manchester")   echo "> ssh -X -Y davide@higgs.hep.manchester.ac.uk"
                  ssh -X -Y davide@higgs.hep.manchester.ac.uk ;;
  "database")     echo "> ssh -X -Y uboonedb@ppdhcp120.hep.manchester.ac.uk"
                  ssh -X -Y uboonedb@ppdhcp120.hep.manchester.ac.uk ;;
  "cambridge")    echo "> ssh -X -Y uboone04@pclv.hep.phy.cam.ac.uk"
                  ssh -X -Y uboone04@pclv.hep.phy.cam.ac.uk ;;
  *)              echo "> ssh -X -Y davide@${1}.hep.manchester.ac.uk"
                  ssh -X -Y davide@${1}.hep.manchester.ac.uk ;;
esac
