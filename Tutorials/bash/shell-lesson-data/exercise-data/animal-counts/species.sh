# Prints a list of the unique species from csv databases where species is the second entry
# Script to find unique species in csv files where the specieis is the second data field
# This script accepts any number of ifle names as commande line arguments
for file in $@
do
	echo "Unique species in $file:"
	# Extract species names
	cut -d, -f 2 $file | sort | uniq
done

# Usage: bash species.sh filenames
#cut -d, -f 2 "$@" | sort | uniq
