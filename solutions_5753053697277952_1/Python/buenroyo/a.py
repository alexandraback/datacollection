def add(x):
  return chr(ord('A') + x)

T=int(raw_input())
for t in xrange(1, T+1):
    N = int(raw_input())

    senators = map(int, raw_input().strip().split(' '))

    best = 0
    secondBest = 0

    bestIndex = -1
    secondBestIndex = -1

    for i in xrange(N):
        num = senators[i]
        if num > best:
            secondBest = best
            best = num
            secondBestIndex = bestIndex
            bestIndex = i
        elif num > secondBest:
            secondBest = num
            secondBestIndex = i

    res = ""
    bestLetter= add(bestIndex)
    secondBestLetter = add(secondBestIndex)

    if best != secondBest:
        diff = best - secondBest
        for i in xrange(diff /2):
            res += bestLetter + bestLetter + " "
        if diff % 2 == 1:
            res += bestLetter + " "

    for i in xrange(N):
        if i == bestIndex or i == secondBestIndex: continue
        letter = add(i)
        for j in xrange(senators[i] /2):
            res += letter + letter + " "
        if senators[i] % 2 == 1:
            res += letter + " "

    for i in xrange(secondBest):
        res += bestLetter + secondBestLetter + " "
    
    print "Case #%d: %s"% (t, res.rstrip())
