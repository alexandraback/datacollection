def solve(a):
    sum0 = 0
    tmp = [a[i-1]-a[i] for i in range(1,len(a))]
    print(tmp)
    for i in tmp:
        if i>0: sum0 += i
    sum1 = 0
    m = max(0, max(tmp))
    for i in a[:-1]:
        if i<m:
            sum1 += i
        else:
            sum1 += m
    return sum0, sum1

if __name__=='__main__':
    ans = []
    with open('A.in') as f:
        T = int(f.readline())
        for k in range(T):
            x = int(f.readline().strip('\r\n'))
            s = f.readline()
            a = [int(t) for t in s.split()]
            print(a)
            ans.append(solve(a))

    with open('output.txt','w') as f:
        for k,t in enumerate(ans):
            f.write("Case #"+str(k+1)+": "+"{0} {1}\n".format(t[0],t[1]))
