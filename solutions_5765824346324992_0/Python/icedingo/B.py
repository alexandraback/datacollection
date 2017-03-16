#!/usr/bin/env python3

import heapq

T = int(input())

def gcd(a, b):
    while b != 0:
        b, a = a % b, b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

for t in range(T):
    B, N = map(int, input().split())

    times = list(map(int, input().split()))

    l = 1
    for time in times:
        l = lcm(l, time)

    bpc = sum(l//time for time in times)

    N = (N - 1) % bpc + 1

    barberq = [(0, i) for time, i in zip(times, range(B))]

    heapq.heapify(barberq)

    for c in range(N):
        barber = heapq.heappop(barberq)
        barber = (barber[0] + times[barber[1]], barber[1])
        heapq.heappush(barberq, barber)

    print('Case #{}: {}'.format(t+1, barber[1]+1))




