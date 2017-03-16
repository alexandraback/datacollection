from sys import stdin as IN
for _ in range(int(IN.readline())):
    print "Case #%s:" % (_+1),
    IN.readline()
    parties = map(int, IN.readline().strip().split())
    n = ""
    answer = []
    while True:
        chosen = None
        m = max(parties)
        if m == 0:
            break
        for _ in range(len(parties)):
            if parties[_] == 0:
                continue
            if parties[_] == m:
                chosen = _
        if sum(parties) == 3 and not n:
            if len(n) == 1:
                answer += [n]
                n = ""
            else:
                answer += [chr(ord("A") + chosen)]
            parties[chosen] -= 1
            continue
        elif len(n) == 1:
            n += chr(ord("A") + chosen)
            answer += [n]
            n = ""
        else:
            n = chr(ord("A") + chosen)
        parties[chosen] -= 1
    print " ".join(answer)
