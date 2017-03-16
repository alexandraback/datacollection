T = int(input())

for t in range(T):
    N = int(input())

    # lists of {letter, [list of lens]}
    letters = None
    tcounts = []

    winnable = True
    for n in range(N):
        line = input()
        if not winnable:
            continue

        clets = ''
        ccounts = []
        for l in line:
            if not clets or clets[-1] != l:
                clets += l
                ccounts.append(0)
            ccounts[-1] += 1
        if letters == None:
            letters = clets

        if clets != letters:
            winnable = False
            continue

        tcounts.append(ccounts)

    if not winnable:
        print('Case #%d: Fegla Won' % (t+1))
        continue

    moves = 0
    for c in zip(*tcounts):
        median = sorted(c)[len(c)//2]
        for m in c:
            moves += abs(m-median)

    print('Case #%d: %d' % (t+1, moves))
        



        

