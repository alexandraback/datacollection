#!/usr/bin/python
# -*- coding: utf-8 -*-

from fractions import gcd
import sys

def lcm(a, b):
    return (a * b) // gcd(a, b)

def lcmm(*numbers):
    return reduce(lcm, numbers)

if __name__ == "__main__":

    fin = open("B-small-0.in", "r")
    fout = open("B-small-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        B, N = tuple(map(int, fin.readline().strip().split()))
        M = map(int, fin.readline().strip().split())

        assert len(M) == B

        answer = 1
        customer = []
        baber = []
        time = 0
        consume = 1

        cycle = lcmm(*M)

        while time < cycle :
            for i in xrange(0, B):
                if len(customer) < B:
                    customer.append([])
                if len(customer[i])*M[i] <= time:
                    customer[i].append(consume)
                    baber.append(i+1)
                    consume += 1
            time += 1

        answer = baber[N%(consume-1)-1]

        fout.write("Case #%i: %s\n" % (t+1, answer))

    fin.close()
    fout.close()

