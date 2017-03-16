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

t = int(input())
for cycle in range(t):
    n = int(input())
    res = 0
    x = ""
    s1, s2 = input().rstrip(), input().rstrip()
    simp1, a = simple(s1)
    simp2, b = simple(s2)
    if simp1 != simp2:
        print("Case #", cycle + 1, ": Fegla Won", sep="")
    else:
        res = 0
        for i in range(len(simp1)):
            res += abs(b[i] - a[i])
        print("Case #", cycle + 1, ": ", res, sep="")
    '''
    for i in range(n):
        s = input().rstrip()
        simp, b = simple(s)
        if i > 0 and simp != x:
            print("Case #", cycle, ": Fegla Won", sep="")
            break
        else:
            x = simp
            a.append(s)
            res += abs()
    '''