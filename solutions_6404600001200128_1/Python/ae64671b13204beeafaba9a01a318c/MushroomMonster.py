__author__ = 'pcjjman'
test_input = \
"""4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9"""
test_output = \
"""Case #1: 15 25
Case #2: 0 0
Case #3: 81 567
Case #4: 181 244"""

import itertools
import math
import sys
test = False
line_number = 0

def get_input():
    global line_number
    if not test:
        return raw_input("")
    else:
        output = test_input.split("\n")[line_number]
        line_number += 1
        return output

cases = []
number_of_cases = int(get_input())
for case_number in range(number_of_cases):
    timestamp_count = int(get_input())
    timestamps = []
    timestamps_str = get_input().split(' ')
    for j in range(timestamp_count):
        timestamps.append(int(timestamps_str[j]))
    minimum_count = 0
    minimum_eating_rate = 0
    seconds_with_food_on_plate = 0
    if timestamps[0] > 0:
        seconds_with_food_on_plate += 1
    for j in range(timestamp_count)[1:]:
        if timestamps[j] > 0:
            seconds_with_food_on_plate += 1
        delta = timestamps[j-1] - timestamps[j]

        if delta > 0:
            minimum_count += delta
            minimum_eating_rate = max(minimum_eating_rate, delta)
    #second run through to count the number of pieces she could have eaten
    eat_count = 0
    for j in range(timestamp_count)[:-1]:
        eat_count += min(timestamps[j], minimum_eating_rate)
    #now determine if
    if minimum_eating_rate == sys.maxint:
        minimum_eating_rate = 0
    #print minimum_eating_rate
    print "Case #{}: {} {}".format(case_number + 1, minimum_count, eat_count)