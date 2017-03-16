import sys
from fractions import gcd

MAX_POSSIBLE = 10**20


def get_lcm(num1, num2):
    return num1 * num2 / gcd(num1, num2)


def get_lcm_from_array(array):
    lcm = 1
    for elem in array:
        lcm = get_lcm(lcm, elem)
    return lcm


def simple_method(num_barbers, place_in_line, barber_speeds):
    lcm = get_lcm_from_array(barber_speeds)
    num_cuts_in_lcm = 0
    for speed in barber_speeds:
        num_cuts_in_lcm += lcm/speed
    place_in_line_after_mod = ((place_in_line - 1) % num_cuts_in_lcm) + 1

    barber_next_ready_time = [0] * num_barbers
    next_barber_index = 0
    while place_in_line_after_mod > 0:
        next_barber_index = 0
        for ii in range(1, num_barbers):
            if barber_next_ready_time[ii] < barber_next_ready_time[next_barber_index]:
                next_barber_index = ii
        barber_next_ready_time[next_barber_index] += barber_speeds[next_barber_index]
        place_in_line_after_mod -= 1
    return next_barber_index + 1


def started_cuts_after_n_seconds(n, barber_speeds):
    started_cuts = 0
    for speed in barber_speeds:
        started_cuts += n/speed + 1
    return started_cuts


def find_best(n, barber_speeds):
    lower_bound = 0
    upper_bound = MAX_POSSIBLE
    lower_bound_completed_cuts = 0
    while lower_bound < upper_bound - 1:
        mid_point = (lower_bound + upper_bound) / 2
        started_cuts = started_cuts_after_n_seconds(mid_point, barber_speeds)
        if started_cuts >= n:
            upper_bound = mid_point
        else:
            # if started_cuts > lower_bound_completed_cuts:
            #     lower_bound = mid_point
            #     lower_bound_completed_cuts = started_cuts
            # else:
            #     upper_bound = mid_point
            lower_bound = mid_point

    return lower_bound





f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    num_barbers, place_in_line = map(int, f.readline().strip().split())
    barber_speeds = map(int, f.readline().strip().split())

    time = find_best(place_in_line, barber_speeds)
    completed_cuts = started_cuts_after_n_seconds(time, barber_speeds)
    indexes_free = []
    for ii in range(len(barber_speeds)):
        speed = barber_speeds[ii]
        if (time + 1) % speed == 0:
            indexes_free.append(ii)


    print "Case #%d: " % (test + 1), indexes_free[place_in_line - completed_cuts - 1] + 1