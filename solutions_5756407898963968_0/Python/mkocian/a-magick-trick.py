# -*- coding: utf-8 -*-


n = int(input())

for i in range(n):
    fst = int(input())
    cards1 = [[int(x) for x in input().split()] for j in range(4)]
    snd = int(input())
    cards2 = [[int(x) for x in input().split()] for j in range(4)]
    
    card = [x for x in cards1[fst-1] if x in cards2[snd-1]]

    print("Case #" + str(i+1) + ": ", end='')
    if len(card) == 1:
        print(card[0])
    elif len(card) == 0:
        print("Volunteer cheated!")
    else:
        print("Bad magician!")
