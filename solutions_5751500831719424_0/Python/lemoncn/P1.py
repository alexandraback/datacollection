fn = raw_input()
rfp = open(fn + '.in', 'r')
wfp = open(fn + '.out', 'w')
T = int(rfp.readline())
def calc(s):
    a = []
    prev = ''
    cnt = 0
    for i in s:
        if i == prev:
            cnt += 1
        else:
            if prev != '':
                a.append((prev, cnt))
            prev = i
            cnt = 1
    a.append((prev, cnt))
    return a

def dist(s, t):
    if len(s) != len(t):
        return 0x7fffffff
    sum = 0
    for i in range(len(s)):
        if s[i][0] != t[i][0]:
            return 0x7fffffff
        sum += abs(s[i][1] - t[i][1])
    return sum

def median(b, ind):
    tmp = []
    for i in b:
        tmp.append(i[ind][1])
    v = sorted(tmp)[len(tmp) / 2]
    cost = 0
    for i in tmp:
        cost += abs(v - i)
    return cost

def read_array():
    return map(lambda(x): int(x), rfp.readline().split(' '))

for k in range(T):
    n = int(rfp.readline())
    a = []
    b = []
    for i in range(n):
        s = rfp.readline().strip()
        a.append(s)
        b.append(calc(s))
    mincnt = 0x7fffffff
    for i in b:
        #i is the template
        cnt = 0
        for j in b:
            if i == j:
                continue
            r = dist(i, j)
            if r == 0x7fffffff:
                cnt = 0x7fffffff
                break
            else:
                cnt += r
        mincnt = min(cnt, mincnt)
    if mincnt == 0x7fffffff:
        ans = 'Fegla Won'
    else:
        cnt = 0
        for i in range(len(b[0])):
            cnt += median(b, i)
        ans = min(mincnt, cnt)
    result_string = 'Case #{0}: {1}\n'.format(k + 1, ans)
    wfp.write(result_string)
    print result_string