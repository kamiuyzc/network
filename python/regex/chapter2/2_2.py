#!/bin/python

import re


a = "aaa111   "
print repr(a)
pattern = re.compile(r"""
                       ^\w+
                       # chapter
                       \d+
                        # num
                       \s+$
                       """, re.X | re.M)
print pattern.search(a).group()