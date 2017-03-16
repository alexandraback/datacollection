import string

# f = open('A-large-practice.in')
f = open('A-large.in')

import sys
sys.stdout = open('out', 'w')

def allEvac(l):
    for item in l:
        if item != 0:
            return False
    return True

def noMajority(l):
    s = sum(l)
    for item in l:
        if item > s/2:
            return False
    return True

T = f.readline()
for case in range(int(T)):
    n = f.readline().split()
#     print n
    l = f.readline().rstrip('\n').split(' ')
    l = map(int, l)
#     print l
    
    el = []
    
    while not allEvac(l):
        ss = ""
        maxv = max(l)
        maxi = l.index(maxv)
        l[maxi] -= 1
        ss += string.ascii_uppercase[maxi]
        
        if not noMajority(l):
            maxv = max(l)
            maxi = l.index(maxv)
            l[maxi] -= 1
            ss += string.ascii_uppercase[maxi]
            
        el.append(ss)
        
    
    print "Case #"+str(case+1)+":", ' '.join(el)
    
