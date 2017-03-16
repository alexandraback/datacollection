T = int( input() )
for tc in range(T):
    N = int( input() )
    A = [ int(x) for x in input().split() ]
    answer = []
    while sum(A) > 0:
        B = [ (A[i],i) for i in range(N) if A[i] > 0 ]
        B.sort()
        if sum(A) == 3:
            x = B[-1][1]
            cx = chr(65+x)
            A[x] -= 1
            answer.append( cx )
        else:
            x = B[-1][1]
            y = B[-2][1]
            cx = chr(65+x)
            cy = chr(65+y)
            A[x] -= 1
            A[y] -= 1
            answer.append( cx+cy )
        assert max(A)*2 <= sum(A)
    print('Case #{}: {}'.format(tc+1,' '.join(answer)))

