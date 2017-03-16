import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def readline(fun) : return [fun(_) for _ in input().split()]
def once():
    '''to cope once'''
    r, c, N = [int(x) for x in input().split()]
    worst = 2*r*c - r - c
    tot = r * c
    def oo(m, n) :
        a = 2*m*n + m + n + 1
        b = a - 1 + 2*(m+n)
        def f(x) :
            if x <= a :
                return 0
            elif x <= a+2 :
                return 3*(x-a)
            elif x <= b :
                return 3*(x-a) - 1
            else :
                return worst - 4 * (tot - x)
        return f
    def ee(m, n) :
        a = 2*m*n
        b = a - 2 + 2*(m+n)
        def f(x) :
            if x <= a :
                return 0
            elif x <= a+2 :
                return 2*(x-a)
            elif x <= b :
                return 3*(x-a) - 2
            else :
                return worst - 4 * (tot - x)
        return f
    def oe(m, n) :
        a = 2*m*n + n
        b = a - 1 + 2*(m+n)
        def f(x) :
            printerr(x, a, b)
            if x <= a :
                return 0
            elif x <= a+2 :
                return 2*(x-a)
            elif x <= b :
                return 3*(x-a) - 2
            else :
                return worst - 4 * (tot - x)
        return f
    if min(r, c) == 1 :
        n = max(r, c)
        if N <= n // 2 :
            return 0
        else :
            return worst - 2 * (tot - N)
    if r % 2 != 0 :
        r, c = c, r
    m = r // 2
    n = c // 2
    calc = oo(m,n) if r % 2 != 0 else (
        oe(n, m) if c % 2 != 0 else ee(m, n))
    return calc(N)

def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, (ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
