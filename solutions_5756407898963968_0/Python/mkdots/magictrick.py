T = int(raw_input())

for t in xrange(T):
    a = int(raw_input())
    A = [raw_input() for _ in xrange(4)][a - 1]
    A = set(map(int, A.split()))
    
    b = int(raw_input())
    B = [raw_input() for _ in xrange(4)][b - 1]
    B = set(map(int, B.split()))
    
    A &= B
    
    ans = ""
    if len(A) == 0:
        ans = "Volunteer cheated!"
    elif len(A) > 1:
        ans = "Bad magician!"
    else:
        ans = str(A.pop())
    
    print "Case #{}: {}".format(t + 1, ans)
    