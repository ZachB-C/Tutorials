# Prints the name of the file with the most lines in a given directory with a given extension
# Usage: longest.sh DIRECTORY EXTENSION
#
# We need to remove the total at the bottom of the word count data
# wc -l "$1"/*."$2" | sort -n | tail -n 2 | head -n 1 | tr -s ' ' | cut -d ' ' -f 3- | awk -F / '{print $NF}' 

wc -l "$1"/*."$2" | sort -n | tail -n 2 | head -n 1 | tr -s ' ' | cut -d ' ' -f 3- | awk -F / '{print $NF}' | rev | cut -d . -f 2- | rev
