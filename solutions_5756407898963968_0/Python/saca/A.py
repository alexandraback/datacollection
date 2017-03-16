#!/usr/bin/env python3


import sys


def readInt():
    return int(sys.stdin.readline())


def readInts():
    return tuple(map(int, sys.stdin.readline().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


for _ in range(readInt()):
    arr = [None, None]
    ans = [None, None]

    ans[0] = readInt() - 1
    arr[0] = tuple(readInts() for _ in range(4))
    ans[1] = readInt() - 1
    arr[1] = tuple(readInts() for _ in range(4))

    first = set(arr[0][ans[0]])
    second = set(arr[1][ans[1]])

    both = list(first & second)
    if len(both) == 1:
        Mouth.answer(both[0])
    elif len(both) > 1:
        Mouth.answer("Bad magician!")
    else:
        Mouth.answer("Volunteer cheated!")
