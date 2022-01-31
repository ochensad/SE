#!/bin/sh

../app.exe pos_${1}_in.txt out.txt
echo "POS ${1}"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum pos_${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
	echo "[FAILED]"
fi

rm out.txt