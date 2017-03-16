infile = 'A-large.in'
outfile = 'Alarge-out.txt'

f = open(infile, 'r')
out = open(outfile, 'w')
T = int(f.readline())

for m in range(T):
    M = int(f.readline())
    a = []
    letters = None
    flag = True
    for i in range(M):
        s = f.readline().strip()
        l = []
        count = []
        ch = None
        for c in s:
            if c!=ch:
                ch = c
                l.append(ch)
                count.append(1)
            else:
                count[-1]+=1
        if letters!=None:
            if ''.join(letters)!=''.join(l):
                flag = False
        else:
            letters = l
        a.append(count)
    print a, flag
    ans = 0
    if flag:
        L = len(a[0])
        for j in range(L):
            ar = [a[k][j] for k in range(M)]
            ar.sort()
            sum = 0
            for k in ar:
                sum+=abs(ar[int(M/2)]-k)
            ans+=sum
    print ans


    out.write('Case #'+str(m+1)+': ')
    if flag:
        out.write(str(ans)+'\n')
    else:
        out.write('Fegla Won'+'\n')

out.close()
