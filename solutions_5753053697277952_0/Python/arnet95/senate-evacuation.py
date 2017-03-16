from string import ascii_uppercase


def f(N, l):
    s = ascii_uppercase[:N]
    d = {}
    for i in xrange(N):
        d[s[i]] = l[i]
    num_senators = sum(l)
    ret_str = ""
    while num_senators > 0:
        m = max(d.values())
        if d.values().count(max(d.values())) == 2 and d.values().count(0) == N - 2:
            count = 2
            for key in d:
                if count == 0:
                    break
                if d[key] == m:
                    ret_str += key
                    d[key] -= 1
                    count -= 1
            num_senators -= 2
        else:
            for key in d:
                if d[key] == m:
                    ret_str += key
                    d[key] -= 1
                    break
            num_senators -= 1
        ret_str += " "
    return ret_str[:-1]

for i in xrange(int(raw_input())):
    N = int(raw_input())
    l = [int(w) for w in raw_input().split()]
    print "Case #%d: %s" % (i+1, f(N, l))
