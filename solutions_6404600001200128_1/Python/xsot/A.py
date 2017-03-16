for tc in range(1, int(raw_input())+1):
    n = int(raw_input())
    m = map(int, raw_input().split())
    
    a = 0
    b = 0
    prev = 0
    for cur in m:
        if cur < prev:
            a += prev-cur
            b = max(b, prev-cur)
        prev = cur
        
    c = (n-1)*b
    for cur in m[:-1]:
        if cur < b:
            c -= b-cur
        
    print "Case #%d: %d %d" % (tc, a, c)
    
    