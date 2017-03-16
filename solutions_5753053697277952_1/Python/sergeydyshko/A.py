CurrentPathIn = "input"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())

for t in range(T):
    n = int(fr.readline())
    a = list(map(int, fr.readline().split()))
    s = [chr(ord('A') + x) for x in range(n)]

    res = ""
    while max(a)>0:
        tmp = list(zip(a,s))
        tmp.sort(key = lambda x:x[0])
        a, s = zip(*tmp)
        a = list(a)
        s = list(s)
        if a[len(a)-1] - a[len(a)-2]>=2:
            res+=str(s[len(a)-1])+str(s[len(a)-1])+ " "
            a[len(a)-1]-=2
        elif a[len(a)-1] - a[len(a)-2]==1:
            res+=str(s[len(a)-1])+ " "
            a[len(a)-1]-=1
        else:
            if sum(a)!=3:
                res+=str(s[len(a)-1])+ str(s[len(a)-2])+" "
                a[len(a)-1]-=1
                a[len(a)-2]-=1
            else:
                res+=str(s[len(a)-1])+" "
                a[len(a)-1]-=1
                
    res = res[:-1]
    fw.write("Case #"+str(t+1)+": "+str(res)+"\n")
fr.close()
fw.close()
