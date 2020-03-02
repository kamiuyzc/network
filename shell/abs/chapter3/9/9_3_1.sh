#!/bin/bash

a=`echo {a..z}`
a=${a// /}

echo "-default ${a-`who`}"
unset a
echo "-default ${a-`who`}"
echo "-default ${a:-`who`}"
a=
echo "-default ${a-`who`}"
echo "-default ${a:-`who`}"

echo "b value is $b"
echo "=default ${b=`who`}"
echo "b value is $b"
b=
echo "=default ${b:=`who`}"
b=
echo "=default ${b=`who`}"

echo "+default ${c+`who`}"
echo $c

echo "? ${e?LALALA}"