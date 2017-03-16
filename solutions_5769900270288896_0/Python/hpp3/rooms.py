import itertools
def value(comb, r, c):
    comb = [(n/r,n%r) for n in comb]
    ss = set(comb) 
    ans = 0
    for n in ss:
        if (n[0]-1, n[1]) in ss:
            ans += 1
        if (n[0]+1, n[1]) in ss:
            ans += 1
        if (n[0], n[1]-1) in ss:
            ans += 1
        if (n[0], n[1]+1) in ss:
            ans += 1
    return ans/2
        

def hack(r,c,n):
    m = r*c
    best = 9999999999
    for comb in itertools.combinations(range(m), n):
        best = min(best, value(comb,r,c))

    return best

q = int(raw_input())
for t in range(q):
    r,c,n = map(int, raw_input().split())
    answer = hack(r,c,n)
    print "Case #{}:".format(t+1), answer

