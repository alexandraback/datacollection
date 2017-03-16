#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def way1(ms):
    ans = 0
    for i in range(len(ms)-1):
        if ms[i] > ms[i+1]:
           ans += ms[i] - ms[i+1]
    return ans

def way2(ms):
    mx_rate = 0
    for i in range(len(ms)-1):
        if ms[i] > ms[i+1]:
           mx_rate = max(mx_rate, ms[i] - ms[i+1])

    ans = 0
    for i in range(len(ms)-1):
        ans += min(ms[i], mx_rate)
    
    return ans

def solve():
    N = int(input())
    ms = list(map(int,input().split()))
    return way1(ms), way2(ms)

def main():
    T = int(input())
    for t in range(T):
        a1,a2 = solve()
        print ("Case #" + str(t+1) + ":", a1, a2);

main()

