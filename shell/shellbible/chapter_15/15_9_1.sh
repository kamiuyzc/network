#!/bin/bash
output="output.txt"
input=~/Info/enviroment/device.csv
rm -rf $output
IFS=',' 
while read -r id address username password
do
	cat >> $output << EOF
ssh $username@$address
EOF
done < $input





