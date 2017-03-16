#!/usr/bin/python3
T = int(input())
for t in range(1,T+1):
    getRow = lambda x: list(map(lambda _: set(map(int, input().split())), range(4)))[x]
    s = getRow(int(input())-1) & getRow(int(input())-1)
    print("Case #{}: {}".format(t, "Bad magician!" if len(s) > 1 else s.pop() if len(s) else "Volunteer cheated!"))
