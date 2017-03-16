import sys

N = int(sys.stdin.readline())

ma = [chr(65 + i) for i in range(26)]

def evacuate(N, sen):
    al = sum(sen)
    sen = [ [sen[j], ma[j]] for j in  range(len(sen))]
    while al:
        sen.sort(reverse=True)
        #print(sen)
        if sen[0][0] == 1:
            for k in range(N):
                if sen[k][0] == 0:
                    break
            if sen[-1][0] != 0:
                k = N
            for j in range(k-2):
                yield sen[j][1]
            yield sen[k-2][1]+sen[k-1][1]
            return 
        if (al-1)/sen[1][0] > 0.5:
            yield sen[0][1]+sen[1][1]
            sen[0][0] -= 1
            sen[1][0] -= 1
            al -= 2
        else:
            yield sen[0][1]
            sen[0][0] -= 1
            al -= 1


for case in range(N):
    n = int(sys.stdin.readline().strip())
    sen = list(map(int, sys.stdin.readline().strip().split()))
    
    print("Case #" + str(case + 1) + ":", " ".join(map(str, evacuate(n, sen))))  
