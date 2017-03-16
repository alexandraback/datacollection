#!/usr/bin/env python

from __future__ import division, print_function
import string, sys


PARTIES = string.ascii_uppercase


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    
    for k in range(T):
        N = int(sys.stdin.readline())
        P = list(map(int, sys.stdin.readline().split()))
        
        total = sum(P)
        order = []
        
        while total > 0:
            x, i = max((x, i) for i, x in enumerate(P))
            P[i] -= 1
            total -= 1
            
            y, j = max((x, i) for i, x in enumerate(P))
            P[j] -= 1
            total -= 1
            
            if any(p * 2 > total for p in P):
                P[j] += 1
                total += 1
                
                order.append(PARTIES[i])
            else:
                order.append(PARTIES[i] + PARTIES[j])
        
        print('Case #%d:' % (k + 1), ' '.join(order))