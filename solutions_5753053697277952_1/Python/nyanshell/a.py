import string

def sol():
    n = input()
    p = input()
    p = [int(_p) for _p in p.split(' ')]
    tot = sum(p)
    ans = []
    # string.ascii_uppercase
    while tot > 0:
        a = None
        b = None
        max_p = max(p)
        max_p_cnt = sum(int(max_p == px) for px in p)
        # print(max_p, max_p_cnt, p, tot)
        if max_p_cnt == 1 or max_p_cnt > 2:
            for i in range(len(p)):
                if p[i] == max_p:
                    p[i] = p[i] - 1
                    a = i
                    tot -= 1
                    break
        elif max_p_cnt == 2:
            for i in range(len(p)):
                if p[i] == max_p:
                    # print(tot, i, p[i])
                    p[i] = p[i] - 1
                    if a is None:
                        a = i
                    else:
                        b = i
                    tot -= 1
        # print(a, b, ans)
        a = string.ascii_uppercase[a]
        if b: a = a + string.ascii_uppercase[b]
        ans.append(a)
    return ' '.join(ans)


t = int(input())
for i in range(t):
    print("Case #%s: %s" % (i+1, sol()))
