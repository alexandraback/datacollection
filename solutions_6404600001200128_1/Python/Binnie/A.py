import sys


def minimum_way_1(mushroom_array):
    current_total = 0
    for ii in range(1, len(mushroom_array)):
        current_total += max(0, mushroom_array[ii-1] - mushroom_array[ii])
    return current_total


def minimum_way_2(mushroom_array):
    biggest_gap = 0
    for ii in range(1, len(mushroom_array)):
        biggest_gap = max(biggest_gap, mushroom_array[ii-1] - mushroom_array[ii])

    total = 0
    for ii in range(len(mushroom_array) - 1):
        total += min(biggest_gap, mushroom_array[ii])

    return total


f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    N = int(f.readline().strip())
    mushrooms = map(int, f.readline().strip().split())

    print "Case #%d: " % (test + 1), minimum_way_1(mushrooms), minimum_way_2(mushrooms)