import sys
fin = open("A-small-attempt0.in","r")
fout = open("out2","w")
inp = fin.readline
out = fout.write

def find(arr):
    mina = min(arr)
    maxa = max(arr)
    save = len(arr)
    mans = 999999999
    if mina == maxa:
        return 0
    else:
        print mina,maxa
        for i in xrange(mina,maxa+1):
            ans = 0
            for j in xrange(save):
                ans += abs(i - arr[j])
            if ans < mans:
                mans = ans
    return mans

t = int(inp())
for cases in xrange(1,t+1):
    n = int(inp())
    mat = []
    valid = True
    s = inp().split()[0]
    rep = ""
    cnt = 0
    arr = []
    for i in xrange(len(s)):
        cnt+=1
        if i==0 or s[i-1] != s[i]:
            rep+=s[i]
            if i!=0:
                cnt-=1
                arr.append(cnt)
                #print "in",s[i],i,arr
                cnt = 1
    arr.append(cnt)
    mat.append(arr[:])
    
    #print rep,mat

    for i in xrange(n-1):
        s = inp().split()[0]
        trep = ""
        cnt = 0
        arr = []
        if valid:
            for j in xrange(len(s)):
                cnt+=1
                if j==0 or s[j-1] != s[j]:
                    trep+=s[j]
                    if j!=0:
                        cnt-=1
                        arr.append(cnt)
                        cnt = 1
        arr.append(cnt)
        mat.append(arr[:])
        if trep != rep:
            valid = False

    print mat,valid
    
    ans  = 0
    if not valid:
        out("Case #"+str(cases)+": "+"Fegla Won"+"\n")
    else:
        for j in xrange(len(rep)):
            arr = []
            for i in xrange(n):
                arr.append(mat[i][j])
            ans += find(arr)
        out("Case #"+str(cases)+": "+str(ans)+"\n")
fin.close()
fout.close()

