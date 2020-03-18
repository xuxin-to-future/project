#!/bin/bash
i=0
while [[ $i -lt 100 ]];do
    echo $i
    i=$[ ${i} + 1]
    #let i=i+1
done
