import sys
import string
from sys import stderr

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout
def read(f,typ):
    return map(typ, f.readline().split())
    
def countem(s):
    id = []
    res = []
    p = s[0]
    n = 1
    id.append(p)
    for c in s[1:]:
        if c!=p:
            res.append(n)
            id.append(c)
            n=1
            p=c
        else:
            n=n+1
    res.append(n)
    return id, res
    
def acts(l):
    l.sort()
    v = l[len(l)/2]
    a = 0
    for s in l:
        a+=abs(s-v)
    return a
    
def transpose(lss):
    return [list(ls) for ls in zip(*lss)]

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            N, = read(f,int)
            sys.stderr.write("Case {0} has {1} strings\n".format(x+1, N))
            s = []
            for y in range(N):
                s.append(f.readline().strip())
                sys.stderr.write("{0}\n".format(s[y]))
            # Count actions
            r1 = map(countem, s)
            ok = True
            for i in range(N-1):
                if r1[i][0] != r1[i+1][0]:
                    ok = False
            if ok:
                print >>stderr, r1
                ns = [r[1] for r in r1]
                print >>stderr, ns
                print >>stderr, transpose(ns)
                print >>stderr, map(acts,transpose(ns))
                print >>stderr, sum(map(acts,transpose(ns)))
                res = sum(map(acts,transpose(ns)))
            else:
                res = 'Fegla Won'
            
            outf.write('Case #{0}: '.format(x+1))
            outf.write('{0}'.format(res))
            outf.write('\n')
