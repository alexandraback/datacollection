import sys

letters = [chr(x) for x in range(ord('A'), ord('A')+26)]

t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    p = [int(x) for x in sys.stdin.readline().split()]
    max1, max2 = 1, 0
    if p[0] > p[1]:
        max1, max2 = 0, 1
    for j in range(2, n):
        if p[j] > p[max1]:
            max2 = max1
            max1 = j
        elif p[j] > p[max2]:
            max2 = j
    sol = []
    for j in range(p[max1] - p[max2]):
        sol.append(letters[max1])
    for j in range(n):
        if j != max1 and j != max2:
            for k in range(p[j]):
                sol.append(letters[j])
    for j in range(p[max2]):
        sol.append(letters[max1] + letters[max2])
    print("Case #" + str(i+1) + ": " + " ".join(sol))

