T = int(raw_input().strip())

letters = map(chr, xrange(65, 91))

for i in xrange(1, T + 1):
    N = int(raw_input().strip())
    pis = map(int, raw_input().strip().split())
    counts = {}

    for j, pi in enumerate(pis):
        counts[letters[j]] = pi

    sol = []
    while len(counts) > 0:
        if len(counts) == 3 and all([v == 1 for v in counts.values()]):
            keys = counts.keys()
            sol.append(keys[0])
            sol.append("".join(keys[1:]))
            break
        m = max(counts.values())
        curr = []
        for k, v in counts.iteritems():
            if v == m:
                curr.append(k)
                if len(curr) == 2:
                    break

        for c in curr:
            counts[c] -= 1
            if counts[c] == 0:
                del counts[c]
        sol.append("".join(curr))

    print "Case #%s: %s" % (i, " ".join(sol))
