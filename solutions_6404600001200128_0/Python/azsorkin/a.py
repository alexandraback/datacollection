#! /usr/bin/env python


def main():
    num_cases = int(raw_input())
    for case in range(1, num_cases + 1):
        num_mushrooms = int(raw_input())
        mushrooms = map(int, raw_input().split())
        delta = 0
        delta = max(x - x1 for x, x1 in (zip(mushrooms, mushrooms[1:])))
        m1 = m2 = 0
        for x, x1 in zip(mushrooms, mushrooms[1:]):
            m1 += max(x - x1, 0)
            m2 += min(x, delta)
        print "Case #{}: {} {}".format(case, m1, m2)

if __name__ == '__main__':
    main()
