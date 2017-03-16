import sys

for case in range(int(input())):
    possible = range(1,17)
    for _ in range(2):
        k = int(input())
        grid = [list(map(int,input().split())) for _ in range(4)]
        new_possible = []
        for i in possible:
            if i in grid[k-1]:
                new_possible.append(i)
        possible = new_possible
    ans = "Case #"+str(case+1)+": "
    if len(possible) == 0:
        ans += "Volunteer cheated!"
    elif len(possible) == 1:
        ans += str(possible[0])
    else:
        ans += "Bad magician!"
    print(ans)
