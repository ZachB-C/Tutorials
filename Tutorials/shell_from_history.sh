# This script takes the last few (second argument) entries from the history and makes them into a shell script
# with the specified name (first argument). It strips off the indexing numbers from the history output so that 
# the shell script should work 'out of the box'.
# Usage: . shell_from_history.sh SCRIPTNAME N_ENTRIES
echo "$2"
echo "$1"
history | tail -n $(("$2"+1)) | head -n "$2" | tr -s ' ' | cut -d ' ' -f 3- > "$1"
