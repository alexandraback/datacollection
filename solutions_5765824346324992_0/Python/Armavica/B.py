#! /usr/bin/python3

from math import ceil

def load_file(chemin):
    def parse_input(f): # TODO
        [b,n] = [int(n) for n in f.readline().split()]
        line = [int(n) for n in f.readline().split()]
        return (n,line)

    from os.path import isfile
    with open(chemin, 'r') as file:
        for _ in range(int(file.readline())):
            yield parse_input(file)
        file.close()

def dicho(test):
    low = 0
    high = 1
    while test(high) < 0:
        high *= 2
    while low < high-1:
        mid = (low+high)//2
        if test(mid) < 0:
            low = mid
        else:
            high = mid
    return low

def solve(case): # TODO
    (n,barbers) = case

    def howmuch(t):
        return sum([ceil(t/b) for b in barbers])
    
    t = dicho(lambda t: howmuch(t) - n)
    n -= howmuch(t)
    for i,b in enumerate(barbers):
        if t % b == 0:
            if n == 1:
                return i+1
            else:
                n -= 1


from sys import argv

for (i, case) in enumerate(load_file(argv[1])):
    print("Case #" + str(i+1) + ":", solve(case))

