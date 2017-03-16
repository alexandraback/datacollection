#!/usr/bin/env python

import string

T = int(raw_input().strip())

def solve(N, Ps):
    parties = {}
    for index, num in enumerate(Ps):
        parties[string.ascii_uppercase[index]] = num
    #print parties
    while True:
        for p, num in list(parties.items()):
            if not num:
                del parties[p]
        number_parties_remaining = len(parties)
        if number_parties_remaining == 0:
            return
        elif number_parties_remaining == 1:
            raise Exception('Majority exists!')
        elif number_parties_remaining == 2:
            ps = list(parties.items())
            if ps[0][1] == ps[1][1]:
                yield ''.join(parties.keys())
                parties[ps[0][0]] -= 1
                parties[ps[1][0]] -= 1
            elif ps[0][1] > ps[1][1]:
                yield ps[0][0]
                parties[ps[0][0]] -= 1
            elif ps[0][1] < ps[1][1]:
                yield ps[1][0]
                parties[ps[1][0]] -= 1
        else:
            biggest_p = None
            biggest_value = 0
            for key, value in parties.items():
                if value > biggest_value:
                    biggest_p = key
                    biggest_value = value
            yield biggest_p
            parties[biggest_p] -= 1

for i in range(1, T+1):
    print ("Case #%d:" % i),
    N = raw_input().strip()
    Ps = map(int, raw_input().strip().split())
    print ' '.join(solve(N, Ps))
    #for x in solve(N, Ps):
    #    print x
