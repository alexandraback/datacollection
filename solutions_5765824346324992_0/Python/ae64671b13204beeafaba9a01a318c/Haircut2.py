__author__ = 'pcjjman'
test_input = \
"""4
2 4
10 5
3 12
7 7 7
3 8
4 2 1
5 1000000000
25 25 25 25 25"""
test_output = \
"""Case #1: 1
Case #2: 3
Case #3: 1"""

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

cases = []
number_of_cases = int(get_input())
for case_number in range(number_of_cases):
    number_of_barbers_and_place = get_input().split(' ')
    barber_count, place_in_line = int(number_of_barbers_and_place[0]), int(number_of_barbers_and_place[1])
    barbers = []
    barber_str = get_input().split(' ')
    #print barber_count, place_in_line, barber_str
    for j in range(barber_count):
        barbers.append([int(barber_str[j]), 0, j])
    effective_haircut_rate = 0
    for barber in barbers:
        effective_haircut_rate += 1.0 / barber[0]
    #print effective_haircut_rate
    #now that we have all the barbers
    #if we iterate across time, it will take an eternity (a huge amount of time for the small set, much less the large set)
    #instead we need to leverage the fact that at a given time x, each barber will have serviced x / barber_time people
    current_time = 0
    last_barber = 0
    #print place_in_line, len(barbers)
    if place_in_line > 10 and place_in_line > len(barbers):
        time = (place_in_line-10) / effective_haircut_rate
        people_helped = 0
        for barber in barbers:
            #calculate the number of people helped
            people_barber_helped = max(int(time / barber[0]), 1)
            people_helped += people_barber_helped
            barber[1] = people_barber_helped * barber[0]
        place_in_line -= people_helped
        #print barbers, place_in_line
    if place_in_line <= 1:
        print "SOMETHING WRONG!!!"
        raise Exception("Place in line not correct!")
    while place_in_line >= 1:
        #print "Starting barber check"
        for barber in barbers:
            #print barber, current_time
            if barber[1] <= current_time:
                barber[1] = current_time + barber[0]
                place_in_line -= 1
                last_barber = barbers.index(barber)
                #print "{} Person in Line Placed in barber: {}".format(place_in_line + 1, last_barber + 1)
                break
        #if we're here then no barbers are available
        current_time = min([j[1] for j in barbers])
    print "Case #{}: {}".format(case_number + 1, last_barber + 1)