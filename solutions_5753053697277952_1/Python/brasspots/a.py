#!/usr/bin/python

# use this file like this:
# ./a.py < ../../Downloads/a.in > a.out

l2s = lambda x: ''.join(x)
s2l = lambda x: list(x)

def debug(*arg):
    if DEBUG:
        for x in arg:
            print x,
            print ":",
        print

DEBUG = False

def solver(inp):
    """
    inp is a list of the input parameters. This solver returns a list of the
    output parameters
    """
    
    
    def majority(senators):
        tot = sum(senators.values())
        for p, num in senators.items():
            if num > tot / 2:
                return True
        return False
    senators = {}
    KEYS ='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    Ki = 0
    for num in inp:
        senators[KEYS[Ki]] = num
        Ki +=1
    
    #senators = {'A': 3, 'B': 2, 'C': 2}
    num_in_room = sum(senators.values())
    full_remove = []
    while num_in_room:
        remove =[]
        _s = senators.copy()
        p = max(_s.keys(), key = lambda x: _s[x])
        _s[p] -= 1
        remove.append(p)
        num_in_room -= 1
        if num_in_room:
            _s2 = _s.copy()
            p = max(_s2.keys(), key = lambda x: _s2[x])
            _s2[p] -= 1

            if not majority(_s2):
                remove.append(p)
                num_in_room -= 1
                senators = _s2
            else:
                senators = _s
        full_remove.append(tuple(remove))

    res =''
    for t in full_remove:
        for p in t:
            res += p
        res+= ' '
    res = res[:-1]

    out = [res]
    
    return out  


cases = int(raw_input())
for case in range(1, cases+1):
    inp = []
    num = int(raw_input())
    inp = [int(i) for i in raw_input().split(' ')]
    print 'Case #{}:'.format(case), ' '.join([str(x) for x in solver(inp)])
 

