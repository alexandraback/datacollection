import sys
rl = lambda: sys.stdin.readline().strip()

IDS = {i: chr(65 + i) for i in range(26)}

T = int(rl())
for tcase in range(1, T + 1):
    N = int(rl())
    K = map(int, rl().split())
    rets = []
    while True:
        Z = float(sum(K))
        if Z == 0.0:
            break
        f = sorted([(idx, k / (Z - 1.0)) for idx, k in enumerate(K)], key=lambda x: x[1], reverse=True)
        r = ''
        for idx, v in f:
            if v > 0.5:
                r += IDS[idx]
                K[idx] -= 1
        if not r:
            r += IDS[f[0][0]]
            K[f[0][0]] -= 1
        rets.append(r)
    # last = IDS[[idx for idx in range(len(K)) if K[idx] > 0][0]]
    # rets[-1] = rets[-1] + last
    print 'Case #%d: %s' % (tcase, ' '.join(rets))
