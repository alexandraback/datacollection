#!/usr/bin/python3 -SOO
from collections import Counter
for t in range(1,int(input())+1):
    x = int(input())
    xs = [Counter(map(int,input().strip().split())) for _ in range(4)][x-1]
    y = int(input())
    ys = [Counter(map(int,input().strip().split())) for _ in range(4)][y-1]
    c = xs&ys
    l = sum(c.values())
    print('Case #%d:'%t, ('Bad magician!' if l>1 else ('Volunteer cheated!' if l==0 else list(c)[0])))
    










