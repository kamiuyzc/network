#!/bin/bash
for i in planet venus
do
    echo $i
done

for i in "planet venus"
do
    echo $i
done

FILES="/home/yangzhengchu/git/book/shell/abs/chapter3/9/9_1_1.sh
/home/yangzhengchu/git/book/shell/abs/chapter3/9/9_1_2.sh
"
for i in $FILES
do
    if [ -f "$i" ]
    then
        echo $i
    fi
done
echo "a"
for file in *
do
    echo $file
done


for i in `ls`
do
    echo $i
done