#!/usr/bin/env python

TEST="""4
2 3 6
4 1 2
3 3 8
5 2 0"""
#raw_input = iter(TEST.splitlines()).next

def empty(C):
    return list([None])*C

def fuh(unhappy, occup):
    worst = -100
    wr, wc = -1,-1
    for rx, row in enumerate(unhappy):
        for cx, uh in enumerate(row):
            if occup[rx][cx]:
                if unhappy[rx][cx] > worst:
                    worst = unhappy[rx][cx]
                    wr,wc = rx,cx
                if worst == 4:
                    return wr,wc
    return wr, wc

def remove(R, C, rx, cx, unhappy, occup):
    occup[rx][cx] = False
    unhappy[rx][cx] = 0

    # Above
    if cx > 0 and occup[rx][cx-1]:
        unhappy[rx][cx-1] -= 1

    # Below
    if cx < (C-1) and occup[rx][cx+1]:
        unhappy[rx][cx+1] -= 1

    # Left
    if rx > 0 and occup[rx-1][cx]:
        unhappy[rx-1][cx] -= 1

    # Right
    if rx < (R-1) and occup[rx+1][cx]:
        unhappy[rx+1][cx] -= 1


def solve(R,C,N):
    if N == 0:
        return 0

    if N <= ((R*C)/2)+( (R*C) % 2):
        return 0
        # diagonal layout.


    max_unhappy = 2*R*C-R-C
    removals = R*C - N
    occup = [empty(C) for r in range(R)]
    unhappy = [empty(C) for r in range(R)]
    for r in range(R):
        if R == 1:
            r_uh = 0
        elif r in (0, R-1):
            r_uh = 1
        else:
            r_uh = 2
        for c in range(C):
            if C == 1:
                uh = r_uh
            elif c in (0, C-1):
                uh = r_uh + 1
            else:
                uh = r_uh + 2
            occup[r][c] = True
            unhappy[r][c] = uh

    for r in range(removals):
        rx, cx = fuh(unhappy, occup)
        remove(R, C, rx, cx, unhappy, occup)
        #print "Removed %s, %s" % (rx, cx)

    total_unhappy = sum([sum(i) for i in unhappy])
    assert(total_unhappy%2==0)
    
    r = total_unhappy/2
    if N == R*C:
        assert( r == max_unhappy )
    return total_unhappy / 2

T = int(raw_input())
for case in range(1, T+1):
    R,C,N = map(int, raw_input().strip().split())
    print("Case #%s: %s" % (case, solve(R,C,N)))
