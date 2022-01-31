#!/bin/sh

../app.exe  neg_${1}_in.txt out.txt
echo "NEG ${1}"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum neg_${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi

rm out.txt