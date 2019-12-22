#!/bin/bash


teamlist=`gawk 'BEGIN{FS=","}{print $2}' scores.txt | uniq`

for team in $teamlist
do
    gawk -v team=$team 'BEGIN{FS=","}
    $2 == team{
            total = total + $3 + $4 + $5
            n = n + 3
    }
    END{
        print total, total/n
    }' scores.txt
done