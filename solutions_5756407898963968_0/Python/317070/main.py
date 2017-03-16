""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos

""" global variables """

""" classes """
        

""" functions """
def solve(row1,matr1,row2,matr2):
    sel = set(matr1[row1-1])
    sel = sel.intersection(set(matr2[row2-1]))
    if sel:
        if len(sel)==1:
            return sel.pop()
        else:
            return "Bad magician!"
    else:
        return "Volunteer cheated!"
    

""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        ### calculate answer ###
        (row1,) = read_ints()
        matr1 = []
        for i in xrange(4):
            matr1.append(list(read_ints()))
        (row2,) = read_ints()
        matr2 = []
        for i in xrange(4):
            matr2.append(list(read_ints()))
        answer = solve(row1,matr1,row2,matr2)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, "%s"%answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)