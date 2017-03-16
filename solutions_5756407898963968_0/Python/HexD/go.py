#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on Sat Apr 12 04:43:37 2014
# @author: Danilo J. S. Bellini
"""
Magic Trick
"""

import sys

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      row1 = int(fin.readline())
      table1 = [fin.readline().split() for _ in range(4)]
      row2 = int(fin.readline())
      table2 = [fin.readline().split() for _ in range(4)]

      # Algorithm
      remain = set(table1[row1-1]).intersection(table2[row2-1])

      # Output
      if len(remain) == 1:
        result = next(iter(remain))
      elif remain:
        result = "Bad magician!"
      else:
        result = "Volunteer cheated!"
      fout.write("Case #{}: {} \n".format(case, result))
