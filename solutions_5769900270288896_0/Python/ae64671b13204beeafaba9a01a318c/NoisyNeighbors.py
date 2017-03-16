test_input = \
"""5
2 3 6
4 1 2
3 3 8
5 2 0
1 16 16"""
test_output = \
"""Case #1: 7
Case #2: 0
Case #3: 8
Case #4: 0"""

import itertools
import math
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

case_number = 1

def get_unhappiness(R, C, filled):
    house = [[0 for x in range(R)] for x in range(C)]
    x_index = 0
    y_index = 0
    for value in filled:
        if value > 0:
            house[x_index][y_index] = 1
        y_index += 1
        if y_index >= len(house[0]):
            y_index = 0
            x_index += 1
    #now we count the unhappiness
    #we only need to look at each intersection
    #first we'll look at the x's
    unhappiness = 0
    for x in range(len(house) - 1):
        for y in range(len(house[0])):
            if house[x][y] == 1 and house[x+1][y] == 1:
                unhappiness += 1
    #next we'll look at the y's
    for x in range(len(house)):
        for y in range(len(house[0]) - 1):
            if house[x][y] == 1 and house[x][y+1] == 1:
                unhappiness += 1
    return unhappiness

def possible_input_values(total, filled):
    output = []
    for value in itertools.product([0, 1], repeat=total):
        if sum(value) == filled:
            output.append(value)
    return output

cases = []
number_of_cases = int(get_input())
for i in range(number_of_cases):
    case_str = get_input().split(' ')
    #print case_str
    cases.append([int(case_str[0]), int(case_str[1]), int(case_str[2])])
for case in cases:
    #print "Case {}, target: {}".format(case_number, case)
    #case_number += 1
    min_unhappiness = 21712893712398712398
    r, c, n = case[0], case[1], case[2]
    if n == 0:
        min_unhappiness = 0
    else:
        for input_value in possible_input_values(r*c, n):
            min_unhappiness = min(min_unhappiness, get_unhappiness(r, c, input_value))
    print "Case #{}: {}".format(case_number, min_unhappiness)
    case_number += 1