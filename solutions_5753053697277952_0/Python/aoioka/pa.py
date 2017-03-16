# -*- coding: utf-8 -*-

import numpy as np


def solve():
    n = int(raw_input())
    cnts = np.array(map(int, raw_input().split()))
    total = sum(cnts)
    ans = []

    while total > 0:
        idx = np.argmax(cnts)
        cnts[idx] -= 1
        total -= 1
        if total >= 2 * max(cnts):
            ans.append(chr(ord('A') + idx))
        else:
            idx2 = np.argmax(cnts)
            cnts[idx2] -= 1
            total -= 1
            if total >= 2 * max(cnts):
                ans.append(chr(ord('A') + idx) + chr(ord('A') + idx2))
            else:
                print 'wrong'

    print ' '.join(ans)


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        print 'Case #%d:' % i,
        solve()


if __name__ == '__main__':
    main()
