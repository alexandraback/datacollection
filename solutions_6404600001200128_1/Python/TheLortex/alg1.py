n = int(input())

def alg(liste):
    s, maxdeniv = 0, 0
    c = liste[0]
    for i in range(len(liste)):
        deniv = c - liste[i] 
        maxdeniv = max(maxdeniv, deniv)
        s += max(0, deniv)
        c = liste[i]


    c = liste[0]

    s2 = 0


    for i in range(len(liste)-1):
        s2 += min(liste[i],maxdeniv) 



    return s,s2


for k in range(n):
    s = int(input())
    data = [int(x) for x in input().split()] 
    s1,s2 = alg(data)
    print ("Case #",k+1,": ",s1," ",s2,sep="")



