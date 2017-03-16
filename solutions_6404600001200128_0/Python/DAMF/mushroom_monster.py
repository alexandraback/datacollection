#!/usr/bin/python

import sys

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


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    N = int(line)
    mushroom_counts = [int(x) for x in f.readline().strip().split()]

    # First method is just that any time any disappear, we assume she ate them
    first_min = 0
    for i in range(1,len(mushroom_counts)):
        if mushroom_counts[i-1] > mushroom_counts[i]:
            first_min += mushroom_counts[i-1] - mushroom_counts[i]

    # Second method is to first see what is the slowest rate she could possibly be eating
    second_min = 0
    slowest_rate = 0
    for i in range(1,len(mushroom_counts)):
        if mushroom_counts[i-1] > mushroom_counts[i]:
            implied_rate = mushroom_counts[i-1] - mushroom_counts[i]
            if implied_rate > slowest_rate:
                slowest_rate = implied_rate
    # Now that we know the rate, we look at each interval. If there were enough mushrooms
    # at the beginning, we must assume she ate them. If not, we can assume she only ate
    # the ones that were there and the others got added at the last second
    for i in range(len(mushroom_counts)-1):
        if mushroom_counts[i] > slowest_rate:
            second_min += slowest_rate
        else:
            second_min += mushroom_counts[i]


    print "Case #" + str(case_num+1) + ":", first_min, second_min

