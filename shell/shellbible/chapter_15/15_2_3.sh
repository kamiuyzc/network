#!/bin/bash

exec 2>testerror

echo "should print stand output"
echo "should wirte in testerror" >&2

exec 1>testoutput

echo "should write in testoutput"
echo "should wirte in testerror" >&2


