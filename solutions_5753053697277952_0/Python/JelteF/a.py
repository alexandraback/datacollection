#!/usr/bin/python3.5

from collections import Counter


def next_line_to_ints(lines):
    return map(int, next(lines).split(' '))

f_in = open('a.in')
f_out = open('a.out', 'w')

lines = (i for i in f_in.read().splitlines())
t = int(next(lines))

for case in range(1, t+1):
    n = int(next(lines))
    counts = next_line_to_ints(lines)
    party_names = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[:n]
    counter = Counter()
    for c, name in zip(counts, party_names):
        counter[name] = c

    ops = []

    while counter and counter.most_common(1)[0][1]:
        try:
            one, two, three = counter.most_common(3)
        except ValueError:
            one, two = counter.most_common(3)
            three = None

        counter[one[0]] -= 1

        if one[1] == two[1] and (three is None or not one[1] == three[1]):
            counter[two[0]] -= 1
            ops.append(one[0] + two[0])
        else:
            ops.append(one[0])

    ops = ' '.join(ops)
    f_out.write('Case #{}: {}\n'.format(case, ops))
