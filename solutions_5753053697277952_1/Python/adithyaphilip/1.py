def op(ans, case):
    for i in map(str, range(0,25)):
        ans = ans.replace(i, chr(ord('A') + int(i)))
    print("Case #%d: %s" %(case + 1, ans))

for _ in range(int(input())):
    n = int(input())
    l = list(map(int ,input().split()))
    l = [[i, l[i]] for i in range(n)]
    
    tot = sum([e[1] for e in l])

    a = []
    empty = 0

    while tot!=0:
        l.sort(key = lambda x: x[1])
        if l[-1][1] == l[-2][1] and (n<=2 or l[-3][1]!=1):
            a.append(str(l[-1][0]) + str(l[-2][0]))
            l[-1][1]-=1
            l[-2][1]-=1
            tot-=2
        else:
            a.append(str(l[-1][0]))
            l[-1][1]-=1
            tot-=1

    op(" ".join(a), _)
    
