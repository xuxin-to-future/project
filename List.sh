#!/bin/bash

if [[ $# -ne 1 ]];then
    echo "usage: bash List num"
    exit
fi

cnt=$1;
names=(`cat names`)
function rand(){
    min=1
    max=${#names[*]}
    num=`cat /dev/random | head -n 10 | cksum | cut -d ' ' -f 1`
    echo $[ $num % $max + $min ]
}
for i in `seq 1 $cnt`;do
    randnum=`rand`
    echo "${names[${randnum}]}"
done

