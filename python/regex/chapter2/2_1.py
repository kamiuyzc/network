#!/bin/python
import re
#num = raw_input("Please Input:")
num = "10F"
pattern = re.compile("^([-+]?[0-9]+)(?:[FC])$")
match = pattern.match(num)
group_list = match.groups()
print match.groups()