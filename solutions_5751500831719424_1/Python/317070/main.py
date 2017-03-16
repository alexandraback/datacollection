""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import itertools

""" global variables """

""" classes """
        

""" functions """
def solve(lines):
    str0 = ''.join(ch for ch, _ in itertools.groupby(lines[0]))
    for i in lines:
        short = ''.join(ch for ch, _ in itertools.groupby(i))
        if short != str0:
            return "Fegla Won"
    
    l = []
    for line in lines:
        l.append([])
        prevchar = ''
        for i in xrange(len(line)):
            if line[i]!=prevchar:
                l[-1].append(1)
            else:
                l[-1][-1] += 1
            prevchar = line[i]
            
    l=array(l)
    
    total = 0
    for i in xrange(len(l[0])):
        numbers = l[:,i]
        minimum = 10000000000000000000000000000000000000000000000000000
        for x in xrange(min(numbers),max(numbers)+1):
            distance = sum(abs(numbers-x))
            if distance<minimum:
                minimum = distance
        total += minimum
    return total
        
    

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
        (N,) = read_ints()
        lines = []
        for i in xrange(N):
            lines.append(f.readline().strip())
        answer = solve(lines)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, "%s"%answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)