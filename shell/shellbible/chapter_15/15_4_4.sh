#!/bin/bash

exec 3<> 1.txt 

read line <&3 
echo $line
echo "modify second" >&3



