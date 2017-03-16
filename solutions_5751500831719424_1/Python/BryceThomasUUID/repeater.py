import fileinput
import sys
from itertools import groupby
import math
import numpy as np

cases = int(sys.stdin.readline())
for i in range(1, cases + 1):
    num_strings = int(sys.stdin.readline())
    strings = []
    for j in range(num_strings):
        strings.append(sys.stdin.readline())
    index = 0
    num_moves = 0
    while True:
        # it's possible if after removing consecutive dupes the lists
        # are the same
        de_duped = [[x[0] for x in groupby(s)] for s in strings]
        if all(x==de_duped[0] for x in de_duped):
            # possible
            groups = [[list(g) for k,g in groupby(s)] for s in strings]
            group_lens = [[len(sg) for sg in g] for g in groups]
            matched_lens = zip(*group_lens)
            #print >> sys.stderr, 'matched_lens:', matched_lens
            for m_len in matched_lens:
                #bla = m_len.copy()
                median_idx = len(m_len)/2 
                median_val = sorted(m_len)[median_idx]
                #print >> sys.stderr, 'median_val:', median_val
                num_moves += int(sum([math.fabs(val - median_val)  for val in m_len]))
            print 'Case #' + str(i) + ': ' + str(num_moves)
        else:
            #impossible
            print 'Case #' + str(i) + ': ' + 'Fegla Won'
        break
    
        
    
