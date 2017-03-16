#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @author: Danilo J. S. Bellini
"""
The Repeater
"""

import sys
from itertools import groupby

def repeater_amount(data):
  def pairs_gen():
    for el in data:
      r = []
      for k, g in groupby(el):
        gl = list(g)
        glen = len(gl)
        r.append((gl[0], glen))
      yield r
  sp = pairs_gen()
  first = next(sp)
  size = len(first)
  chars = [k for k, v in first]
  the_max = [v for k, v in first]
  the_min = [v for k, v in first]
  to_size = [{v: 0} for k, v in first]

  for already, data in enumerate(sp, 1):
    for idx, (ch, amount) in enumerate(data):
      if idx >= size or chars[idx] != ch:
        raise ValueError("Impossible")
      if amount > the_max[idx]:
        for s in range(the_max[idx] + 1, amount + 1):
          to_size[idx][s] = to_size[idx][s - 1] + already
        the_max[idx] = amount
      if amount < the_min[idx]:
        for s in range(the_min[idx] - 1, amount - 1, -1):
          to_size[idx][s] = to_size[idx][s + 1] + already
        the_min[idx] = amount
      for s in to_size[idx]:
        to_size[idx][s] += abs(amount - s)

  return sum(min(el.values()) for el in to_size)

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      N = int(fin.readline())
      data = [fin.readline() for _ in range(N)]
      try:
        result = repeater_amount(data)
      except ValueError:
        result = "Fegla Won"
      fout.write("Case #{}: {} \n".format(case, result))
