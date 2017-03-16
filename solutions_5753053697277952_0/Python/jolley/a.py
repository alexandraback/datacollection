# -*- coding: utf-8 -*-
"""
Created on Fri Apr 15 20:13:26 2016

@author: jo
"""

import numpy as np
l = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
with open('input', 'r') as f:
    with open('output', 'w') as fo:
        cases = int(f.readline())
        print cases
        for case in xrange(1,cases+1):
            fo.write('Case #' + str(case) + ': ')
            print('Case: ' + str(case))
    
            
            N = int(f.readline().strip())
            
            Ps = map(int, f.readline().split())
            Ps = np.asarray(Ps)
            output = []
            while(sum(Ps)>3):
                a =  np.argmax(Ps)
                Ps[a] -= 1
                b = np.argmax(Ps)
                Ps[b] -= 1
                output.append("" + l[a] + l[b])
                
            if(sum(Ps)==3):
                a = np.argmax(Ps)
                Ps[a] -= 1
                output.append(l[a])
                b = np.argmax(Ps)
                Ps[b] -=1
                c = np.argmax(Ps)
                output.append("" + l[b] + l[c])
                
            else:
                if(sum(Ps)==2):
                     a = np.argmax(Ps)
                     Ps[a] -= 1
                     b = np.argmax(Ps)   
                     output.append("" + l[a] + l[b])
            
            for o in output:
                fo.write(o + " ")           
            fo.write('\n')