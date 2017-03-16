# python A.py < A-small-attempt0.in > A-small-attempt0.out
# 
# list(raw_input()) # List of chars
# [int(n) for n in raw_input().split()] # List of ints

from fractions import gcd
from math import ceil

def lcm(a, b):
    return a * b / gcd(a, b)

if __name__ == "__main__":
    testcases = input()
    
    for case in xrange(1, testcases+1):
        
        row1 = [int(n) for n in raw_input().split()]
        my_place = row1[1] - 1
        barbers = [int(n) for n in raw_input().split()]
        
        # Return the number of people taken and the list of next barbers free at time t
        def sample(t):
            num_taken = [int(ceil(float(t) / m)) for m in barbers]
            time_until = [(m - t % m) % m for m in barbers]
            min_time_until = min(time_until)
            return (sum(num_taken), [i+1 for i, x in enumerate(time_until) if x == min_time_until])
        
        loop_time = reduce(lcm, barbers)
        loop_people = sample(loop_time)[0]
        my_place %= loop_people
        r = [0, loop_time - 1]
        barber = 0
        while r[1] - r[0] >= 0:
            mid = (r[1] + r[0]) / 2
            taken, free_barbers = sample(mid)
            if taken <= my_place and taken + len(free_barbers) > my_place:
                barber = free_barbers[my_place - taken]
                break
            elif taken > my_place:
                r[1] = mid - 1
            else:
                r[0] = mid + 1
        
        print("Case #%i: %s" % (case, str(barber)))
