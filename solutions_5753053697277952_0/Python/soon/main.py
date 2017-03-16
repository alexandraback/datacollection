#!/usr/bin/env python3


def solve(senators_counts):
    senators = {chr(ord('A') + i): x for i, x in enumerate(senators_counts)}
    s, m = max(senators.items(), key=lambda y: y[1])
    while len([x for x in senators.values() if x == m]) == 1:
        res = s
        senators[s] -= 1
        s, m = max(senators.items(), key=lambda z: z[1])
        if len([b for b in senators.values() if b == m]) == 1 and m != 0:
            senators[s] -= 1
            res += s
        s, m = max(senators.items(), key=lambda xx: xx[1])
        yield res

    ordered_by_size = sorted(senators.items(), key=lambda xxx: xxx[::-1])
    while len(ordered_by_size) > 2:
        s, m = ordered_by_size[0]
        while m >= 2:
            yield s * 2
            m -= 2
        if m > 0:
            yield s
        ordered_by_size = ordered_by_size[1:]

            
    s1, m, s2 = ordered_by_size[0][0], ordered_by_size[0][1], ordered_by_size[1][0]

    while m > 0:
        m -= 1
        yield s1 + s2


def run_all_tests():
    cases = {
        (1, 1): ['AB'],
        (2, 2): ['AB', 'AB'],
        (3, 3): ['AB', 'AB', 'AB'],
        (4, 4): ['AB', 'AB', 'AB', 'AB'],
        (6, 1, 2, 3): ['AA', 'A', 'B', 'CC', 'AD', 'AD', 'AD'],
        (3, 2, 6, 1, 3): ['CC', 'C', 'D', 'BB', 'AA', 'A', 'CE', 'CE', 'CE'],
        (2, 2): ['AB', 'AB'],
        (3, 2, 2): ['A', 'AA', 'BC', 'BC'],
        (1, 1, 2): ['C', 'A', 'BC'],
        (2, 3, 1): ['B', 'C', 'AB', 'AB'],
        (3, 2, 3): ['BB', 'AC', 'AC', 'AC'],
        (4, 2, 3): ['A', 'BB', 'AC', 'AC', 'AC'],
        (2, 3, 3): ['AA', 'BC', 'BC', 'BC'],
        (3, 4, 2): ['B', 'CC', 'AB', 'AB', 'AB'],
        (2, 2, 3): ['C', 'AA', 'BC', 'BC'],
        (3, 1, 2): ['A', 'B', 'AC', 'AC'],
        (3, 1, 3): ['B', 'AC', 'AC', 'AC'],
        (4, 3, 2): ['A', 'CC', 'AB', 'AB', 'AB'],
        (3, 2, 1): ['A', 'C', 'AB', 'AB'],
        (2, 3, 2): ['B', 'AA', 'BC', 'BC'],
        (3, 3, 3): ['AA', 'A', 'BC', 'BC', 'BC'],
        (1, 2, 1): ['B', 'A', 'BC'],
        (2, 4, 3): ['B', 'AA', 'BC', 'BC', 'BC'],
        (2, 1, 2): ['B', 'AC', 'AC'],
        (1, 4, 3): ['B', 'A', 'BC', 'BC', 'BC'],
        (1, 3, 3): ['A', 'BC', 'BC', 'BC'],
        (1, 2, 2): ['A', 'BC', 'BC'],
        (1, 2, 3): ['C', 'A', 'BC', 'BC'],
        (1, 1, 1): ['A', 'BC'],
        (4, 3, 1): ['A', 'C', 'AB', 'AB', 'AB'],
        (3, 4, 1): ['B', 'C', 'AB', 'AB', 'AB'],
        (1, 3, 2): ['B', 'A', 'BC', 'BC'],
        (4, 4, 1): ['C', 'AB', 'AB', 'AB', 'AB'],
        (4, 2, 2): ['AA', 'AA', 'BC', 'BC'],
        # (1, 4, 4): [''],
        # (2, 1, 3): [''],
        # (4, 1, 4): [''],
        # (2, 1, 1): [''],
        # (2, 2, 4): [''],
        # (2, 2, 2): [''],
        # (3, 3, 1): [''],
        # (2, 3, 4): [''],
        # (3, 2, 4): [''],
        # (3, 1, 4): [''],
        # (2, 2, 1): [''],
        # (3, 3, 2): [''],
        # (4, 1, 3): [''],
        # (1, 3, 4): [''],
        # (2, 4, 2): [''],
    }

    for t, answer in cases.items():
        print('Running test {}, expected answer: {}'.format(t, answer))
        res = list(solve(t))
        assert res == answer, 'Given {}, expected {}, received {}'.format(t, answer, res)

    print('All tests passed')


def main():
    # run_all_tests()
    n = int(input())
    for i in range(1, n + 1):
        input()
        s = [int(x) for x in input().split()]
        print('Case #{}: {}'.format(i, ' '.join(solve(s))))


if __name__ == "__main__":
    main()
