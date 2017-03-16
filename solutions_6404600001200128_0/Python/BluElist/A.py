T = int(input())

for CC in range(T):
    N = int(input())
    m = list(map(int,input().split()))

    m1 = [ m[x]-m[x+1] for x in range(len(m)-1) if m[x]-m[x+1]>0 ]

    if len(m1)==0:
        m1 = [0]
    big = max(m1)

    m2 = []
    for x in range(N-1):
        if m[x]<big:
            m2.append(m[x])
        else:
            m2.append(big)

    print('Case #{}:'.format(CC+1),sum(m1),sum(m2))
