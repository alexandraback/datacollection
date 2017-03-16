ncase = int(raw_input())
for case in range(1, ncase+1):
    r, c, n = map(int, raw_input().split(' '))
    ans = r * (c - 1) + c * (r - 1)
    if r - 2 > 0 and c - 2 > 0:
        t = (r-2)*(c-2)
        t = t if t == 1 else t / 2
        lst = [t, (r-t-2)*2+(c-t-2)*2, 2]
    elif r == 2 or c == 2:
        lst = [0, max(r, c)-2, 2]
    else:
        lst = [0, 0]
        if max(r, c) % 2 == 0:
            lst.extend([max(r, c)/2-1, 1])
        else:
            lst.extend([max(r, c)/2])
    m = r * c - n
    for idx, i in enumerate(lst):
        if m > i:
            ans -= (4-idx) * i
            m -= i
        else:
            ans -= (4-idx) * m
            m = 0
    print 'Case #%d: %d' % (case, ans)