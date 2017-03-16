#!/usr/bin/python

import sys

T = int(sys.stdin.readline())

counter = 1
for i in range(0,T):
    ans1 = int(sys.stdin.readline().strip())
    
    for j in range(0,ans1-1):
        sys.stdin.readline()
    
    cards = sys.stdin.readline().strip().split()
    
    for j in range(ans1,4):
        sys.stdin.readline()
        
    ans2 = int(sys.stdin.readline().strip())
    
    for j in range(0,ans2-1):
        sys.stdin.readline()
    
    cards2 = sys.stdin.readline().strip().split()
    
    for j in range(ans2,4):
        sys.stdin.readline()
        
    result = set(cards).intersection( set(cards2) )
    if len(result) == 1:
        print 'Case #{}: {}'.format(counter, list(result)[0]) 
    else:
        if len(result) == 0:
            print 'Case #{}: {}'.format(counter, 'Volunteer cheated!') 
        else:
            print 'Case #{}: {}'.format(counter, 'Bad magician!') 
    counter += 1
    