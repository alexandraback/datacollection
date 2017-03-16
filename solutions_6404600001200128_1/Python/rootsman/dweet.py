#!/usr/bin/python
from operator import attrgetter
from operator import itemgetter

import sys

class tc:

  def __init__(self,tcIndex,instr):
    self.myIndex = tcIndex
    self.N = int(instr.readline().strip())
    self.mi = [int(x) for x in instr.readline().strip().split()]
    self.maxSpike = 0
    self.maxSteady = 0

  def solve(self):
    if ( self.N == 2 ):
      self.maxSpike  = self.mi[-1] - self.mi[0]
      self.maxSteady = self.mi[-1] - self.mi[0]
    else:
      singleRoundMax = 0 
      mspk = 0
      for ei in range(1,self.N):
        cer = self.mi[ei-1] - self.mi[ei]
        if ( cer > 0 ):
          mspk += cer
          if ( cer > singleRoundMax ):
            singleRoundMax = cer
      self.maxSpike = mspk

      mstdy = 0
      for ei in range(1,self.N):
        cer = min(singleRoundMax,self.mi[ei-1])
        eaten = max(0,cer)
        mstdy += eaten
      self.maxSteady = mstdy

  def share(self,ostr):
    ostr.write ( 'Case #%i: %i %i\n' % (self.myIndex,self.maxSpike,self.maxSteady) )

def main():
  numTC = int(sys.stdin.readline().strip())
  for tci in range(0,numTC):
    theTC = tc(tci+1,sys.stdin)
    theTC.solve()
    theTC.share(sys.stdout)


main()
