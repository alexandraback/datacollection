#!/usr/bin/env python3

def rl():
    return [ int(_) for _ in input().split() ]

T, *_ = rl()
for C in range(1,T+1):
    r1, *_ = rl()
    l1 = [ rl() for i in range(4) ] [r1-1]
    r2, *_ = rl()
    l2 = [ rl() for i in range(4) ] [r2-1]
    s = set(l1) & set(l2)
    if len(s) == 0:
        answer = 'Volunteer cheated!'
    elif len(s) == 1:
        answer = str( list(s)[0] )
    else:
        answer = 'Bad magician!'
    print('Case #%d: %s'%(C,answer))

