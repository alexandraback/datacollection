import sys

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(raw_input())


for i in range(n):

    pieces = int(raw_input())
    p = [int(x) for x in raw_input().split()]

    a = 0
    b = 0

    mx = 0

    count = 0

    for j in range(1, pieces):
        c = p[j-1] - p[j]
        if c > mx:
            mx = c

        if c >= 0:
            count += 1

        if c > 0:
            a += c

    for j in range(0, pieces-1):
        if p[j] > 0:
            b += min(mx, p[j])

    print "Case #"+str(i+1)+": "+str(a)+" "+str(b)