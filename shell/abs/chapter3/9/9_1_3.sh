#!/bin/bash

for i in $*
do
    echo "\$* not common,$i"
done


for i in $@
do
    echo "\$@ not common,$i"
done


for i in "$*"
do
    echo "\$* not common,$i"
done


for i in "$@"
do
    echo "\$@ not common,$i"
done


for i in "$@"
do
    shift
    echo $i
done

