#!/usr/bin/python

f=open('A-small-attempt0.in','r')

n=int(f.readline())
for t in range(1,n+1):
    a,i=[],int(f.readline())
    for k in range(4):
        a.append([int(x) for x in f.readline().split()])
    b,j=[],int(f.readline())
    for k in range(4):
        b.append([int(x) for x in f.readline().split()])
    s=set(a[i-1])&set(b[j-1])
    if len(s)==1:
        print("Case #%d: %d" % (t,s.pop()))
    elif len(s)==0:
        print("Case #%d: Volunteer cheated!"%t)
    else:
        print("Case #%d: Bad magician!"%t)
