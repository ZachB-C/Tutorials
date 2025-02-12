# Returns two lines of the file from the top and from the bottom
# Usage: script.sh FILE N_FROM_HEAD N_FROM_TAIL
head -n $2 $1
tail -n $3 $1
