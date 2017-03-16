

def solve(n, P):

    ans = []
    total = sum(P[k] for k in P)
    if total % 2 == 1:
        c = max(P, key=P.get)
        P[c] -= 1
        ans.append(c)

    while True:
        most = max(P, key=P.get)
        second_most = max(P, key=lambda c: -10 if c == most else P[c])
        if P[most] == 0 and P[second_most] == 0:
            break
        else:
            ans.append(most + second_most)
            P[most] -= 1
            P[second_most] -= 1
    return ' '.join(ans)


t = int(input())

for casid in range(1, t+1):
    n = int(input())
    P = {chr(65+i): int(p) for (i, p) in enumerate(input().split())}
    print("Case #%s: %s" % (casid, solve(n, P)))
