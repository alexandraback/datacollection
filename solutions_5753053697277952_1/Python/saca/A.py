#!/usr/bin/env python3
import math, collections, itertools
from sys import stdin


def readValue(valueType):
    return valueType(stdin.readline())


def readValues(valueType):
    return list(map(valueType, stdin.readline().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


def readInput():
    n = readValue(int)
    bins = readValues(int)
    return n, bins


def checkValid(bins, total):
    for bin in bins:
        if bin[0] * 2 > total:
            return False
    return True

def solve(n, bins):
    ans = []
    total = sum(bins)
    bins = [(bin, chr(ord("A") + i)) for i, bin in enumerate(bins)]

    while total > 0:
        bins.sort(reverse=True)
        bins[0] = bins[0][0] - 1, bins[0][1]
        total -= 1

        if checkValid(bins, total):
            ans.append(bins[0][1])
        else:
            total -= 1
            bins[1] = bins[1][0] - 1, bins[1][1]
            ans.append(bins[0][1] + bins[1][1])
            if not checkValid(bins, total):
                raise Error()

    return " ".join(ans)

if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(*readInput()))
