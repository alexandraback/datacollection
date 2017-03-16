#!/usr/bin/python

import sys

def delete_prev(strings, i, prev):
    res = []
    for s in strings:
        if i < len(s) and s[i] == prev:
            first = s[:i] if i > 0 else ''
            last = s[i+1:] if i < len(s)-1 else ''
            res.append(first + last)
        else:
            res.append(s)
    return res

def double_prev(strings, i, prev):
    res = []
    for s in strings:
        if i >= len(s) or s[i] != prev:
            res.append(s[:i] + prev + s[i:])
        else:
            res.append(s)
    return res

def solve_test_case(strings):
    max_len = max([ len(s) for s in strings ])
    prev = chr(0)
    total = 0
    i = 0
    while True:
        counts = {}
        for s in strings:
            ch = '#' if i >= len(s) else s[i]
            if ch not in counts:
                counts[ch] = 0
            counts[ch] += 1
        if len(counts) == 1 and '#' in counts:
            break
        elif prev not in counts and len(counts) > 1:
            return 'Fegla Won'
        elif prev in counts and len(counts) > 1:
            num_prev = counts[prev]
            if num_prev <= len(strings) / 2:
                total += num_prev
                strings = delete_prev(strings, i, prev)
            else:
                total += len(strings) - num_prev
                strings = double_prev(strings, i, prev)
                i += 1
        else:
            prev = s[i]
            i += 1
    lengths = set(len(s) for s in strings)
    return str(total) if len(lengths) == 1 else 'Fegla Won'

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        N = int(f.readline().strip())
        strings = []
        for k in range(0,N):
            strings.append(f.readline().strip())
        print 'Case #%d: %s' % (i, solve_test_case(strings))

if __name__ == '__main__':
    main()
