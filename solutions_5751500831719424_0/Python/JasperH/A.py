def solve(testnum):
    n = int(input())
    l = [input() for i in range(n)]
    l2 = []
    for s in l:
        l2.append([])
        prevchar = s[0]
        count = 1
        for c in s[1:]:
            if c == prevchar:
                count += 1
            else:
                l2[-1].append((prevchar,count))
                prevchar = c
                count = 1
        l2[-1].append((prevchar,count))
    #print(l2)
    s = ''.join([p[0] for p in l2[0]])
    for pl in l2:
        if ''.join([p[0] for p in pl]) != s:
            print("Case #%d: Fegla Won"%testnum)
            return
    bestpl = [(l2[0][i][0],int(round(sum([pl[i][1] for pl in l2])/len(l2))))
              for i in range(len(l2[0]))]
    def cost(pl):
        out = 0
        for pl2 in l2:
            assert len(pl) == len(pl2)
            out += sum([abs(pl2[i][1]-pl[i][1]) for i in range(len(pl))])
            #print(pl,pl2,sum([abs(pl2[i][1]-pl[i][1]) for i in range(len(pl))]))
        return out
    best = cost(bestpl)
    #best = min([cost(pl) for pl in l2])
    print("Case #%d: %d"%(testnum,best))

for i in range(int(input())): solve(i+1)
