from fractions import gcd
import sys

def parse(pair):
    qpos = int(pair[0].split()[-1])
    bspeeds = map(int, pair[1].split())
    return qpos, bspeeds


def lcm(numbers):
    return reduce(lambda x, y: (x*y)/gcd(x,y), numbers, 1)

def which_b(tst):
    n, bs = tst
    barber_order = []
    for i in range(lcm(bs)):
        barber_order.extend([b for b, x in enumerate(bs) if i % x == 0])
        
    return barber_order[(n-1) % len(barber_order)] + 1

with open(sys.argv[1], "r") as fh:
    lines = fh.readlines()
    
lines = [l.strip() for l in lines[1:]]

tests = [(lines[i], lines[i+1]) for i in range(0, len(lines) - 1, 2)]
tcs = map(parse, tests)

results = map(which_b, tcs)
lines = ["Case #{}: {}".format(i+1, r) for i, r in enumerate(results)]
print lines
with open("output.txt", "w+") as fh:
    fh.write("\n".join(lines))