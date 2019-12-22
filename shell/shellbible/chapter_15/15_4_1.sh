#!/bin/bash

exec 4> customfile
echo "output to customfile"> &4

