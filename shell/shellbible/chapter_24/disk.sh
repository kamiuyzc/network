#!/bin/bash

dir_list="/var/log /home"

exec 1> /root/1.txt
for dir in $dir_list
do
    echo $dir
    du -S $dir | sort -rn | sed '11,$d;=' | sed 'N;s/\n/ /' |  gawk '{print $1,$2,$3}'
done