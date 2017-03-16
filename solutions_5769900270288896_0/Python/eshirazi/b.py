import itertools

def bad(r, c, state):
    s = 0
    for i in xrange(r):
        for j in xrange(c):
            if state[i * c + j]:
                if j + 1 < c:
                    s += state[i * c + (j+1)]
                if i + 1 < r:
                    s += state[(i+1) * c + j]
    return s

def solve(r,c,n):
    res = 1000000
    for i in itertools.product(*([[0,1]] * r * c)):
        if sum(i) == n:
            res = min(res, bad(r, c, i))
    return res

if __name__ == "__main__":
    tests = int(raw_input())
    for i in xrange(tests):
        r,c,n = [int(x) for x in raw_input().split()]
        print "Case #{}: {}".format(i + 1, solve(r,c,n))