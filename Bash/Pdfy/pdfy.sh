#! /bin/bash

# pdfy converts directories containing images into pdf books
# sdporzio


############
# Function #
############

function_pdfy(){
  rm -rf PdfBooks
  mkdir PdfBooks

  for book in $( find ${dirOpt} -type d ); do
    if [ ${book} != "${dirOpt}/PdfBooks" ] && [ ${book} != '.' ]; then
      echo -e "\nConverting directory: ${book}"
      convert ${book}/*.${formatOpt} PdfBooks/${book}.pdf
      echo "...done"
    fi
  # for pngfile in ${dir}/*.jpg
  # do convert "${pngfile}" "BOOKS/${D}.pdf"
  #   echo "Done"
    # do :
    # for shit in ${pngfile}
    #   do echo "     ${shit}"
    # done
  # done
  done
}



##########################
# Wrapping and execution #
##########################

# Default arguments
verboseFlag='false'
helpFlag='false'
formatOpt='jpg'
dirOpt='false'

# Take in options
while [[ $* ]]
do
    OPTIND=1
    # echo $1
    if [[ $1 =~ ^- ]]
    then
        getopts vhf: parameter
        case $parameter in
            v)  verboseFlag='true'
                echo -e '-> Verbose mode'
                ;;
            h)  helpFlag='true'
                echo -e "-> Help mode"
                ;;
            f)  formatOpt=${OPTARG}
                echo -e "-> Specified input format: ${formatOpt}"
                shift
                ;;
            *) echo -e "This is an invalid argument: $parameter" ;;
        esac
    else
        dirOpt=${1}
    fi
    shift
done


# Check if mandatory variables have been provided
# If not, complain and send to help documentation
if [ ${helpFlag} == false ] && [ ${dirOpt} == false ]; then
  echo
  echo -e "ERROR: \033[4m\033[1mInput directory not provided \033[0m"
  helpFlag='true'
fi

# Either print help or execute function
if [ ${helpFlag} == true ]; then
    echo -e "\n\033[1m${0}\033[0m converts directories containing images into pdf books"
    echo -e "\n\033[1mUsage:\033[0m ${0} [ -vhf ] [ \033[4mdirectory\033[0m ]"
    echo -e "* \033[1m-v\033[0m: Help mode"
    echo -e "* \033[1m-v\033[0m: Verbose mode"
    echo -e "* \033[1m-f\033[0m: Input format of the individual files (default: 'jpg')"
    echo -e "* \033[1mdirectory\033[0m: Mother directory containing the directories to pdfy"
    echo
else
  function_pdfy
  echo -e "\nEnd of script"
fi
