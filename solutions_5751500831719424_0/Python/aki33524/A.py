INF = 10**8

fin = open("A-small-attempt0 (1).in")
fout = open("A.out", "w")
T = int(fin.readline())

for t in range(1, T+1):
    N = int(fin.readline())
    sl = []
    for i in range(N):
        sl.append("."+fin.readline()[:-1])
    
    dp = [[] for i in range(N)]
    
    for j in range(N):
        for i, c in enumerate(sl[j]):
            if 0<i and sl[j][i-1] != sl[j][i]:
                dp[j].append(sl[j][i])
    
    flag = False
    for i in range(1, N):
        if dp[i-1] != dp[i]:
            flag = True
            break
    if(flag):
        fout.write("Case #%d: Fegla Won\n" %t)
        continue
    
    dp2 = [[] for i in range(N)]
    for sli, s in enumerate(sl):
        s = s[1:]
        for c in dp[0]:
            for i, sc in enumerate(s):
                if sc != c:
                    dp2[sli].append(i)
                    s = s[i:]
                    break
                elif i == len(s)-1 and sc == c:
                    dp2[sli].append(i+1)
    
    ans = 0                
    for i in range(len(dp2[0])):
        tans = INF
        for k in range(110):
            ttans = 0
            for j in range(N):
                ttans += abs(dp2[j][i] - k)
            tans = min(tans, ttans)
        ans += tans
            
    fout.write("Case #%d: %d\n" %(t, ans))
        
    
    