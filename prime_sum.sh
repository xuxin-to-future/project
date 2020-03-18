#!/bin/bash

#num=(`cat day.txt`)
num=()
su=0
maxn=1000

for (( i=2; i<=1000; i++));
do
    if [[ ${num[i]} -eq 0 ]];then
        num[0]=$((${num[0]}+1))
        num[${num[0]}]=$i
        su=$((${su}+$i))
    fi

    for (( j=1; j<=${num[0]}; j++));
    do
        if [[ ${num[j]}*${i} -ge ${maxn} ]];
        then
            break;
        fi
        let val=${num[j]}*${i}
        num[val]=1
        if [[ $i%${num[j]} -eq 0 ]];
        then
            break;
        fi
    done
done

echo ${su}
