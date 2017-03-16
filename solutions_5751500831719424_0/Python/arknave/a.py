def raw(s):
    out = ''
    for c in s:
        if len(out) == 0 or out[-1] != c:
            out += c
    return out

def rr(l, s):
    if len(l) > 0 and l[-1][0] == s[0]:
        return l[:-1] + [(l[-1][0], l[-1][1]+1)]
    else:
        return l + [(s[0], 1)]

def breaker(s):
    return map(lambda x: x[1], reduce(rr, s, []))

def main():
    T = int(raw_input())
    for ll in xrange(1, T+1):
        N = int(raw_input())
        strs = []
        for i in xrange(N):
            strs.append(raw_input())
        reduced = raw(strs[0])
        works = True        
        for s in strs:
            if raw(s) != reduced:
                works = False
                break

        if not works:
            print "Case #%d: Fegla Won" % ll
            continue
        # go through each character of each string, and develop a min and max
        # then iterate through all of them to find the best cost for it
        ans = 0
        lastpos = 0
        broken = zip(*map(breaker, strs))
        for c in broken:
            minn, maxx = min(c), max(c)
            if minn == maxx: continue
            best = maxx*len(c)
            for i in xrange(minn, maxx+1):
                best = min(best, sum([abs(x - i) for x in c]))
            ans += best

        print "Case #%d: %d" % (ll, ans)
if __name__ == '__main__':
    main()
