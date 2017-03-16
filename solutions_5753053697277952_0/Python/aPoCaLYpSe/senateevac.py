import itertools
import copy
import sys
import math
from collections import Counter

sys.setrecursionlimit(10000)

def line2ints(instrm):
    args = instrm.readline().strip().split()
    return list(map(int, args))


def parse_case(instrm):
    instrm.readline()
    return line2ints(instrm)
   
def check(people):
    tot = len(people)
    counts = Counter(people)
    for v in counts.values():
        if v*2 > tot:
            return False
    return True


alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def solve_case(case):
    people = "" 
    for i, num in enumerate(case):
        people += alpha[i]*num

    tot = len(people)
    for perm in itertools.permutations(people):
        perm = "".join(perm)
        plan = []
        while len(plan) < tot:
            opt1 = perm[:-2]
            opt2 = perm[:-1]
            if check(opt1):
                plan.append(perm[-2:])
                perm = opt1
            elif check(opt2):
                plan.append(perm[-1:])
                perm = opt2
            else:
                plan = None
                break
        if plan is not None:
            return " ".join(plan)
        




if __name__ == "__main__":
    instrm = open(sys.argv[1])
    ncases = int(instrm.readline().strip())
    for i in range(ncases):
        case = parse_case(instrm)
        ans = solve_case(case)
        print("Case #{}: {}".format(i+1, ans))
