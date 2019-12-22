#!/bin/bash

exec 3<&0
exec 0< read.csv

while read line
do
	echo $line
done

exec 0<&3

read line
echo $line
