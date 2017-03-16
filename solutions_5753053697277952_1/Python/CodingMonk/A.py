import math
import itertools
from collections import Counter
from collections import deque


T = int(raw_input())

for case_no in xrange(1, T + 1):
    ans = []

    N = int(raw_input())
    P = map(int, raw_input().split())

    total = sum(P)
    while total:
        max_num = max(P)
        count = P.count(max_num)
        index = P.index(max_num)
        if count == 1:
            total -= 1
            P[index] -= 1
            ans.append(chr(index+65))
        elif count == 2:
            total -= 2
            P[index] -= 1
            index2 = P.index(max_num)
            P[index2] -= 1
            ans.append(chr(index+65) + chr(index2+65))
        else:
            total -= 1
            P[index] -= 1
            ans.append(chr(index+65))


    print 'Case #{}: {}'.format(case_no, " ".join(ans))