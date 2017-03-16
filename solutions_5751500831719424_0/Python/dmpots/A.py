#!/usr/bin/env python3
import sys
import pprint
import argparse
from operator import attrgetter, methodcaller, itemgetter

debug = False
def log(msg, *args):
  global debug
  if debug:
    print(msg.format(*args))

def parse_args():
  parser = argparse.ArgumentParser(description='Google CodeJam Template')
  parser.add_argument('-d', '--debug', action='store_true',
                    help='print debugging messages')
  parser.add_argument('-c', '--case', metavar='N', type=int,
                    help='only run case N (default: run them all)')

  args = parser.parse_args()
  if args.debug:
    global debug
    debug = True
  return args

def mapstr(string):
  runs = []
  cnt = 0
  prev = None
  for (i, c) in enumerate(string):
    if c != prev and i > 0:
      runs.append((prev, cnt))
      cnt = 0
    prev = c
    cnt += 1
  runs.append((prev, cnt))
  return runs


def solve(strings):
  runs = []
  for string in strings:
    runlen = mapstr(string)
    runs.append(runlen)
    log("map: {}".format(runlen))

  len0 = len(runs[0])
  run0 = runs[0]
  for r in runs:
    if len(r) != len0:
      return -1
    
    for ((c1, cnt), (c2, cnt2)) in zip(r, run0):
      if c1 != c2:
        return -1

  total = 0
  for pos in range(len0):
    pbest = 100000
    for (tn, trun) in enumerate(runs):
      tcnt = trun[pos][1]
      pcnt = 0
      for (on, orun) in enumerate(runs):
        ocnt = orun[pos][1]
        pcnt += abs(tcnt - ocnt)
      if pcnt < pbest:
        pbest = pcnt
    total += pbest

  return total

class Case:
  def __init__(self, i, strings):
    self.i = i
    self.strings = strings

  def solve(self):
    log("Solving: {}", self)
    moves = solve(self.strings)
    sol = str(moves)
    if moves == -1:
      sol = "Fegla Won"
    return self.case() + sol

  def case(self):
    return "Case #{}: ".format(self.i)

  def __repr__(self):
    return self.case()

def parse_input(stream):
  cases = []
  T = int(stream.readline())
  for i in range(1, T+1):
    N = int(stream.readline())
    strings = []
    for j in range(N):
      strings.append(stream.readline().rstrip())

    # parse case input
    cases.append(Case(i, strings))
  return cases

def main():
  options = parse_args()
  cases = parse_input(sys.stdin)
  for case in cases:
    if not options.case or options.case == case.i:
      print(case.solve())
      sys.stdout.flush()


main()
  
