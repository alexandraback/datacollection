import sys

def dfs(ps, tot):
    #print ps, tot
    if tot == 0:
        return []

    majority = tot/2+1
    for p in ps:
        if p >= majority:
            return False

    ps_sorted = sorted(enumerate(ps), key=lambda (k,v): -v)
    for i, p in ps_sorted:
        if ps[i] > 0:
            ps[i] -= 1
            res = dfs(ps, tot-1)
            if res != False:
                res.append([i])
                return res
            for j, p in ps_sorted:
                if ps[j] > 0:
                    ps[j] -= 1
                    res = dfs(ps, tot-2)
                    if res != False:
                        res.append([i, j])
                        return res
                    ps[j] += 1
    return False


def solve(ps):
    tot = sum(ps)
    res = dfs(ps, tot)
    #print res
    res = map(lambda lst: ''.join(map(lambda i: chr(ord('A')+i), lst)), reversed(res))
    print ' '.join(res)

N = int(sys.stdin.readline())
for i in range(N):
    n = int(sys.stdin.readline())
    ps = map(int, sys.stdin.readline().split())
    print "Case #{}:".format(i+1),
    solve(ps)
