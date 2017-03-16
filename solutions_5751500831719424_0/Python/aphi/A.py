import sys

T = int(sys.stdin.readline())

for testNum in range(T):

    N = int(sys.stdin.readline())
    strs = []
    for n in range(N):
        strs.append(sys.stdin.readline().strip())

    charCounts = []
    for s in strs:
        charCounts.append([])

        current = []
        for i in s:
            if (not current) or (current[0] <> i):

                if current:
                    charCounts[-1].append(current)

                current = [i, 1]
            else:
                current[1] += 1

        charCounts[-1].append(current)


    base = "".join([char for char, count in charCounts[0]])
    ans = ""
    for cc in charCounts:
        this = "".join([char for char, count in cc])

        if this <> base:
            ans = "Fegla Won"

    if not ans:
        totalDistance = 0
        for i in range(len(base)):
            #print "place", i
            totals = []
            for cc in charCounts: # strings
                char, count = cc[i]
                totals.append(count)

            # candidates
            distance = 1E9
            for j in range(min(totals), max(totals) + 1):
                thisDist = sum([abs(t-j) for t in totals])
                distance = min(distance, thisDist)

            totalDistance += distance

        ans = str(totalDistance)
    
    print "Case #%d: %s"%(testNum+1, ans)