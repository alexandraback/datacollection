#!/usr/bin/env python3
import random

if __name__ == '__main__':
    T = int(input())
    for t in range(1, T+1):
        N = int(input())
        P = list(map(int, str.split(input())))
        tot = sum(P)

        print('Case #{}: '.format(t), end='')
        while tot > 0:
            e = max(P)
            es = [(i, v) for i, v in enumerate(P) if v == e]
            #print(es)
            if len(es) == 2:
                print(chr(es[0][0] + ord('A')), end='')
                print(chr(es[1][0] + ord('A')) + ' ', end='')
                P[es[0][0]] -= 1
                P[es[1][0]] -= 1
                tot -= 2
            else:
                print(chr(es[0][0] + ord('A')) + ' ', end='')
                P[es[0][0]] -= 1
                tot -= 1
            assert(tot == sum(P))
            assert(max(P) <= sum(P) // 2)
            
        #p1 = max(enumerate(P), key=lambda x: x[1])
        #P[p1[0]] -= 1
        #p2 = max(enumerate(P), key=lambda x: x[1])
        #P[p2[0]] -= 1

        #for e in [p1, p2]:
        #    print(chr(e[0] + ord('A')), end='')
        print()
