# Searches a directory for all instances of a given species and returns a file whose title is the name of the species (.txt) and which contains a list of dates and how many of instance of that animal species were seen
# Usage: bash species_tracker.sh SPECIES DIRECTORY
grep -r -h -E [0-9]{4}-[0-9]{2}-[0-9]{2},"$1",[0-9]+ "$2" | cut -d , -f1,3 > "$1".txt
# grep -w $1 -r $2 | cut -d : -f 2 | cut -d , -f 1,3 > $1.txt
