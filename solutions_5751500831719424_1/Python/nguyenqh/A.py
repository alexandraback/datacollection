import math

def reduce(s):

    L = len(s)
    c0 = s[0]
    r = c0
    count = [1]
    for i in range(1,L):
        c = s[i]
        if c in 'abcdefghijklmnopqrstuvwxyz':
            if c!=c0:
                r = r+c
                count.append(1)
        ##            print('$',r,c,cou3nt)
            else:
                count[-1] = count[-1]+1
        c0 = c
    return [r,count]            
    
##inputFile = open('A-sample.in','r')
##outputFile = open('A-sample.ou','w')
##inputFile = open('A-small-attempt0.in','r')
##outputFile = open('A-small-attempt0.ou','w')
inputFile = open('A-large.in','r')
outputFile = open('A-large.ou','w')
numTest = int(inputFile.readline())
for testid in range(1,numTest+1):
    N = int (inputFile.readline())
    A = []
    lose = False
    for i in range(N):
        s = inputFile.readline()
        r,cnt = reduce(s)
        if i==0:
            r0 = r
        if r!=r0:
            lose = True
        A.append(cnt)
##        print('$',s,r,cnt)
    if lose:
        print('Case #',testid,': Fegla Won', sep='',file=outputFile)
    else:
        L = len(cnt)
        LA = len(A)
        D = []
        for i in range(L):
            a = [A[j][i] for j in range(LA)]
            maxa = max(a)
            mina = min(a)
            mind = (maxa-mina)*LA
            for x in range(min(a),max(a)+1):
                d = 0
                for c in a:
                    if c>x:
                        d = d+c-x
                    else:
                        d = d+x-c
                if d<mind:
                    mind = d
            D.append(mind)
        print('Case #',testid,': ',sum(D), sep='',file=outputFile)


outputFile.close()
    
        
