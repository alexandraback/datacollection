#!/usr/bin/env python3

from fractions import gcd
from itertools import cycle
import sys


def write_output_line(f, case, result):
    f.write('Case #{}: {}\n'.format(case, result))


def lcm(a, b, *ns):
    if not ns:
        return a*b / gcd(a, b)
    return lcm(a, lcm(b, *ns))


def main(input_path, output_path):
    with open(input_path) as f_in, open(output_path, 'w') as f_out:
        T = int(f_in.readline())  # number of cases

        for n in range(T):
            B, N = map(int, f_in.readline().strip().split())
            times = list(map(int, f_in.readline().strip().split()))

            state = [0 + 1 for _ in range(B)]
            result = None

            # we can serve a given number of customers in the LCM and still
            # get back to an empty state
            # so we do that here to speed things up
            times_lcm = lcm(*times)
            customers_in_lcm = [times_lcm/t for t in times]
            total_customers_in_lcm = sum(customers_in_lcm)

            # our new position in line will be less than the total in LCM
            N = N%total_customers_in_lcm
            if not N:
                N = total_customers_in_lcm

            while result is None:
                # one minute has passed; decrement state
                # might as well always do this so one barber becomes free
                delta = min(state)
                for idx, minutes in enumerate(state):
                    state[idx] = minutes - delta

                # check if any barber is now free
                for idx, barber in enumerate(state):
                    # if free, send next person in line
                    if not barber:
                        state[idx] = times[idx]

                        N -= 1
                        if not N:
                            result = idx + 1  # numbered from 1
                            break

            print('Case #{}: {}'.format(n+1, result))
            write_output_line(f_out, n + 1, result)


if __name__ == '__main__':
    if not sys.argv[2:]:
        sys.argv.append(sys.argv[1].replace('in', 'out'))

    main(sys.argv[1], sys.argv[2])
