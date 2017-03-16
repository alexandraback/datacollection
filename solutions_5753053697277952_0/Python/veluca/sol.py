#!/usr/bin/env pypy3

import sys

def solve():
    n_parties = int(input())
    party_count = list(map(int, input().split()))
    party_sort = sorted(list(range(n_parties)), key=lambda x: -party_count[x])
    actions = []
    while True:
        cur = party_sort[0]
        oth = -1
        for i in party_sort:
            if party_count[i] > party_count[cur]:
                cur = i
                oth = -1
            elif party_count[i] == party_count[cur] and i != party_sort[0]:
                oth = i
        if party_count[cur] == 1:
            break
        action = ""
        if oth != -1:
            action += chr(ord('A') + oth)
            party_count[oth] -= 1
        action += chr(ord('A') + cur)
        party_count[cur] -= 1
        actions.append(action)
    while len(party_sort) > 2:
        actions.append(chr(ord('A')+party_sort[0]))
        del party_sort[0]
    actions.append(chr(ord('A') + party_sort[0]) + chr(ord('A') + party_sort[1]))
    return " ".join(actions)

T = int(input())
for l in range(1, T+1):
    print("Case #%d:" % l, end=" ")
    print(solve())
