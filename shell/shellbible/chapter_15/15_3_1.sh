#!/bin/bash
sleep 10
echo 'exec'
exec 0< read.csv

sleep 10
while read line
do
	echo $line
done

