from fractions import gcd
from functools import reduce
import heapq

def lcm(a, b):
    return a*b//gcd(a,b)

with open("B-small-attempt1.in") as infile:
    with open("B.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            barbers, place = map(int, next(infile).split())
            minutes = list(map(int, next(infile).split()))

            L = reduce(lcm, minutes)
            R = sum(L//x for x in minutes)

            # Barber 0, 1, 2 ...
            barberh = [(0, i) for i in range(barbers)]

            heapq.heapify(barberh)
            place = 1 + (place-1) % R

            for c in range(place - 1):
                m, b = heapq.heappop(barberh)
                heapq.heappush(barberh, (m + minutes[b], b))

            print("Case #{}: {}".format(case, heapq.heappop(barberh)[1] + 1), file=outfile, flush=True)
