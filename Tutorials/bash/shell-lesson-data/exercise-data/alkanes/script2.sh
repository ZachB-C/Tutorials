# Script 2: Writes the contents of the first three files when given a list of files
for filename in $1 $2 $3
do 
	cat $filename
done

