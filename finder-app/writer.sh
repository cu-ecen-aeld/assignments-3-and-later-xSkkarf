#!/bin/bash

writeFileDir="$1"
writeStr="$2"

#Remove the file basename from the directory path
writeDir=${writeFileDir%/*}/

# Check that the user entered exactly 2 arguments
if [ $# -ne 2 ]; then
    echo "Incorrect number of arguments. Your command should looklike something like this:"
    echo "$0 /path/to/write/directory your_write_string"
    exit 1
fi

# Check whether or not the directory the user entered exists 
if [ ! -d $writeDir ]; then
    echo "Unable to find directory: $writeDir"
    exit 1
fi

#Make the path of the desired directory
mkdir -p $writeDir

#Create the file
touch $(basename $writeDir)

#Overwriting the file data with our new data
echo $writeStr > $writeFileDir