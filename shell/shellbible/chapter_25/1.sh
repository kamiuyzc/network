#!/bin/bash


command=`which mysql`
$command Lab_Dev -uroot -pfortinet -e "select * from users;"