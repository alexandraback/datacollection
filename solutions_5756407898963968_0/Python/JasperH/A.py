def solve(testNum):
    a1 = int(input())-1
    l1 = [[int(x) for x in input().split()] for y in range(4)]
    a2 = int(input())-1
    l2 = [[int(x) for x in input().split()] for y in range(4)]
    poss = set.intersection(set(l1[a1]),set(l2[a2]))
    if len(poss) == 1:
        ans = str(list(poss)[0])
    elif len(poss) > 1:
        ans = "Bad Magician!"
    else:
        assert len(poss) == 0
        ans = "Volunteer cheated!"
    print("Case #%d: %s"%(testNum+1,ans))

t = int(input())
for i in range(t):
    solve(i)
