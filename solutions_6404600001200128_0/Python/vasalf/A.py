#!/usr/bin/pypy3


def first_method(n, arr):
    res = 0
    for i in range(1, n):
        if arr[i] < arr[i - 1]:
            res += arr[i - 1] - arr[i]
    return res


def second_method(n, arr):
    rate = 0
    for i in range(1, n):
        rate = max(rate, arr[i - 1] - arr[i])
    res = 0
    for i in range(1, n):
        res += min(arr[i - 1], rate)
    return res


t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    print("Case #%d: %d %d" % (i + 1, first_method(n, arr), second_method(n, arr)))
