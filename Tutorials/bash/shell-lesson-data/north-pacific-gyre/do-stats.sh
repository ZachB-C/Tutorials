# Calculates stats for data files
# Usage: bash do-stats.sh FILENAME_LIST
for datafile in "$@"
do 
	echo $datafile
	bash goostats.sh $datafile stats-$datafile
done
