'''
Created on May 8, 2016

@author: fernandomendez
'''

import argparse
import sys
import math


def solve(inFile):
    n = int(inFile.readline().strip())
    senat = [int(x) for x in inFile.readline().strip().split()]
    partdict = dict()
    for par in range(n):
        partdict[chr(par+ord('A'))] = senat[par]
#     print partdict
    prtcount = dict()
    for co in range(1001):
        prtcount[co]=set()
    for let in partdict.keys():
        prtcount[partdict[let]].add(let)
    #print  prtcount
    maxc = 1000
    seq = list()
    while maxc > 0:
        if len(prtcount[maxc]) ==0:
            maxc -=1
        elif len(prtcount[maxc]) == 1 or len(prtcount[maxc]) == 3:
            extparty = list(prtcount[maxc])[0]
            seq.append(extparty)
            prtcount[maxc-1].add(extparty)
            prtcount[maxc].remove(extparty)
        else:
            li = list(prtcount[maxc])
            extpa1 = li[0]
            extpa2 = li[1]
            seq.append(extpa1+extpa2)
            prtcount[maxc-1].add(extpa1)
            prtcount[maxc-1].add(extpa2)
            prtcount[maxc].remove(extpa1)
            prtcount[maxc].remove(extpa2)
            
        
    return ' '.join(seq)


parser = argparse.ArgumentParser(description='''Template''',  epilog='')
parser.add_argument('input',  help='input file', )
parser.add_argument('output', help='output file')
args = parser.parse_args()

inFile = open (args.input)
outFile = open (args.output, 'w')
line = inFile.readline()
line= line.strip()
ncases = int(line)

for case in range(1, ncases+1):
    sol = solve(inFile)
    outFile.write('Case #'+str(case)+": "+str(sol)+"\n")


