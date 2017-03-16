#!/usr/bin/env python3

def howMuch(nrs):
    minnr = -1
    for i in range(min(nrs), max(nrs)+1):
        bnr = 0
        for x in nrs:
            bnr += abs(x-i)
        if bnr < minnr or minnr == -1:
            minnr = bnr
    return minnr

T = int(input())

for t in range(1, T+1):
    N = int(input())
    ch = []
    nr = []

    for i in range(N):
        string = input()
        prev = ''
        bch = []
        bnr = []
        for char in string:
            if char != prev:
                prev = char
                bch.append(char)
                bnr.append(0)
            bnr[-1] += 1
        ch.append(bch)
        nr.append(bnr)


    takiesame = True
    for x in ch:
        if x != ch[0]:
            takiesame = False

    if takiesame:
        suma = 0
        for i in range(len(ch[0])):
            suma += howMuch([x[i] for x in nr])
        print("Case #{}: {}".format(t, suma))
    else:
        print("Case #{}: Fegla Won".format(t))
