#with open('A.in') as f:
#    input = list(f)[::-1].pop

def naive(P):
    out = []
    while any(P):
        a = P.index(max(P))
        P[a] -= 1
        x = chr(65 + a)
        if any(P) and sum(P) != 2:
            a = P.index(max(P))
            P[a] -= 1
            x += chr(65 + a)
        out.append(x)
    return ' '.join(out)

for x in range(1, int(input()) + 1):
    N = input()
    P = list(map(int, input().split()))
    print('Case #%d:' % x, naive(P))
