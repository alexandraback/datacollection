#!/usr/bin/python3
from googlejam.tools import *

class Jam:
  split = " "
  #flatten = True
  def cases(ss):
    num_cases = num(ss)
    for i in range(num_cases):
      choosen_row = num(ss)
      rows = take(ss,4)
      new_row = num(ss)
      transformed = take(ss,4)
      yield choosen_row, rows, new_row, transformed

  def solve(choosen_row, rows, new_row, transformed):
    p1,p2 = set(rows[choosen_row-1]), set(transformed[new_row-1])
    #msg(p1,p2)
    sol = p1 & p2
    if not sol:
      return "Volunteer cheated!"
    if len(sol) > 1:
      return "Bad magician!"
    else:
      return [s for s in sol][0]
    

import googlejam.main
