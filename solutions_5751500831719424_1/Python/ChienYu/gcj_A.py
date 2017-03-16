from sys import stdin

def each_case():
    N = int(stdin.readline())
    strings = [None]
    count = [[None] for n in xrange(N)]
    for n in xrange(N):
        if n == 0:
	    for c in stdin.readline().strip():
    	        if c == strings[-1]:
                    count[n][-1] += 1
                else:
                    strings.append(c)
                    count[n].append(1)
            lstrings = len(strings)
            continue

        m = 0  # m = len(count[n])-1
        for c in stdin.readline().strip():
            if c == strings[m]:
                count[n][-1] += 1
            elif m+1 < len(strings) and c == strings[m+1]:
                m += 1
                count[n].append(1)
            else:
                return 'Fegla Won'
	if m+1 != lstrings:
            return 'Fegla Won'

    Nmove = 0
    for l in xrange(1,lstrings):
        center = sorted(count[n][l] for n in xrange(N))[N//2]
        Nmove += sum(abs(count[n][l] - center) for n in xrange(N))
    return Nmove

T = int(stdin.readline())
for t in xrange(1,T+1):
    print 'Case #{}: {}'.format(t, each_case())
stdin.close()
