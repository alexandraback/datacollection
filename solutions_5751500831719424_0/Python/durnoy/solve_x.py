from __future__ import print_function
import sys

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")


T = int(f.readline().strip())

for case_id in range(1, T+1):
    N = int(f.readline().strip())
    strings = []
    for i in range(0, N):
        strings.append(f.readline().strip())
    #~ print(N)
    #~ print(strings)

    r = -1
    if N == 2:
        r = 0
        a = strings[0]
        b = strings[1]
        i = 0
        j = 0
        while i < len(a) and j < len(b):
            if a[i] != b[j]:
                r = 'Fegla Won'
                break
            na = 1
            nb = 1
            while i < len(a)-1 and a[i] == a[i+1]:
                i += 1
                na += 1
            while j < len(b)-1 and b[j] == b[j+1]:
                j += 1
                nb += 1
            r += abs(na-nb)
            i += 1
            j += 1

        if i < len(a) or j < len(b):
            r = 'Fegla Won'

    print(str.format('Case #{0}: {1}', case_id, r))
