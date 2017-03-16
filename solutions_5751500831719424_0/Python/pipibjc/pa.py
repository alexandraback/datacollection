import sys

def parse_str(s):
    m = []
    m.append([s[0], 1])
    for c in s[1:]:
        if c == m[-1][0]:
            m[-1][1] += 1
        else:
            m.append([c, 1])
    return m

T = int(sys.stdin.readline())

for t in range(T):
    N = int(sys.stdin.readline())
    impossible = False
    maps = []
    for n in range(N):
        m = parse_str(sys.stdin.readline().strip())
        maps.append(m)

    m0 = maps[0]
    for m in maps:
        if len(m) != len(maps[0]):
            impossible = True
            break
        for idx in range(len(m)):
            if m[idx][0] != m0[idx][0]:
                impossible = True
                break
        if impossible:
            break

    if impossible:
        print "Case #%d: Fegla Won"%(t+1)
    else:
        moves = 0
        for idx in range(len(m0)):
            arr = []
            for m in maps:
                arr.append(m[idx][1])
            median = sorted(arr)[len(arr)/2]
            for a in arr:
                moves += abs(a-median)
        print "Case #%d: %d"%((t+1), moves)
