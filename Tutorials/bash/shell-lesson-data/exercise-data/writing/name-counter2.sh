# Counts the number of occurences of each of a list of inputs in a given file and returns a file name-counts with each
# of the inputs and how many times it occurs. The name list must be given in quotes to the input.
# usage: name-counter.sh  FILENAME NAMELIST
# This version doesn't work as two of the same name on the same line will be counted only once the other version should
# deal correctly with these things if we use -o but not -c
for name in $2
do
	echo -n -e "$name":'\t'
	grep -o -w -c "$name" $1 
done
