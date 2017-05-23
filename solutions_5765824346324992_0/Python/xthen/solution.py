import copy

from fractions import gcd
import functools


def lcm(a, b):
    return (a * b) // gcd(a, b)


def listlcm(lst):
    return functools.reduce(lcm, lst)


def barbs(lst, n):


    mult = listlcm(lst)

    done = 0
    for k in range(0, len(lst)):
        done += mult // lst[k]

    line = n % done
    if line == 0:
        line = done

    times = copy.copy(lst)
    if line <= len(lst):
        return line

    line -= len(lst)

    while line > 0:
        mn = min(times)
        for j in range(0, len(times)):
            times[j] -= mn
            if times[j] == 0:
                line -= 1
                if line == 0:
                    return j + 1
                else:
                    times[j] = lst[j]

    return "err"


with open('B-small-attempt1.in') as f:
    stuff = f.readlines()

x = 1
case = 1

while x < len(stuff):
    pos = list(map(int, stuff[x].split()))[1]
    barbers = list(map(int, stuff[x+1].split()))
    print("Case #"+str(case)+": "+str(barbs(barbers, pos)))
    x += 2
    case += 1