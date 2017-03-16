#!/usr/bin/env python3
import math, collections, itertools
from sys import stdin


def readValue(valueType):
    return valueType(stdin.readline())


def readValues(valueType):
    return list(map(valueType, stdin.readline()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


def readInput():
    N = readValue(int)
    words = [None] * N
    for i in range(N):
        words[i] = readValue(str).strip()

    return words


def getBaseWord(word):
    baseWord = []
    prev = None
    for ch in word:
        if ch != prev:
            baseWord.append(ch)
            prev = ch
    return tuple(baseWord)


def getWordRepr(word):
    prev, cnt = word[0], 0
    wordRepr = []
    for ch in word + '?':
        if ch != prev:
            wordRepr.append(cnt)
            cnt = 1
            prev = ch
        else:
            cnt += 1
    return wordRepr


def solve(read):
    words = read
    baseWords = set(map(getBaseWord, words))
    if len(baseWords) > 1:
        return 'Fegla Won'
    wordReprs = list(map(getWordRepr, words))
    minCost, N = 0, len(wordReprs)

    for i in range(len(wordReprs[0])):
        left = min(wordRepr[i] for wordRepr in wordReprs)
        right = max(wordRepr[i] for wordRepr in wordReprs)

        bestCost = 1000000
        for choose in range(left, right + 1):
            cost = sum(abs(wordRepr[i] - choose) for wordRepr in wordReprs)
            bestCost = min(bestCost, cost)
        minCost += bestCost
    return minCost


if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(readInput()))
