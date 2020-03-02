#!/bin/bash


TIMELIMIT=10
INTERVAL=1
let HALF=$TIMELIMIT/2
while [ $SECONDS -lt $TIMELIMIT ]
do
    if [ $SECONDS -lt $HALF ]
    then
        echo "before $SECONDS"
    else
        echo "after $SECONDS"
    fi
    sleep 1
done