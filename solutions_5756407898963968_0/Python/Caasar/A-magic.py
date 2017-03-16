# -*- coding: utf-8 -*-
"""
Created on Sat Feb 15 18:33:33 2014

@author: Caasar
"""

from sys import stdin
import numpy as np

T = int(stdin.next())
for t in xrange(T):
    row1 = int(stdin.next())-1
    conf1 = []
    for line in stdin:
        conf1.append(np.fromstring(line,sep=" "))
        if len(conf1)==4:
            conf1 = np.array(conf1,np.int)-1
            break

    row2 = int(stdin.next())-1
    conf2 = []
    for line in stdin:
        conf2.append(np.fromstring(line,sep=" "))
        if len(conf2)==4:
            conf2 = np.array(conf2,np.int)-1
            break
        
    mask1 = np.zeros(16,np.bool)
    mask1[conf1[row1]] = True
    mask2 = np.zeros(16,np.bool)
    mask2[conf2[row2]] = True
    
    inds = np.flatnonzero(mask1&mask2)
    if inds.size == 0:
        print 'Case #%d: Volunteer cheated!' % (t+1,)
    elif inds.size > 1:
        print 'Case #%d: Bad magician!' % (t+1,)
    else:
        print 'Case #%d: %d' % (t+1,inds[0]+1)
    
