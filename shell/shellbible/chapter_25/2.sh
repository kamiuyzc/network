#!/bin/bash

command=`which mysql`
$command Lab_Dev -uroot -pfortinet <<EOF
show tables;
select * from users;
EOF
