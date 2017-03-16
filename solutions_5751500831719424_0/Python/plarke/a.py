f = open('a.in')
out = open('a.out', 'w+')
t = int(f.readline())
for tc in range(t):
    n = int(f.readline())
    strings = []
    for i in range(n):
        strings.append(f.readline())
    maps = []
    for s in strings:
        thismap = []
        char = s[0]
        g = 1
        for i in range(1, len(s)):
            if s[i] != char:
                thismap.append((char, g))
                char = s[i]
                g = 1
            else:
                g += 1
        maps.append(thismap)
    possible = True
    g = [maps[0][l][0] for l in range(len(maps[0]))]
    for m in maps:
        if [m[l][0] for l in range(len(m))] != g:
            possible = False
    if not possible:
        res = 'Fegla Won'
    else:
        moves = 0
        for k in range(len(maps[0])):
            best = 100000000
            for m in maps:
                nec = sum([abs(m[k][1]-m2[k][1]) for m2 in maps])
                if nec < best:
                    best = nec
            moves += best
        res = str(moves)
    out.write('Case #{0}: {1}\n'.format(tc+1, res))
