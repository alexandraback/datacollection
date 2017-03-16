import operator
# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
parties = map(chr, range(65, 91))
for i in xrange(1, t + 1):
    N = int(raw_input())
    Ps = [int(x) for x in raw_input().split(" ")]
    evacuation = []
    while sum(Ps) > 0:
        m = max(Ps)
        m_idxs = [idx for idx, j in enumerate(Ps) if j == m]
        if len(m_idxs) > 2 or len(m_idxs) == 1:
            # Ok to remove one of a big party
            Ps[m_idxs[0]] -= 1;
            evacuation.append(parties[m_idxs[0]])
        elif len(m_idxs) == 2:
            # We remove from both, which is safe since neither will have a majority
            Ps[m_idxs[0]] -=1;
            Ps[m_idxs[1]] -=1;
            evacuation.append(parties[m_idxs[0]]+parties[m_idxs[1]])

    print "Case #{}: {}".format(i, " ".join(evacuation))
