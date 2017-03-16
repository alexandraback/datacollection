#!/usr/bin/python3
# import sys
#import numpy as np

T = int(input())

letters = [chr(e) for e in range(ord('A'),26+ord('A'))]

# def Evacuate(Ps):
#     min_party = min(Ps)
#     evacuation_plan = [[]]

for i_T in range(T):
    N = int(input())
    Ps = list(map(int, input().split(" ")))
    
    # print(i_T, N, Ps)
    evacuation_plan = list()
    while sum(Ps) > 0:
        for i_P, P in enumerate(Ps):
            if P > 0:
                Ps[i_P] -= 1
                evacuation_plan.append(letters[i_P])
        # print(Ps, evacuation_plan)
    evacuation_plan = evacuation_plan[::-1]
    if len(evacuation_plan) % 2 == 0:
        tmp = [i+j for i,j in zip(evacuation_plan[::2],evacuation_plan[1::2])]
    else:
        tmp = [evacuation_plan[0]]
        tmp.extend([i+j for i,j in zip(evacuation_plan[1::2],evacuation_plan[2::2])])

    # print(evacuation_plan, tmp)



    
    print("Case #{}: {}".format(i_T+1, " ".join(tmp)))
