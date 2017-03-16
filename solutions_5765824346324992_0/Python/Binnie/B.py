import sys
from fractions import gcd


def get_lcm(num1, num2):
    return num1 * num2 / gcd(num1, num2)


def get_lcm_from_array(array):
    lcm = 1
    for elem in array:
        lcm = get_lcm(lcm, elem)
    return lcm



f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    num_barbers, place_in_line = map(int, f.readline().strip().split())
    barber_speeds = map(int, f.readline().strip().split())
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


    print "Case #%d: " % (test + 1), next_barber_index + 1