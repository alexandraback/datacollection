#!/usr/bin/env python3

import sys


def write_output_line(f, case, result):
    f.write('Case #{}: {}\n'.format(case, result))


def main(input_path, output_path):
    with open(input_path) as f_in, open(output_path, 'w') as f_out:
        T = int(f_in.readline())  # number of cases

        for n in range(T):
            N = int(f_in.readline())
            ms = list(map(int, f_in.readline().strip().split()))

            # eat any number at any time
            # minimum is the difference between consecutive times
            # note that this only applies if there are *less* on the plate
            # at the next timestep
            min_any = 0
            for prev, now in zip(ms[:-1], ms[1:]):
                if prev > now:
                    min_any += prev - now

            # constant rate
            # work out the largest delta in ten seconds
            # that is then the constant rate per second
            rate = 0
            for prev, now in zip(ms[:-1], ms[1:]):
                if prev > now:
                    if prev - now > rate:
                        rate = prev - now

            min_rate = 0
            for mushrooms in ms[:-1]:
                min_rate += min(mushrooms, rate)

            result = '{} {}'.format(min_any, min_rate)

            print(n+1, result)
            write_output_line(f_out, n + 1, result)


if __name__ == '__main__':
    if not sys.argv[2:]:
        sys.argv.append(sys.argv[1].replace('in', 'out'))

    main(sys.argv[1], sys.argv[2])
