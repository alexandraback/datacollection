def simple(s):
    res = ""
    a = []
    for i in range(len(s)):
        if i == 0 or s[i] != s[i - 1]:
            res += s[i]
            a.append(1)
        else:
            a[-1] += 1
    return res, a

def equal(a):
    n = len(a[0])
    b = []
    for i in range(n):
        b.append([a[j][i] for j in range(len(a))])
    res = 0
    for i in range(n):
        x = b[i]
        mini = float("inf")
        for j in range(len(x)):
            e = 0
            for k in x:
                e += abs(k - x[j])
            mini = min(mini, e)
        res += mini
    return res

fin = open("A-large.txt", "r")
fout = open("A Large Answer.txt", "w")

t = int(fin.readline())
for cycle in range(t):
    n = int(fin.readline())
    a = []
    x = ""
    flag = True
    for i in range(n):
        s = fin.readline().rstrip()
        simp, b = simple(s)
        a.append(b)
        if i > 0 and simp != x:
            if flag:
                print("Case #", cycle + 1, ": Fegla Won", sep="", file=fout)
            flag = False
        else:
            x = simp
    if flag:
        print("Case #", cycle + 1, ": ", equal(a), sep="", file=fout)

fin.close()
fout.close()