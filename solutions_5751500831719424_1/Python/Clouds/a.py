#!/usr/bin/python

import sys
fin=sys.stdin
T=int(fin.readline())

for k in range(T):
    n=int(fin.readline())
    a,f,po,s="",[],True,0
    for i in range(n):
        st=fin.readline()
        print(st,file=sys.stderr)
        x,y,z=st[0],0,0
        for j in range(len(st)):
            if x!=st[j]:
                if i==0:
                    a+=x
                    f.append([y])
                elif z<len(a) and a[z]==x:
                    f[z].append(y)
                else:
                    po=False
                    break
                x,y,z=st[j],1,z+1
            else:
                y+=1
        if po==False or z!=len(a):
            po=False
            #break
    print(a,f,file=sys.stderr)
    if not po:
        print("Case #%d: Fegla Won"%(k+1))
    else:
        for j in range(len(a)):
            xx=sorted(f[j])[int(n/2)]
            s+=sum([abs(x-xx) for x in f[j]])
            #print(sorted(f[j]),xx,s,file=sys.stderr)
        print("Case #%d: %d"%(k+1,s))

