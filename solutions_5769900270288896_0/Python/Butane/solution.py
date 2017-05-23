import sys
from itertools import combinations
sys.stdin=open("kk.in",'r')
sys.stdout=open("OUT.txt",'w')
for t in xrange(int(raw_input())):
    a,b,c=map(int,raw_input().split())
    coor=[]
    for i in xrange(a):
        for j in xrange(b):coor.append((i,j))
    ans=1e999
    for comb in combinations(coor,c):
        co=0
        grid=[[' ' for i in xrange(b)]for j in xrange(a)]
        for r,c in comb:grid[r][c]='X'
        for i in xrange(a):
            for j in xrange(b):
                if grid[i][j]=='X':
                    for y1,x1 in ((0,1),(1,0)):
                        if 0<=i+y1<a and 0<=j+x1<b and grid[i+y1][j+x1]=='X':co+=1
        ans=min(ans,co)
    print 'Case #%i: %i'%(t+1,ans)
sys.stdout.close()

