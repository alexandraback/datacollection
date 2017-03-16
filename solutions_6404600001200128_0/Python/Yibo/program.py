#!/usr/bin/python2.7


f = open('input.txt', 'r')
T = int(f.readline())

def solve(arr):
    count1 = 0
    count2 = 0
    prev = arr[0]
    max_dec = 0
    for elt in arr:
        diff = prev - elt
        if elt < prev:
            count1 += diff
        if diff > max_dec:
            max_dec = diff
        prev = elt

    for elt in arr[:-1]:
        count2 += min(elt, max_dec)

    print count1, count2

for t in range(T):
    N = int(f.readline())
    arr = map(int, f.readline().rstrip().split(' '))
    assert N == len(arr)

    print "Case #" + str(t + 1) + ":",
    solve(arr)

