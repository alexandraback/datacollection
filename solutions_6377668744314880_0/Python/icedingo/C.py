#!/usr/bin/env python3

T = int(input())

def ccw(hull, tree):
    return (hull[-1][0] - hull[-2][0])*(tree[1] - hull[-2][1]) - (hull[-1][1] - hull[-2][1])*(tree[0] - hull[-2][0])

for t in range(T):
    N = int(input())
    trees = []
    for n in range(N):
        tree = tuple(map(int, input().split()))
        trees.append(tree)

    origtree = list(trees)
    trees.sort()

    upper = []
    lower = []

    for tree in trees:
        while len(lower) >= 2 and ccw(lower, tree) < 0:
            lower.pop()
        lower.append(tree)

    for tree in reversed(trees):
        while len(upper) >= 2 and ccw(upper, tree) < 0:
            upper.pop()
        upper.append(tree)

    hull = lower[:-1] + upper[:-1]
    hullset = set(hull)

    lh = len(hull)

    print('Case #{}:'.format(t+1))
    for tree in origtree:
        if tree in hullset:
            print(0)
            continue
        minj = lh
        for i in range(lh):
            hullpart = [hull[i], tree]
            for j in range(1, lh):
                if j >= minj:
                    break
                nexttree = hull[(i+j+1)%lh]
                if ccw(hullpart, nexttree) >= 0:
                    minj = min(minj, j)
                    break
        print(minj)
