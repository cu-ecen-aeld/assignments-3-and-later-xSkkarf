#!/bin/bash

filesDir="$1"
searchStr="$2"

# Check that the user entered exactly 2 arguments
if [ $# -ne 2 ]; then
    echo "Incorrect number of arguments. Your command should looklike something like this:"
    echo "$0 /path/to/search/directory your_search_string"
    exit 1
fi

# Check whether or not the directory the user entered exists 
if [ ! -d $filesDir ]; then
    echo "Unable to find directory: $filesDir"
    exit 1
fi

#Number of matching files (repeated occurenses not included)
X=$(find $filesDir -type f -exec grep -l $searchStr {} + | wc -l)

#Number of matching lines (repeated occurenses included)
Y=$(grep -r $searchStr $filesDir | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"