#!/usr/bin/env python
import sys
import numpy as np
from itertools import combinations

T = int(next(sys.stdin))


def unhappiness(arr):
    return np.sum(arr[:,1:] & arr[:,:-1]) + np.sum(arr[1:,:] & arr[:-1,:])


def brute_force(R, C, N):
    arr = np.zeros((R, C), dtype=bool)
    flat = arr.reshape(-1)

    min_unhappiness = 2*R*C

    for arrangement in combinations(range(R*C), N):
        flat[:] = False
        flat[list(arrangement)] = True

        min_unhappiness = min(min_unhappiness, unhappiness(arr))

    return min_unhappiness


for i, l in enumerate(sys.stdin):
    R, C, N = (int(tok) for tok in l.strip().split())

    print("Case #{}: {}".format(i+1, brute_force(R, C, N)))
