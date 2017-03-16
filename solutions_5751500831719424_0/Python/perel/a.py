##import sys
##sys.setrecursionlimit(10002)

def simp(s):
    ans='';last='';c=[]
    n=1
    for si in s:
        if si<>last:
            if last<>'':
                c.append(n)
                n=1
            ans+=si
            last=si
        else:
            n+=1
        #print si,n,c
    c.append(n)
    return (ans,c)

def count(li):
    l=sorted(li)
    m=len(l)/2
    s=sum([abs(li-l[m]) for li in l])
    return s

def solve(n,m):
    ms=[];mt=[]
    for mi in m:
        tmp=simp(mi)
        ms.append(tmp[0])
        mt.append(tmp[1])
    if max(ms)<>min(ms):
        return "Fegla Won"
    mc=zip(*mt)
    s=sum([count(mi) for mi in mc])
    return s


def main():
    fi=file('as.in')
    fo=file('a.out','w')
    t=int(fi.readline())
    for ti in range(t):
        n=int(fi.readline())
        m=[]
        for i in range(n):
            m.append(fi.readline()[:-1])
        ans="Case #%d: %s"%(ti+1,solve(n,m))
        #print ans
        fo.write(ans+'\n')
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
    #print count([1,2,3,4,100])
