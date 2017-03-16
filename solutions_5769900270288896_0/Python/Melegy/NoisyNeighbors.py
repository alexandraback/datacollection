'''
Created on May 2, 2015

@author: sshadmin
'''
from collections import deque
from itertools import combinations

d=[(0,1),(1,0),(0,-1),(-1,0)]
def checkgrid(grid):
    c=0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j]=="X":
                for dir in d:
                    if dir[0]+i>=0 and dir[0]+i<len(grid):
                        if dir[1]+j>=0 and dir[1]+j<len(grid[0]):
                            px,py=dir[0]+i,dir[1]+j
                            if grid[px][py]=='X':
                                c+=0.5
    return int(c)
                            
    
def solve(r,c,n):
    size=r*c
    comb=list(combinations(range(size),n))
    mn=9999999999999
    for i in range(len(comb)):
        grid=[]
        for _ in range(r):
            grid.append([0]*c)
        for j in range(n):
            row=comb[i][j] / c
            col=comb[i][j] % c
            grid[row][col]="X"
        mn=min(mn,checkgrid(grid))
    return mn
    
    
    

fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    r,c,n=[int(x) for x in fin.readline().strip().split()]
    print case
    fout.write("Case #"+str(case)+": "+str(solve(r,c,n))+"\n")
    
    