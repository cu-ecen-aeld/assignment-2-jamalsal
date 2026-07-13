
#!/bin/bash

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ] || [ -z "$searchstr" ]
then
   echo "Error: Parameters were not specified"
   exit 1

elif [ ! -d "$filesdir" ]
then
    echo "Error: $filesdir does not repesent a directory on the filesystem"
    exit 1
fi

noFiles=$(find "$filesdir" -type f | wc -l)
noMatches=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are $noFiles and the number of matching lines are $noMatches"
exit 0

