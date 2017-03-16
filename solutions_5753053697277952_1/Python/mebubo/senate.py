from sys import stdin

def itochar(i):
    return str(chr(ord('A') + i))

def translate(xs):
    return ''.join(map(itochar, xs))

def solve(case):
    def remove1(i):
        case[i] -= 1
        result.append([i])
    def remove2(i, j):
        case[i] -= 1
        case[j] -= 1
        result.append([i, j])
    result = []
    while any(case):
        max_ = max(*case)
        nmax = len(filter(lambda x: x == max_, case))
        imax = map(lambda x: x[0], filter(lambda x: x[1] == max_, enumerate(case)))
        if nmax == 1 or (nmax > 2 and max(case) == 1):
            remove1(imax[0])
        else:
            remove2(imax[0], imax[1])
    return ' '.join(map(translate, result))

def solveAll(cases):
    printAll(map(solve, cases))

def printAll(lines):
    for i, l in enumerate(lines):
        print "Case #%d: %s" % (i+1, l)

def main():
    T = int(stdin.readline())
    cases = []
    for t in range(T):
        n = int(stdin.readline())
        bffs = map(int, stdin.readline().split())
        cases.append(bffs)
    solveAll(cases)

main()
