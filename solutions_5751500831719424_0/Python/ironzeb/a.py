import sys

T = int(sys.stdin.readline())

def solve(strings):
    pattern = []
    mins = []
    counts = []
    prev = ''
    for c in strings[0]:
        if prev != c:
            pattern.append(c)
            mins.append(0)
        mins[-1] += 1
        prev = c

    for s in strings:
        prev = ''
        i = -1
        cnt = 0
        counts.append([])
        for c in s:
            if prev != c:
                if prev != '':
                    counts[-1].append(cnt)
                    if cnt < mins[i]:
                        mins[i] = cnt
                i += 1
                cnt = 0
            cnt +=1
            prev = c
            if i >= len(pattern) or pattern[i] != c:
                return "Fegla Won"
        counts[-1].append(cnt)
        if cnt < mins[i]:
            mins[i] = cnt
    l = len(counts[0])
    for c in counts:
        if len(c) != l:
            return "Fegla Won"
    moves = 0
    cnts = zip(*counts)
    for c in cnts:
        mid = sorted(c)[len(c)/2]
        for i in c:
            moves += abs(i - mid)

    return moves

for t in range(T):
    N = int(sys.stdin.readline().strip())
    strings = []
    for n in range(N):
        strings += [sys.stdin.readline().strip()]

    print "Case #{}: {}".format(t+1, solve(strings))