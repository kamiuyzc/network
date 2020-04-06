#!/bin/bash
sed -i "s/define NUM [[:digit:]]*/define NUM $1/g" client.c;y_gcc client.c hyzc;./client.c.out 127.0.0.2


