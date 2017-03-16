#!/usr/bin/python

import sys

def unhappy(R, C, G, N, ss=0):
  # print >> sys.stderr, G

  if N <= 0: # everyone placed, calc unhappiness
    U = 0

    # vertical dividers
    for i in range(R-1):
      for j in range(C):
        if G[i][j] == 1 and G[i+1][j] == 1:
          U += 1

    # horizontal dividers
    for i in range(R):
      for j in range(C-1):
        if G[i][j] == 1 and G[i][j+1] == 1:
          U += 1

    return U

  else: # try place one
    U = None
    for i in range(R):
      for j in range(C):
        if G[i][j] == 0: # empty?
          ij = i * C + j
          if ij >= ss: # don't repeat searches
            G[i][j] = 1
            u = unhappy(R, C, G, N-1, ij)
            if u != None and (U == None or u < U):
              U = u
              if U == 0: # quick return
                return U
            G[i][j] = 0
    return U

T = int(sys.stdin.readline())
for test in range(T):
  print >> sys.stderr, "Test: %d" % (test+1)
  toks = sys.stdin.readline().strip().split()
  R = int(toks[0])
  C = int(toks[1])
  N = int(toks[2])

  # print >> sys.stderr, R, C, N
  G = []
  for i in range(R):
    G.append([])
    for j in range(C):
      G[i].append(0)
  U = unhappy(R, C, G, N)
  # print >> sys.stderr, U

  print "Case #%d: %d" % (test+1, U)

