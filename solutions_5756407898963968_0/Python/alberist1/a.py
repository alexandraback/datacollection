#!/usr/bin/pypy

def solve():
    A1 = int(raw_input())
    B1 = [[int(x) for x in raw_input().split()] for i in range(4)]
    A2 = int(raw_input())
    B2 = [[int(x) for x in raw_input().split()] for i in range(4)]
    r = set(B1[A1-1]).intersection(set(B2[A2-1]))
    if len(r)==0:
        print 'Volunteer cheated!'
    elif len(r)==1:
        print list(r)[0]
    else:
        print 'Bad magician!'

if __name__=="__main__":
    T = int(raw_input())
    for i in range(1,T+1):
        print "Case #%d:"%i,
        solve()
