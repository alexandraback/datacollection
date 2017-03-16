import sys

sys.stdin = open('input')
sys.stdout, debug = open('output', 'w'), sys.stdout

def calc(g):
    g.sort()
    s = sum(g)
    res = s - len(g)*g[0]
    for i in range(1, len(g)):
        s -= 2*g[i - 1]
        res = min(res, s + (2*i - n)*g[i])
    return res
    
def solve(l):
    res = 0
    ind = [0]*len(l)
    while ind[0] < len(l[0]):
        g = []
        i = ind[0]
        c = l[0][ind[0]]
        while ind[0] < len(l[0]) and c == l[0][ind[0]]:
            ind[0] += 1
        g.append(ind[0] - i)
        for j in range(1, len(l)):
            i = ind[j]
            while ind[j] < len(l[j]) and c == l[j][ind[j]]:
                ind[j] += 1
            g.append(ind[j] - i)
        if 0 not in g:
            res += calc(g)
        else:
            return None
    if ind != [len(s) for s in l]:
        return None
    return res
        
answer = 'Case #{0}: {1}'
t = int(input())
for i in range(t):
    l = []
    n = int(input())
    for j in range(n):
        l.append(input())
    s = solve(l)
    if s is not None:
        print(answer.format(i + 1, s))
    else:
        print(answer.format(i + 1, 'Fegla Won'))

sys.stdin.close()
sys.stdout.close()
