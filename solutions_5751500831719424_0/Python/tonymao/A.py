from collections import OrderedDict
fin = open('A-small-attempt0.in.txt','r')
#fin = open('A-large-practice.in.txt', 'r')
#fin = open('input.txt')

fout = open('output.txt', 'w')

numCases = int(fin.readline())

for cases in range(numCases):
    N = [int(x) for x in fin.readline().split()]
    N = N[0]
    Str = [None]*N
    nStr = [None]*N
    for i in range(N):
        Str[i] = fin.readline().rstrip()
        nStr[i] = "".join(OrderedDict.fromkeys(Str[i]))

    temp = True
    for i in range(N):
        for j in range(i, N):
            if nStr[i] != nStr[j]:
                fout.write("Case #" + str(cases+1) + ": "+"Fegla Won"+'\n')
                temp = False
                break
        if temp == False:
            break

    pt = [0]*N
    numlst = [-1]*N
    sum = 0
    if temp == True:
        newStr = nStr[0]
        for c in newStr:
            for i in range(N):
                numlst[i] = numlst[i] + 1
                pt[i] = pt[i] +1
                while(pt[i]<len(Str[i]) and Str[i][pt[i]] == c):
                    numlst[i] = numlst[i] + 1
                    pt[i] = pt[i] +1
            sorts = sorted(numlst)
            median = sorts[(int)(len(numlst)/2)]
            for i in range(N):
                sum = sum + abs(numlst[i] - median)
            numlst = [-1]*N
        fout.write("Case #" + str(cases+1) + ": "+str(sum)+'\n')


    #fout.write("Case #" + str(cases+1) + ": "+'\n')

fin.close()
fout.close()