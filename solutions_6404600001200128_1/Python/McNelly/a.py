import sys

sys.stdin = open("A.in")

INF = 0xdeadbeef

def do_sol_a(x, n, ns):
    res = 0
    if not x:
        if len(set(ns)) == 1:
            return 0
        else:
            return INF
    
    for i in xrange(1, n):
        a = ns[i - 1]
        b = ns[i]
        if b < a:
            res += ((a - b + x - 1) / x) * x
            
    return res

#print do_sol_a(5, 4, [10, 5, 15, 5])

def do_sol_b(x, n, ns):
    res = 0
    y = 10 * x
    
    if not x:
        if len(set(ns)) == 1:
            return 0
        else:
            return INF
    
    for i in xrange(1, n):
        a = ns[i - 1]
        b = ns[i]
        if a - b > y:
            return INF
        if a > b and a > y:
            print ((a - b + y - 1) / y) * y
            res += ((a - b + y - 1) / y) * y
        else:
            print min(a, y)
            res += min(a, y)
    return res


print do_sol_b(11, 6, [23,90,40,0, 100,9])


def sol_b(n, ns):
    ans = INF
    for i in xrange(0, 128):
        ans = min(ans, do_sol_b(i, n, ns))
    return ans


def sol_a(n, ns):
    ans = INF
    for i in xrange(0, 128):
        ans = min(ans, do_sol_a(i, n, ns))
    return ans

def solve():
    n = int(raw_input())
    ns = map(int, raw_input().split())
    a = sol_a(n, ns)
    b = sol_b(n, ns)
    return a, b

'''
T = int(raw_input())
for cas in xrange(T):
    a, b = solve()
    print "Case #%d: %d %d" % (cas + 1, a, b)
'''
