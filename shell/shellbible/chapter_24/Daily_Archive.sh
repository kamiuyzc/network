#!/bin/bash

BASE=/root/backup/
YEAR=`date +%y`
MONTH=`date +%m`
DAY=`date +%d`
mkdir -p $BASE$YEAR/$MONTH
FILE=backupfile${DAY}.tar.gz
CONFIG_FILE=/root/backupconfig
DESTINATION=$BASE$YEAR/$MONTH/$FILE

if [ ! -f ${CONFIG_FILE} ]
then
    echo "config file is not exist"
    exit
fi

exec 0< $CONFIG_FILE

read filename

backuplist=''
while [ $? -eq 0 ]
do
    if [ -f $filename -o -d $filename ]
    then
        backuplist="$backuplist $filename"
    fi
    read filename
done

tar -zcf $DESTINATION $backuplist 2>/dev/null

exit
