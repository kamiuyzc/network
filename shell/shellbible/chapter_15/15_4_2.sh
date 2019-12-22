#!/bin/bash


exec 3>&1
exec 1> output.txt

echo "need in outpuu"

exec 1>&3

echo "need in std"
