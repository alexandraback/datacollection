#!/usr/bin/python

import sys
from heapq import *

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [B, N] = line.split()
    [B, N] = [int(B), int(N)]
    minutes = [int(x) for x in f.readline().strip().split()]
    minute_block = lcmm(*minutes)
    num_customers_per_block = sum([minute_block/m for m in minutes])
    N = N%num_customers_per_block
    if N == 0:
        N = num_customers_per_block

    answer = -1
    heap = []
    if N <= B:
        answer = N
    else:
        current_customer = 1
        while current_customer <= B:
            heappush( heap, (minutes[current_customer-1], current_customer-1))
            current_customer += 1
        while current_customer < N:
            next_barber_minutes, next_barber = heappop(heap)
            heappush( heap, (next_barber_minutes + minutes[next_barber], next_barber ))
            current_customer += 1
        answer = heappop(heap)[1]+1
            

    print "Case #" + str(case_num+1) + ":", answer

