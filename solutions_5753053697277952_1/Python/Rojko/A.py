def get_c(x):
    return chr(x+ord('A'))

def maxi(p):
    maxi = 0
    for i in range(len(p)):
        if p[i] > p[maxi]:
            maxi = i
    return maxi

T = int(input())
for t in range(1, T+1):
    n = int(input())
    p = [int(x) for x in input().split()]
    print("Case #",t,":",sep="",end="")
    suc = sum(p)
    ret = ""
    while suc > 0:
        i = maxi(p)
        pi = p[i]
        p[i] = 0
        j = maxi(p)
        kolko = min(pi,suc - 2*p[j])
        if kolko == 0 and pi == p[j] != 0:
            ret += " "+get_c(i)+get_c(j)
            p[i] = pi - 1
            p[j] -= 1
            suc -= 2
            continue
        for l in range(kolko):
            if l%2 == 0:
                ret += " "+get_c(i)
            else:
                ret+=get_c(i)
        p[i] = pi - kolko
        suc -= kolko
        
    print(ret)
