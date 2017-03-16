# -*- coding: utf-8 -*-

from pylab import *
import numpy

infile = open('input.txt', 'r')
outfile = open("magitrick-output.txt", "w")

numcases = int(infile.readline())

for case in range(0, numcases):
    row1_id = int(infile.readline()) - 1
    row1_data = zeros(4, dtype=numpy.int)
    
    for r in range(0, 4):
        line = infile.readline()
        if r == row1_id:
            els = line.split(" ")
            for i in range(0, 4):
                row1_data[i] = int(els[i])
            
    row1_data = set(row1_data)
    
    row2_id = int(infile.readline()) - 1
    row2_data = zeros(4, dtype=numpy.int)
    
    for r in range(0, 4):
        line = infile.readline()
        if r == row2_id:
            els = line.split(" ")
            for i in range(0, 4):
                row2_data[i] = int(els[i])
                
    row2_data = set(row2_data)
    
    common = row1_data & row2_data
    
    outfile.write('Case #')
    outfile.write(str(case + 1))
    outfile.write(': ')
    if (len(common) == 0):
        print('Case #', case, ': Volunteer cheated!')
        outfile.write('Volunteer cheated!')
    else:
        if (len(common) == 1):
            res = common.pop()
            print('Case #', case, ': ', res)
            outfile.write(str(res))
        else:
            print('Case #', case, ': Bad magician!')
            outfile.write('Bad magician!')
            
    outfile.write('\n')
    
outfile.close()
    
    
                
    
    
    
        

