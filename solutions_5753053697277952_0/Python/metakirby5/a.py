#!/usr/bin/env python3
from collections import *
from string import ascii_uppercase as up

def main(*args):
    parties = [int(p) for p in input().split()]
    moves = []
    while any(parties):
        move = ''
        counts = defaultdict(list)
        for i, c in enumerate(parties):
            counts[c] += [i]
        _, top = sorted(counts.items(), reverse=True, key=lambda x: x[0])[0]
        parties[top[0]] -= 1
        move += up[top[0]]
        if not len(top) % 2:
            parties[top[1]] -= 1
            move += up[top[1]]
        moves += [move]
    return ' '.join(moves)

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #{}: {}".format(i + 1, main(*input().split())))
