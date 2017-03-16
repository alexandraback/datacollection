from pprint import pprint
import sys

import operator


def argmax(values):
    max_index, max_value = max(enumerate(values), key=operator.itemgetter(1))
    return max_index, max_value


def leave(counts, a, b=None):
    new_counts = [i for i in counts]
    new_counts[a] -= 1
    if b:
        new_counts[b] -= 1
    total = sum(new_counts)
    maj = total // 2

    if any(i > maj for i in new_counts):
        raise ValueError()
    # print(new_counts, maj)
    return new_counts


def output(n, counts):
    total = sum(counts)
    rounds = []

    def lleave(a, b=None):
        nonlocal counts, total, rounds
        counts = leave(counts, a, b)
        if not b:
            total -= 1
            rounds += [(a,)]
        else:
            total -= 2
            rounds += [(a, b)]

    while total > 0:
        max_index, max_value = argmax(counts)

        o = [i for i in counts]
        o[max_index] -= 1
        max_index2, max_value2 = argmax(o)

        try:
            lleave(max_index, max_index2)
        except ValueError:
            lleave(max_index)

    return " ".join("".join(chr(65 + i) for i in left) for left in rounds)


if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        n = int(sys.stdin.readline())
        counts = list(map(int, sys.stdin.readline().strip().split()))
        answer = output(n, counts)
        print("Case #%d: %s" % (t + 1, answer))
