
ts = int(raw_input())

for t in range(ts):
    print "Case #{}:".format(t+1),

    n  = int(raw_input())

    ps = [int(x) for x in raw_input().split(" ")]
    
    m = {}
    for i in range(n):
        m[unichr(ord('A')+i)] = ps[i]

    sol = []
    while len(m.keys()) > 0:
        mm = max(m.keys(), key=lambda x: m[x])
        s = sum(m.values())

        assert m[mm] <= (s-m[mm])

        if len(m.keys()) == 1 and m[m.keys()[0]] == 1:
            sol += [m.keys()[0]]
            break
        else:
            l = sorted(m.keys(), key=lambda x: m[x], reverse=True)
            a = l[0]
            m[a] -= 1

            if m[a] > m[l[1]]:
                b = a
            else:
                b = l[1]

            if m[a] == 0: del m[a]

            mm = max(m.keys(), key=lambda x: m[b]-1 if x == b else m[x])
            s = sum(m.values())

            if len(m.keys()) == 1 or (mm != b and m[mm] <= (s-m[mm]-1)):
                m[b] -= 1
                if a != b and m[b] == 0: del m[b]
                sol += [a+b]
            else:
                sol += [a]
    print " ".join(sol)
