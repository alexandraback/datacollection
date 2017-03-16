import sys


def prefixlen(s, c):
    for i in xrange(len(s)):
        if s[i] != c:
            return i
    return len(s)


def main():
    f = open(sys.argv[1])
    for j in xrange(int(f.readline())):
        count = int(f.readline())
        ss = [f.readline().strip() for k in xrange(count)]
        total = 0
        ok = True
        if ss:
            while ss[0]:
                c = ss[0][0]
                ts = []
                counts = []
                for s in ss:
                    if not s:
                        ok = False
                        break
                    count = prefixlen(s, c)
                    if count == 0:
                        ok = False
                        break
                    counts.append(count)
                    ts.append(s[count:])
                if not ok:
                    break
                ss = ts

                counts.sort()
                if False:
                    m = min(sum(abs(k-c) for k in counts) for c in counts)
                    total += m

                else:
                    #counts = [c - counts[0] for c in counts]
                    tot = sum(counts)
                    size = len(counts)
                    part = 0
                    best = tot
                    prev = 0
                    for i in xrange(size):
                        c = counts[i]
                        diff = c - prev
                        tot -= (size-i) * diff
                        part += i * diff
                        best = min(best, tot+part)
                        prev = c

                    total += best

        if all(not s for s in ss):
            print "Case #%i: %i" % (j+1, total)
        else:
            print "Case #%i: Fegla Won" % (j+1)

main()
