#!/bin/python3

T = int(input())

for t in range(T):

    P = int(input())
    VALS = list(map(int, input().split()))

    sorted_parties = sorted([(VALS[i], chr(ord('A') + i)) for i in range(len(VALS))], reverse=True)

    P1 = sorted_parties[0]
    P2 = sorted_parties[1]
    sorted_parties = sorted_parties[2:]

    result = []

    while P1[0] > P2[0] + 1:
        result.append(P1[1] + P1[1])
        P1 = (P1[0] - 2, P1[1])
    if P1[0] > P2[0]:
        result.append(P1[1])
        P1 = (P1[0] - 1, P1[1])

    for party in sorted_parties:
        for i in range(party[0]):
            result.append(party[1])

    for i in range(P1[0]):
        result.append(P1[1] + P2[1])

    print("Case #" + str(t+1) + ": " + " ".join(result))
