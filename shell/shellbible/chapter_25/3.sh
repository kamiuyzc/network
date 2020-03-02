#!/bin/bash

MYSQL=`which mysql`
if [ $# -ne 4 ]
then
    echo
else
    echo '1'
    command="INSERT INTO roles VALUES($1, '$2', $3, $4)"
    $MYSQL Lab_Dev -uroot -pfortinet << EOF
    $command;
EOF

    if [ $? -eq 0 ]
    then
        echo 'ok'
    else
        echo 'error'
    fi
fi