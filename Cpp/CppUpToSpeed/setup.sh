#! /bin/echo "You should be sourcing this file."
#
# You must source this script
#

# The version of GCC setup here should be the same as that used by the
# version of toyExperiment we're using for the Workbook.
setup -B gcc v4_9_2

# Define environment variables that will be used by the exercises under Build
export PACKAGE1_INC=$(pwd)/Libraries/packages/package1
export PACKAGE1_LIB=$(pwd)/Libraries/packages/package1/lib
