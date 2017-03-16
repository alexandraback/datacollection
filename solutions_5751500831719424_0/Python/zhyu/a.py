def minimal(s):
    res = ''
    for idx, ch in enumerate(s):
        if idx == 0 or ch != s[idx-1]:
            res += ch
    return res

def transfrom(s):
    res = []
    cur, l = 0, len(s)
    while cur < l:
        ch = s[cur]
        cnt = 1
        cur += 1
        while cur < l and s[cur]==ch:
            cur += 1
            cnt += 1
        res.append(cnt)
    return res

def get_num(l):
    l.sort()
    n = len(l)
    if n%2==1:
        middle = l[n/2]
    else:
        middle = (l[n/2] + l[n/2-1]) / 2
    return sum(map(lambda x: abs(x-middle), l))

T = input()
for cas in xrange(T):
    n = input()
    s_list = [raw_input() for _ in xrange(n)]
    dest = minimal(s_list[0])
    flag = False
    for s in s_list[1:]:
        if minimal(s) != dest:
            flag = True
            break
    if flag:
        print 'Case #{0}: Fegla Won'.format(cas+1)
        continue

    num_list = map(transfrom, s_list)
    res = 0
    l = len(num_list[0])
    for idx in xrange(l):
        res += get_num([num_list[x][idx] for x in xrange(n)])
    print 'Case #{0}: {1}'.format(cas+1, res)
