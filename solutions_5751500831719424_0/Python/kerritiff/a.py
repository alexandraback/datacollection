
def cal(l):
    l.sort()
    ans = 0
    m = l[len(l)/2]
    for c in l:
        ans += abs(c - m)
    return ans

def process(s):
    s = s + '$'
    ans = []
    su = -1
    for i, c in enumerate(s):
        su += 1
        if i > 0:
            if c == s[i-1]:
                continue
            else:
                ans.append((s[i-1], su))
                su = 0
    return ans

def solve():
    n = int(input())
    ss = []

    for _ in xrange(n):
        s = raw_input()
        ss.append(process(s))


    igen = [x[0] for x in ss[0]]
    for i in xrange(1, n):
        if [x[0] for x in ss[i]] != igen:
            return 'Fegla Won'

    ans = 0
    for i in xrange(len(igen)):
        ans += cal([x[i][1] for x in ss])

    return ans

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s' % (i, solve())

if __name__ == '__main__':
    main()
