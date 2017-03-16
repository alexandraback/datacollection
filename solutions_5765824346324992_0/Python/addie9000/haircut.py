import sys
import fractions


def lcm(a, b):
    return a * b / fractions.gcd(a, b)


def solve_case(n, ms, case_number):
    barber_index = 0
    barbers = [0] * len(ms)
    cycle = reduce(lcm, ms, 1)
    n_per_cycle = 0
    for m in ms:
        n_per_cycle += cycle / m
    n2 = n % n_per_cycle
    if n2 == 0:
        n2 = n_per_cycle

    for x in range(0, n2):
        min_wait_time = min(barbers)
        if min_wait_time > 0:
            barbers = map(lambda t: t - min_wait_time, barbers)
        barber_index = barbers.index(0)
        barbers[barber_index] = ms[barber_index]

    print "Case #%d: %d" % (case_number, barber_index + 1)


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        bn = map(int, r.readline().strip().split(' '))
        ms = map(int, r.readline().strip().split(' '))

        solve_case(bn[1], ms, case_number)


if __name__ == '__main__':
    main()
