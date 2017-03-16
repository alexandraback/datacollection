#!/usr/bin/python
# -*- coding: utf-8 -*-

if __name__ == "__main__":

    fin = open("A-large-0.in", "r")
    fout = open("A-large-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        N = int(fin.readline().strip())
        M = map(int, fin.readline().strip().split())

        fst = 0
        snd = 0

        max_diff = 0
        for i in xrange(1, N):
            if M[i] < M[i-1]:
                diff = M[i-1]-M[i]
                fst += diff
                if diff > max_diff:
                    max_diff = diff
        for i in xrange(0, N-1):
            if M[i] < max_diff:
                snd += M[i]
            else:
                snd += max_diff

        fout.write("Case #%i: %s %s\n" % (t+1, fst, snd))

    fin.close()
    fout.close()

