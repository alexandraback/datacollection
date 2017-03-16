#! /usr/bin/env python3

import numpy as np

def compute(parties):
    evacuation = []
    while True:
        step = ''
        i = np.argmax(parties)
        if parties[i] == 0:
            return evacuation
        parties[i] -= 1
        step += chr(i + ord('A'))
        j = np.argmax(parties)
        parties[j] -= 1
        if len(list(p for p in parties if p != 0)) == 1:
            parties[j] += 1
        else:
            step += chr(j + ord('A'))
        evacuation.append(step)

T=int(input())
for case in range(1, T+1):
    N = int(input())
    parties = [int(p) for p in input().split()]
    assert N==len(parties)
    evacuation = compute(parties)
    print('Case #%d: %s' % (case, ' '.join(evacuation)))
