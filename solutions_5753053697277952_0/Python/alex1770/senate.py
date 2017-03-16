import sys

def thing(N,P):
  s=sum(P)
  while 1:
    nz=0
    for i in range(N): nz+=(P[i]>0)
    l=range(N)
    l.sort(key=lambda i:-P[i])
    if nz==0: print;return
    if nz!=2: print chr(65+l[0]),;P[l[0]]-=1;continue
    print chr(65+l[0])+chr(65+l[1]),;P[l[0]]-=1;P[l[1]]-=1

T=int(sys.stdin.readline())
for case in range(1,T+1):
  N=int(sys.stdin.readline().strip())
  P=[int(y) for y in sys.stdin.readline().strip().split()]
  print "Case #%d:"%case,;thing(N,P)
