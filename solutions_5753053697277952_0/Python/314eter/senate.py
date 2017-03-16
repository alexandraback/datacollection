#! /usr/bin/env python3
newline = False


def read_problem():
    n = int(input())
    counts = [int(c) for c in input().split()]
    return (n, counts)

def maxp(counts):
    maxparty = -1
    maxcount = -1
    for party, count in enumerate(counts):
        if count >= maxcount:
            maxparty = party
            maxcount = count
    secondparty = counts.index(maxcount)
    return (maxparty,) if maxparty == secondparty else (maxparty, secondparty)

def solve(problem):
    plan = []
    np, counts = problem
    n = sum(counts)
    while n > np:
        step = maxp(counts)
        for party in step:
            counts[party] -= 1
        plan.append(step)
        n -= len(step)
    for party in range(2, np):
        plan.append((party,))
    plan.append((0, 1))
    return plan


def print_solution(plan):
    print(' '.join(''.join(chr(ord('A') + party) for party in step) for step in plan))


cases = int(input())
for n in range(1, cases + 1):
    problem = read_problem()
    solution = solve(problem)
    print("Case #{0}:".format(n), end='\n' if newline else ' ')
    print_solution(solution)
