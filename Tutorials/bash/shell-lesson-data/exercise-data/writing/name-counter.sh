# Counts the number of occurences of each of a list of inputs in a given file and returns a file name-counts with each
# of the inputs and how many times it occurs. The name list must be given in quotes to the input.
# usage: name-counter.sh  FILENAME NAMELIST
rm -f name-counts.txt
for name in $2
do
	echo -n -e "$name":'\t' >> name-counts.txt
	grep -iow "$name" $1 | wc -l >> name-counts.txt
done
cat name-counts.txt
