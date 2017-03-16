#!/usr/bin/python
import math
from operator import attrgetter
from operator import itemgetter

import sys

class FacNum:
  def __init__(self,a):
    self.val = a
    self.factorize()

  def factorize(self):
    maxFac = 2 + int(math.sqrt(float(self.val)))
    resid = self.val
    self.facs = dict()
    chkF = 2
    while ( resid != 1 ):
      if ( resid % chkF == 0 ):
        if ( chkF not in self.facs.keys() ):
          self.facs[chkF] = 0
        self.facs[chkF] += 1
        resid /= chkF
      else:
        chkF += 1
  def show(self):
    print '%i = %s' % (self.val, ','.join(['%i^%i' % (k,self.facs[k]) for k in sorted(self.facs.keys())]))

  def lcmWith(self,other):
    for fo in other.facs.keys():
      if ( fo not in self.facs.keys() ):
        self.facs[fo] = 0
      self.facs[fo] = max(self.facs[fo], other.facs[fo])
    self.recalcVal()

  def recalcVal(self):
    self.val = 1
    for fo in self.facs.keys():
      for pwr in range(0,self.facs[fo]):
        self.val *= fo

class tc:

  def __init__(self,tcIndex,instr):
    self.myIndex = tcIndex
    (self.B,self.N) = [int(x) for x in instr.readline().strip().split()]
    self.Mk         = [int(x) for x in instr.readline().strip().split()]
    self.whichBarber = 0

  def getN(self,t):
    rv = 0
    for curMk in self.Mk:
      rv += int(t/curMk)
    return rv
    
  def solve(self):
    if (  self.N <= self.B ):
      self.whichBarber = self.N
      return 
    self.period = FacNum(1)
    for curMk in self.Mk:
      self.period.lcmWith(FacNum(curMk))
    #x.show()
    modulus = 0
    for curMk in self.Mk:
      modulus += self.period.val / curMk
    nBeforeMe = self.N - 1
    ##print 'N = %i pd = %i nBeforeMe = %i mod = %i' % (self.N,self.period.val,nBeforeMe,modulus)

    nBeforeMe %= modulus
    # if ( nBeforeMe < self.B ):
    #   self.whichBarber = nBeforeMe + 1
    #   return
    #print 'N = %i pd = %i nBeforeMe = %i' % (self.N,self.period.val,nBeforeMe)
    #

    # t = int(float(nBeforeMe)/float(modulus)*float(self.period.val))+5
    # while ( self.getN(t) >= nBeforeMe ):
    #   #print '%i at %i' % (self.getN(t),t)
    #   t -= 1
    # #print 'whew. %i at %i' % (self.getN(t),t)
    # #nBeforeMe -= self.getN(t)
    self.whichBarber = None
    t = 0
    while ( self.whichBarber is None ):
      for bi in range(0,self.B):
        if ( t % self.Mk[bi] == 0 ):
          #print '%i: B%i (%i left)' % (t,bi+1,nBeforeMe)
          if ( nBeforeMe == 0 ):
            self.whichBarber = bi+1
            return
          else:
            nBeforeMe -= 1
      t += 1

  def share(self,ostr):
    ostr.write ( 'Case #%i: %i\n' % (self.myIndex,self.whichBarber) )

def main():
  numTC = int(sys.stdin.readline().strip())
  for tci in range(0,numTC):
    theTC = tc(tci+1,sys.stdin)
    theTC.solve()
    theTC.share(sys.stdout)


main()
