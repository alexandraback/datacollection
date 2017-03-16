import math

T = input()

def solve(arr):
    total = 0
    while arr[0] != "":
        lens = []
        new_arr = []
        current = arr[0][0]
        for line in arr:
            count = 0
            while line != "" and line[0] == current:
                line = line[1:]
                count +=1
            if count == 0:
                print "Fegla Won"
                return
            lens.append(count)
            new_arr.append(line)
        lens.sort()
        median = lens[len(lens)/2]
        total += sum(abs(i - median) for i in lens)
        arr = new_arr
    if set(arr) != set([""]):
        print "Fegla Won"
        return
    print total

for i in xrange(T):
    print "Case #%d:" % (i + 1),
    N = input()
    arr = []
    for _ in xrange(N):
        arr.append(raw_input())
    solve(arr)
