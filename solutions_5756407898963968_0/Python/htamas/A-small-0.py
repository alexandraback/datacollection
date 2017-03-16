#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    row = int(input())
    cards = [{int(i) for i in input().split()} for _ in range(4)][row-1]
    row = int(input())
    cards &= [{int(i) for i in input().split()} for _ in range(4)][row-1]
    if cards:
        if len(cards) > 1:
            ans = "Bad magician!"
        else:
            ans = cards.pop()
    else:
        ans = "Volunteer cheated!"
    print("Case #{}: {}".format(case, ans))

