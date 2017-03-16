from random import randint

fin = open("../../Downloads/B-small-attempt0 (2).in", "r")
out = open("haircut.out", "w")

cases = int(fin.readline())

for i in range(cases):
    b, n = [int(x) for x in fin.readline().split()]
    n = n-1
    times = [int(x) for x in fin.readline().split()]
    min = 0
    max = 1000000000000
    rounds = 0
    while min < max and rounds < 100:
        mid = (min + max + randint(0,1))/2
        numcut = sum([(mid-1)/mk+1 for mk in times])
        if numcut > n:
            max = mid - 1
        if numcut < n:
            min = mid
        if numcut == n:
            min = mid
        rounds = rounds + 1
    #print max
    n -= sum([(max-1)/mk+1 for mk in times])
    ans = -1
    for j in range(0, b):
        if max % times[j] == 0:
            n = n-1
        if n < 0:
            ans = j + 1
            break
    out.write("Case #%d: %d\n" % (i + 1, ans))
out.close()
