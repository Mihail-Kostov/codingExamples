#!/bin/bash

# Connect to different ssh addresses

run(){
  COLOR='\033[1;33m'
  DEFAULT='\033[0m'
  echo -e "${COLOR}-> ${1}${DEFAULT}";
  eval ${1};
}

case ${1} in
  "uboone")
	if [ -z "$2" ]; then
		run "ssh -X -Y sporzio@uboonegpvm05.fnal.gov"
	else
		run "ssh -X -Y sporzio@uboonegpvm0${2}.fnal.gov"
	fi ;;
  "uboonebuild")
	run "ssh -X -Y sporzio@uboonebuild01.fnal.gov" ;;
  "manchester")   	
	run "ssh -X -Y davide@higgs.hep.manchester.ac.uk" ;;
  "database")     	
	run "ssh -X -Y uboonedb@ppdhcp120.hep.manchester.ac.uk" ;;
  "database_socket")
	run "ssh -L 8080:127.0.0.1:5432 uboonedb@ppdhcp120.hep.manchester.ac.uk" ;;
  *)
	run "ssh -X -Y davide@${1}.hep.manchester.ac.uk" ;;
esac
