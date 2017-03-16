import sys
f = open("a0" if len(sys.argv)<2 else sys.argv[1] ,"r")
T = int(f.readline())
def sig(s):
    x0= ""
    rtn=""
    for x in s:
        if x!=x0:
          rtn+=x
          x0 = x
    return rtn
def spec(s):
    x0= ""
    rtn=[]
    for x in s:
        if x==x0:
          rtn[-1]+=1
        else:
          x0 = x
          rtn.append(1)
    return rtn
def work(sa):
    l = len(set(sig(s) for s in sa))
    if l >1:
        return -1
    ss = [spec(s) for s in sa]
    rtn = 0
    for i in range(len(ss[0])):
        a = sorted(x[i] for  x in ss)
        m = a[len(a)//2]
        rtn += sum(abs(x-m) for x in a)
    return rtn
    
    

for t in range(1,1+T):
    N = int(f.readline())
    sa=[f.readline().strip() for i in range(N)]
    r = work(sa)
    print("Case #%d: %s"%(t, r if r>=0 else "Fegla Won"))
