T = eval(input())
for t in range(1,1+T):
    print("Case #{}:".format(t),end='')
    N = eval(input())
    P = list(map(int,input().split(' ')))
    total = sum(P)
    output = ''
    while(total > 0):
        acount = 0
        for i in range(N):
            accept = True
            while(accept):
                tempP = list(P)
                tempP[i] -= 1
                tempH = (total-1)/2
                for j in range(N):
                    if (i==j):continue
                    if (tempP[j] > tempH):
                        accept = False
                        break
                if (accept):
                    print('',chr(ord('A')+i),end='')
                    acount += 1
                    total -= 1
                    if (total == 0): break
                    P = tempP
            if (total == 0): break
        if (acount == 0):
            for i in range(N):
                end = False
                for j in range(N):
                    tempP = list(P)
                    tempP[i] -= 1
                    tempP[j] -= 1
                    tempH = (total-2)/2
                    accept = True
                    for k in range(N):
                        if (tempP[k] > tempH):
                            accept = False
                            break;
                    if (accept):
                        print('',chr(ord('A')+i)+chr(ord('A')+j),end='')
                        total -= 2
                        P = tempP
                        end = True
                        break
                if (end):break
    print()
