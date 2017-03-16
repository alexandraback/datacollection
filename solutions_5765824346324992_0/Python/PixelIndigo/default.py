import sys

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(raw_input())

for i in range(n):

    b, place = map(int, raw_input().split())

    barbers = [int(x) for x in raw_input().split()]

    q = [j for j in range(b)]

    queue = [x for x in barbers]

    while sum(queue) != 0:
        for j in range(b):
            if queue[j] == 0:
                q.append(j)
                queue[j] = barbers[j]

        mn = min(queue)
        for j in range(b):
            queue[j] -= mn

    answ = str(q[(place-1) % len(q)]+1)

    print "Case #"+str(i+1)+": "+answ