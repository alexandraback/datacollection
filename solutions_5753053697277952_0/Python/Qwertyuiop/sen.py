LETTERS="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def solve(pN):
    result=[]
    gTO={}
    for k in pN.keys():
        if pN[k]>1:
            gTO[k]=pN[k]-1
    while sum(gTO.values())>0:
        m=-1
        mK=-1
        mS=-1
        mKS=-1
        for k in gTO.keys():
            if gTO[k]>m:
                mK=k
                m=gTO[k]
                mKS=-1
                mS=-1
            if gTO[k]==m and k!=mK:
                mKS=k
                mS=gTO[k]

        gTO[mK]-=1
        r=LETTERS[mK]
        if mS!=-1:
            r+=LETTERS[mKS]
            gTO[mKS]-=1
        result.append(r)
    singles = pN.keys()
    if len(singles)%2!=0:
        k=singles.pop(0)
        result.append(LETTERS[k])
    while len(singles)>0:
        r=""
        k=singles.pop(0)
        r+=LETTERS[k]
        k=singles.pop(0)
        r+=LETTERS[k]
        result.append(r)
    return " ".join(result)

import sys
f=open(sys.argv[1], "r")
F=open(sys.argv[1]+".out", "w")
for i in range(int(f.readline())):
    f.readline()
    L=map(int, f.readline().rstrip().split(" "))
    pN={}
    for j in range(len(L)):
        pN[j]=L[j]
    F.write("Case #%d: %s\n" % (i+1, solve(pN)))
F.close() 