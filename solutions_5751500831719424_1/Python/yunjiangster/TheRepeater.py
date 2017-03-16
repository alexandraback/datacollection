import sys,math,re,copy
problems=[]
counter=0
currN=0
currP = []
for i,line in enumerate(sys.stdin):
    if i == 0:
        totalN=int(line.strip('\r\t\n '))
    elif currN==0:
        currN = int(line.strip('\r\t\n '))
        currP = []
    else:
        currP.append(line.strip('\r\t\n '))
        counter += 1
        if counter == currN:
            currN = 0
            problems.append(copy.deepcopy(currP))
            counter = 0
'''
for p in problems:
    for i in p:
        print i
'''

def contract(s):
    ret=  ''    
    
    for i,c in enumerate(s):
        if i==0:
            ret += c
        elif not c == ret[-1]:
            ret += c
    return ret

def allequal(L):
    for m in L[1:]:
        if not m == L[0]:
            return False
    return True

def count(s):
    ret = []
    for i,c in enumerate(s):
        if i == 0:
            char = c
            ct = 1
        elif not c == char:
            ret.append(ct)
            ct = 1
            char = c
        else:
            ct += 1
    ret.append(ct)
    return ret

def dist(s,t):
    sc = count(s)
    tc = count(t)
    return sum(abs(i-j) for i,j in zip(sc,tc))

def mintrip(ts):
    ret = []
    for t in ts:
        ret.append(sum(abs(t-s) for s in ts))
    return min(ret)

def output(p):
    q= [contract(s) for s in p]
    if not allequal(q):
        return 'Fegla Won'
    else:
        sumdists = []
        charcts = [count(s) for s in p]
        ret = []
        for i in xrange(len(charcts[0])):
            ret.append(mintrip([cts[i] for cts in charcts]))
    return sum(ret)



for i,p in enumerate(problems):
    print 'Case #%s: %s'%(i+1,output(p))

