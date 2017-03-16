for cases in range(1, int(input()) + 1):
    n = int(input())
    print('Case #%d:' % (cases,), end=' ')
    d = {}
    P = list(map(int, input().split()))
    s = sum(P)
    l = [[chr(ord('A') + i), P[i]] for i in range(n)]
    while(s > 0):
        l.sort(key = lambda x: x[1])
        
        if(sum([x[1] for x in l]) == 3):
            print(l[-1][0], end=' ')
            if(l[-1][1] == 1):
                del l[-1]
                s -= 1
            continue
            
        op = l[-1][0]
        l[-1][1] -= 1
        s -= 1
        
        if(len(l) > 1):
            if(l[-2][1] >= l[-1][1]):
                l[-2][1] -= 1
                op = op + l[-2][0]
                s -= 1
            else:
                if(l[-1][1] != 0):
                    l[-1][1] -= 1
                    op = op + l[-1][0]
                    s -= 1
        else:
            if(l[-1][1]):
                l[-1][1] -= 1
                op = op + l[-1][0]
                s -= 1

        l = [x for x in l if x[1] > 0]
        print(op, end=' ')
    print()
