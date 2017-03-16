T = int(input())

for t in range(T):
    N = int(input())

    mushrooms = list(map(int, input().split()))

    minEaten1 = 0
    minSpeed = 0
    lastM = 0
    for m in mushrooms:
        if m < lastM:
            minEaten1 += lastM - m

        if lastM - m > minSpeed:
            minSpeed = lastM - m
        lastM = m

    minEaten2 = 0
    lastM = 0
    for m in mushrooms:
        minEaten2 += min(minSpeed, lastM)
        lastM = m

    print("Case #" + str(t+1) + ": " + str(minEaten1) + " " + str(minEaten2))
