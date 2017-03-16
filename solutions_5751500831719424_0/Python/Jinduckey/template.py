fh = open("A-small-attempt6.in", "r")
fh2 = open("output.txt", "w")
testCases = fh.readline()

for testCase in xrange(int(testCases)):
    N = int(fh.readline())

    d = []
    good = 1
    s = []
    words = []
    for i in range(N):
        words.append(fh.readline().split()[0])
    #word = fh.readline

    for c in words[0]:
        if len(d) == 0:
            d.append([c, [1.0]])
        else:
            if d[-1][0] == c:
                d[-1][1][0] += 1.0
            else:
                d.append([c, [1.0]])
        if len(s) == 0 or s[-1] != c:
            s.append(c)
    
    for i in range(0, N):
        if i > 0:
            word = words[i]
            j = 0
            s2 = []
            for c in word:
                if j < len(d) and d[j][0] == c:
                    if len(d[j][1]) == i:
                        d[j][1].append(1.0)
                    else:
                         d[j][1][-1] += 1.0
                else:
                    j += 1
                    if j < len(d):
                        d[j][1].append(1.0)
                    else:
                        good = 0
                    
                if len(s2) == 0 or s2[-1] != c:
                    s2.append(c)
            if i > 0 and s != s2:
                good = 0
                break
            s = s2[:]
            if good == 0:
                break


    
    if good == 0:
        ans = "Fegla Won"
    else:
        ans = 0
        for b in d:
            l = b[1]
            l.sort()
            if len(l) % 2 == 1:
                median = l[(len(l) - 1) / 2]
            else:
                median = int((l[len(l)/ 2 - 1] + l[len(l)/ 2]) / 2)
            for c in l:
                ans += int(abs(median - c))

        ans = int(ans)

    fh2.write("Case #" + str(testCase + 1) + ": " + str(ans) + "\n")
    

fh.close()
fh2.close()
    
    
    
        
