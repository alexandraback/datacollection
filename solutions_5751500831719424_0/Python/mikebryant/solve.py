#!/usr/bin/env python

T = int(raw_input().strip())

def get_lines(num):
    rows = []
    for i in range(0, num):
        row = raw_input().strip()
        rows.append(row)
    return rows

def convert_to_singles(s):
    out = ''
    current = None
    for c in s:
        if c == current:
            continue
        else:
            out += c
            current = c
    return out

def convert_to_numbers(s):
    out = []
    current = None
    for c in s:
        if c == current:
            out[-1] += 1
        else:
            out.append(1)
            current = c
    return out

def calc_moves_for_sub(xs):
    xs = sorted(xs)

    #if len(xs) % 2 != 0:
    mid = xs[len(xs)//2]
    ret = (
        sum([mid-x for x in xs[:len(xs)//2]]) +
        sum(x-mid for x in xs[(len(xs)//2)+1:])
    )
    #print xs, ret
    return ret
    #else:
    #    mid =

    #return 0

for i in range(1, T+1):
    print ("Case #%d:" % i),
    lines = get_lines(int(raw_input().strip()))
    #print lines
    if len(set([convert_to_singles(s) for s in lines])) != 1:
        print "Fegla Won"
        continue
    xs = zip(*[convert_to_numbers(s) for s in lines])
    print sum(calc_moves_for_sub(sub) for sub in xs)