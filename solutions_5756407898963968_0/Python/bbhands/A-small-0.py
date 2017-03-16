#!/usr/bin/python
# -*- coding: utf-8 -*-

if __name__ == "__main__":

    fin = open("A-small-0.in", "r")
    fout = open("A-small-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        ans_1 = int(fin.readline())
        rows_1 = []
        for i in xrange(0, 4):
            rows_1.append(fin.readline().strip().split(' '))

        row_1 = rows_1[ans_1-1]
        
        ans_2 = int(fin.readline())
        rows_2 = []
        for i in xrange(0, 4):
            rows_2.append(fin.readline().strip().split(' '))

        row_2 = rows_2[ans_2-1]

        overlap = set(row_1).intersection(row_2)
        if len(overlap) == 1:
            answer = overlap.pop()
        elif len(overlap) == 0:
            answer = "Volunteer cheated!"
        else:
            answer = "Bad magician!"
        
        fout.write("Case #%i: %s\n" % (t+1, answer))
    
    fin.close()
    fout.close()

