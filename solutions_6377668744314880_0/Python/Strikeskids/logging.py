
import math
import sys
import functools

def lineSide(a, b, c): 
    """
        Returns -1 for right side of line
    """
    lx, ly = b[0] - a[0], b[1] - a[1]
    px, py = c[0] - a[0], c[1] - a[1]

    return lx * py - ly * px

def quad(loc, a):
    if a[0] < loc[0]:
        if a[1] < loc[1]:
            return 3
        else:
            return 2
    else:
        if a[1] < loc[1]:
            return 4
        else:
            return 1

def test():
    n = int(input())
    locs = []
    for i in range(n):
        locs.append(tuple(map(int, input().split(' '))))

    for i in range(n):
        loc = locs[i]

        other = locs[:i] + locs[i+1:]

        def pntcmp(a, b):
            q1, q2 = quad(loc, a), quad(loc, b)
            if q1 == q2:
                val = lineSide(loc, b, a)
                if val == 0:
                    return 0
                return math.copysign(1, val)
            if q1 < q2:
                return -1
            else:
                return 1

        other.sort(key=functools.cmp_to_key(pntcmp))

        if len(other) < 2:
            print(0)
            continue

        print(loc, other, file=sys.stderr)

        low = 0

        def advance(h):
            while h != low:
                print(low, h, other[low], other[h], lineSide(loc, other[low], other[h]), file=sys.stderr)
                if lineSide(loc, other[low], other[h]) <= 0:
                    break
                h = (h + 1) % (n-1)
            return h

        high = advance(1)

        count = (high - low - 1) % (n-1)

        print(low, high, count, file=sys.stderr)

        best = min(count, n-1-count)
        while low < n-2:
            low += 1
            high = advance(high)
            print(low, high, count, file=sys.stderr)
            count = (high - low - 1) % (n-1)


            best = min(count, n-1-count, best)

        print(best)

def main():
    cases = int(input())
    for case in range(1, cases+1):
        print('Case #%d:'%(case, ))
        test()

if __name__ == '__main__': main()