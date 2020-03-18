#!/bin/bash

declare -a prime
END=1000

for (( i=2; i<${END}; i++ ));do
    if [[ ${prime[$i]}x == x ]];then
        prime[0]=$[ ${prime[0]} + 1 ]
        prime[${prime[0]}]=$i
        Sum=$[ ${Sum} + $i ]
    fi

    for (( j=1; j<=${prime[0]}; j++ ));do
        if [[ $[ $i * ${prime[$j]} ] -gt ${END} ]];then
            break
        fi
        prime[$[ $i * ${prime[$j]} ]]=1
        if [[ $[ $i % ${prime[$j]} ] -eq 0 ]];then
            break
        fi
    done

done

echo ${Sum}
