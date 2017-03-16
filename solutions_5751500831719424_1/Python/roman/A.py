#!/usr/bin/python2.7
import sys

def is_valid(aa, n, m):
    for a in aa:
        if len(a) != m:
            return False
    for i in range(1, n):
        for j in range(m):
            ch1, cnt1 = aa[0][j]
            ch2, cnt2 = aa[i][j]
            if ch1 != ch2:
                return False
    return True

def get_move_cnt(xs, z):
    res = 0
    for x in xs:
        res += int(abs(x - z))
    return res

if __name__ == "__main__":
    tcn = int(sys.stdin.readline())
    for tc in range(tcn):
        n = int(sys.stdin.readline())
        aa = []
        for i in range(n):
            s = sys.stdin.readline().strip()
            cnt = 0
            ch = None
            a = []
            for i in range(len(s)):
                if ch != s[i]:
                    if ch:
                        a.append((ch, cnt))
                    ch = s[i]
                    cnt = 0
                cnt += 1
            a.append((ch, cnt))
            aa.append(a)

        m = len(aa[0])
        if not is_valid(aa, n, m):
            print "Case #" + str(tc + 1) + ": Fegla Won"
            continue

        res = 0
        for ind in range(m):
            xs = []
            for i in range(n):
                ch, cnt = aa[i][ind]
                xs.append(cnt)
            bst = n * (max(xs) + 1)
            for z in range(max(xs) + 1):
                bst = min(bst, get_move_cnt(xs, z))
            res += bst

        print "Case #" + str(tc + 1) + ":", res
