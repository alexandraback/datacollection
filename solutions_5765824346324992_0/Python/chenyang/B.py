#!/usr/bin/python2
from fractions import Fraction, gcd
from math import ceil
line = lambda: map(int, raw_input().split())

def main():
    n = input()
    for t in range(n):
        b, n = line()
        mk = line()
        print 'Case #{}: {}'.format(t + 1, solve_small(n, mk))

second = lambda l: l[1]

def lcm(a, b): return a * b /gcd(a, b)
def lcm_lst(lst):
    l = 1
    for i in lst:
        l = lcm(i, l)
    return l

def solve(n, mk):
    ppl_per_sec = sum(Fraction(1, k) for k in mk)
    secs = int((n-len(mk)) / ppl_per_sec)
    ppl_so_far = sum(int(ceil(1.0 * secs / k)) for k in mk)
    residues = list(enumerate([(- secs) % k for k in mk]))
    left = n - ppl_so_far
    assert left > 0
    for _ in range(left):
        to_take = min(residues, key=second)
        residues.remove(to_take)
        id, num = to_take
        residues.append((id, num + mk[id]))
    return id + 1
def solve_small(n, mk):
    l = lcm_lst(mk)
    left = n % sum(l/m for m in mk)
    if left == 0:
        return len(mk)
    residues = [(i, 0) for i in range(len(mk))]
    for _ in range(left):
        to_take = min(residues, key=second)
        residues.remove(to_take)
        id, num = to_take
        residues.append((id, num + mk[id]))
    return id + 1

main()
