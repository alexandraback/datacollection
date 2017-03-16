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

    #~ if case_id == 65:
        #~ print(strings)

    r = -1
    if N == -1:
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
    else:
        positions = [0 for i in range(0, N)]
        r = 0
        isOk = True
        while isOk:
            cur_char = None
            counts = []
            for i in range(0, N):
                j = positions[i]
                s = strings[i]
                if j >= len(s) and cur_char is not None:
                    r = 'Fegla Won'
                    isOk = False
                    break
                if j < len(s):
                    if cur_char is not None:
                        if cur_char != s[j]:
                            r = 'Fegla Won'
                            isOk = False
                            break
                    else:
                        if i > 0:
                            r = 'Fegla Won'
                            isOk = False
                            break
                        cur_char = s[j]
                    count_idx = 0
                    while j < len(s) and s[j] == cur_char:
                        if count_idx >= len(counts):
                            counts.append(0)
                        counts[count_idx] += 1
                        count_idx += 1
                        j += 1
                    positions[i] = j
            if cur_char is None or not isOk:
                break
            #~ print('---')
            #~ print(positions)
            #~ print(counts)
            # Process counts - block of same chars.
            best_n = sys.maxint
            remain_sum = sum(counts)
            cur_n = 0
            low_n = counts[0]
            isLog = cur_char == 'o'
            for i in range(0, len(counts)-1):
                remain_sum -= counts[i]
                best_n = min(best_n, cur_n + remain_sum)
                cur_n += low_n - counts[i+1]
            best_n = min(best_n, cur_n)
            r += best_n
            #~ if len(counts) > 1:
                #~ print(str.format('cur_char = {0}', cur_char))
                #~ print(positions)
                #~ print(counts)
                #~ print(best_n)


    print(str.format('Case #{0}: {1}', case_id, r))
