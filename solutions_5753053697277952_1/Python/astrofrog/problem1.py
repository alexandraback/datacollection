# Author: Thomas P. Robitaille
# Executed using Python 3

import string
import numpy as np

ALL_PARTIES = np.array(list(string.ascii_uppercase))


def check_no_majority(numbers):
    total = numbers.sum()
    if total == 0:
        return
    frac = numbers / total
    if np.any(frac > 0.5):
        raise Exception("One party has absolute majority")


def split_pairs(numbers):
    if len(numbers) == 0:
        return []
    else:
        return numbers.reshape(-1,2).tolist()


with open('A-large.in') as f:
    T = int(f.readline())
    for i in range(T):
        N = int(f.readline())
        numbers = np.array([int(x) for x in f.readline().strip().split()])
        order = np.argsort(numbers)[::-1]
        parties = ALL_PARTIES[:N][order]
        numbers = numbers[order]
        print("Case #{0}:".format(i + 1), end="")
        for limit in range(numbers[0], 0, -1):
            indices = np.where(numbers >= limit)[0]
            if len(indices) % 2 == 0:
                groups = split_pairs(indices)
            else:
                groups = [indices[0:1]] + split_pairs(indices[1:])
            for group in groups:
                evacuate = "".join(parties[x] for x in group)
                numbers[group] -= 1
                check_no_majority(numbers)
                print(" " + evacuate, end="")
        print("")
