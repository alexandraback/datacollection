# coding: utf8

import sys


def main():
    t = int(sys.stdin.readline())
    for _t in range(t):
        n = int(sys.stdin.readline())
        parties = [int(x) for x in sys.stdin.readline().strip().split()]
        parties = [list(x) for x in zip(
            parties,
            list(range(len(parties))), # the party ID
        )]
        parties = sorted(parties)
        steps = []

        def add_and_log(parties, steps):
            total_parties = sum(x[0] for x in parties)
            if total_parties % 2 == 1:
                # Shall happen at most once
                steps.append([parties[-1][1]])
                parties[-1][0] -= 1
                parties = sorted(parties)
                if parties[0][0] <= 0:
                    parties = parties[1:]
            else:
                assert len(parties) >= 2
                steps.append([parties[-1][1], parties[-2][1]])
                parties[-1][0] -= 1
                parties[-2][0] -= 1
                parties = sorted(parties)
                while parties and parties[0][0] <= 0:
                    parties = parties[1:]
            return parties, steps

        def examine(parties):
            total = sum(x[0] for x in parties)
            return all(x[0] * 2 <= total for x in parties)

        while parties:
            parties, steps = add_and_log(parties, steps)
            assert examine(parties)

        steps = [
            ''.join([chr(ord('A') + y) for y in x])
            for x in steps
        ]

        print('Case #%s: %s' % (_t + 1, ' '.join(steps)))


if __name__ == '__main__':
    main()
