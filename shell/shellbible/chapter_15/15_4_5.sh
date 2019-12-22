#!/bin/bash

exec 3> 1.txt

echo "abc" >&3

exec 3>&- 

echo "error" >&3


