f = open('A-small-attempt1.in', 'r')
#f = open('A-sample.in', 'r')
outpu=open('output.txt','w')
cases = int(f.readline())
for case in range(cases):
    N = int(f.readline())
    G= [f.readline() for i in range(N)]
    G=[S[:len(S)-1] for S in G]
    pos = [0 for i in range(N)]
    print(G)
    #totpos =0
    #totlen = sum([len(S) for S in G])
    goOn=True
    changes =0
    while goOn:
        fegwon = False
        for i in range(1,N):
            if G[i][pos[i]]!=G[0][pos[0]]:
                fegwon=True
        count=[0 for i in range(N)]
        for i in range(N):
            bufpos = pos[i]
            while bufpos< len(G[i]) and G[i][pos[i]]==G[i][bufpos]:
                bufpos+=1
            count[i]=bufpos-pos[i]
            pos[i]=bufpos
        count.sort()
        median = count[len(count)//2]
        changes += sum([abs(median-j) for j in count])
        incomplete = False
        for i in range(N):
            goOn&= pos[i]<len(G[i])
            if pos[i]<len(G[i]):
                incomplete =True
        if (not goOn) and incomplete:
            fegwon =True
        goOn&= not fegwon        
    result  = 'Fegla Won' if fegwon else str(changes)
    print('Case #'+ str(case+1)+": "+ result)
    outpu.write('Case #'+ str(case+1)+": "+ result+"\n")
f.close()
outpu.close()
