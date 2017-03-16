#!/usr/bin/python

import sys

def solve(strs):
  # Check feasibility
  (rep, _) = characterize(strs[0])
  nums = []
  for s in strs:
    (minrep, ns) = characterize(s)
    if minrep != rep:
      return 'Fegla Won'
    nums.append(ns)

  counts = zip(*nums)

  result = 0
  for i in xrange(len(counts)):
    m = max(counts[i])
    min_moves = sys.maxint
    for candidate in xrange(1, m + 1):
      moves = 0
      for c in counts[i]:
        moves += abs(candidate - c)
      min_moves = min(min_moves, moves)
    result += min_moves
  return result

def characterize(s):
  prev = None
  nums = []
  count = 0
  curr = s[0]
  minrep = curr
  for c in s:
    if c != curr:
      nums.append(count)
      count = 1
      minrep += c
      curr = c
    else:
      count += 1
  return (minrep, nums)

def main():
  lines = iter(sys.stdin.readlines())
  cases = int(lines.next())
  for case in range(cases):
    N = int(lines.next())
    strs = []
    for _ in xrange(N):
      strs.append(lines.next())
    print 'Case #%d: %s' % (case+1, solve(strs))

main()
