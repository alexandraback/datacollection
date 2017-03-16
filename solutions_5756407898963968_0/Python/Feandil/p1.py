#!/usr/env/python

from sys import stdin

def read_map():
    pos = int(stdin.readline().strip())
    grid = {}
    for i in range(1, 5):
        grid[i] = stdin.readline().strip().split()
    return set(grid[pos])

def solve_prob():
    first = read_map()
    second = read_map()
    inter = first.intersection(second)
    if len(inter) == 1:
      return inter.pop()
    elif len(inter) > 1:
      return 'Bad magician!'
    return 'Volunteer cheated!'

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}: {}'.format(i, solve_prob()))
