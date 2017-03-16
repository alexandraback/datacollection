#!/usr/bin/env python
import sys,os
import numpy as np


def Solve(N,strings):
    #check if possible
    base=norepeats(strings[0])
    for s in strings[1:]:
        rs_check=norepeats(s)
        if base!=rs_check: return 'Fegla Won'

    #rs is base string
    counts=np.array([countRepeats(s,base) for s in strings],dtype='int')

    mins=counts.min(axis=0)
    maxs=counts.max(axis=0)
    best_change=[]

    for i in xrange(len(base)):
        best=float("inf")
        for j in xrange(mins[i],maxs[i]+1):
            cost=np.sum(np.abs(counts[:,i]-j))
            best=min(cost,best)
        best_change.append(best)

    return sum(best_change)


def norepeats(s):
    output=[s[0]]
    for c in s[1:]:
        if c!=output[-1]: output.append(c)
    return ''.join(output)

def countRepeats(s,base):
    ibase=0
    counts=[0]
    assert s[0]==base[0]
    for c in s:
        if c==base[ibase]:
            counts[-1]+=1
        else:
            ibase +=1
            assert c==base[ibase]
            counts.append(1)
    assert len(counts)==len(base)
    return counts


def parse(infile):
    N=int(infile.readline().strip())
    strings=[infile.readline().strip() for i in xrange(N)]
    return N,strings


mytestcase="""paste test case here1"""

def test():
    import StringIO
    args=parse(StringIO.StringIO(mytestcase))
    Solve(*args)


class GCJ_Parser( object ):
    def __init__(self,fname):
        self.infile=open(fname,'r')
        self.NumCases=int(self.infile.readline().strip() )
        self.caseNum=0

    def __iter__(self): return self

    def next(self):
        if self.caseNum==self.NumCases: raise StopIteration
        self.caseNum += 1
        args=parse(self.infile)
        return self.caseNum , args


def runmain():
    myCases=GCJ_Parser(sys.argv[1])

    #Open output file, but don't overwrite old ones (for comparison)
    outname=sys.argv[1].rstrip('.in')+'.out'
    if os.path.isfile(outname):
        oldout=outname+'.old'
        ii=0
        while os.path.isfile(oldout):
            ii+=1
            oldout=outname+'.old'+str(ii)
        os.rename(outname,oldout)
        print 'Rename: %s -> %s'%(outname,oldout)   
 
    outfile=open(outname,'w')

    for iCase, args in myCases:
        answer=Solve(*args)

        print 'Case #'+str(iCase)+':',answer
        print >> outfile, 'Case #'+str(iCase)+':',answer




if __name__=='__main__':
    if sys.argv[1]=='-test':
        test()
    else:
        runmain()
