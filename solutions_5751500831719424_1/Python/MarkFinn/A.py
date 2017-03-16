#!/bin/python
problem='A'


import sys


def solve(n):
  def canonical(s):
    o=''
    for c in s:
      if not o or o[-1]!=c    :
        o+=c
    return o

  if len(n)<2:
    return 0
  can=canonical(n[0])
  for s in n[1:]:
    if can!=canonical(s):
      return -1
  
  ss=[]
  for s in n:
    sss=[]
    for c in can:
      cc=-1
      while s and s[0]==c:
        cc+=1
        s=s[1:]
      sss.append(cc) 
    ss.append(tuple(sss))
#  print ss

  res=0

  for r in xrange(len(can)):
    vs = [xx[r] for xx in ss]
    bestmove=None
#    print 'retying', min(vs), max(vs)+1
    for vset in xrange(min(vs), max(vs)+1):
      moves=0
      for v in vs:
#        print 'in', vset, v
        moves+=abs(vset-v)
#        print 'moves', moves, bestmove
      if bestmove==None or bestmove > moves:
         bestmove=moves
    res+=bestmove
  return res


def doall(outf, testcases, lines):
  case = 1

  while lines:
    n = int(lines[0])
    nn = [l.strip() for l in lines[1:n+1]]
    lines=lines[n+1:]
 
    s=solve(nn)
    if s<0:
      s='Fegla Won'
    else:
      s=str(s)
    print >> outf, 'Case #%d: %s'%(case,s)

    case+=1


def readin(infile):
  print >> sys.stderr, "reading from " + infile
  lines=open(infile, 'r').readlines()
  testcount = int(lines[0])
  print >> sys.stderr, "read %d test cases from %d lines"%(testcount, len(lines))
  lines=lines[1:]
  return testcount, lines

if __name__ == '__main__': 
  if len(sys.argv) == 1:
    inf='A-test.in'
    outf=sys.stdout
    print >> sys.stderr, "writing to stdout "
  elif len(sys.argv) == 3:
    input_name_format='{problem}-{input}-{id}.in'
    output_name_format='{problem}-{input}-{id}.out'

    inf=str.format(input_name_format, problem=problem, input=sys.argv[1], id=int(sys.argv[2]))
    outf=str.format(output_name_format, problem=problem, input=sys.argv[1], id=int(sys.argv[2]))
    print >> sys.stderr, "writing to "+outf
    outf = open(outf,'w')
  else:
    print >> sys.stderr, "bad args"
    sys.exit(1)
  tc, l = readin(inf)
  doall(outf, tc, l)
  print >> sys.stderr, "done"

