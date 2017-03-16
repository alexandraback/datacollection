import sys
import collections

INFTY = 1000000

def evalMap(assignment, r, c):
    res = 0
    for i in xrange(r):
        for j in xrange(c - 1):
            if assignment[i][j] == "1" and assignment[i][j + 1] == "1":
                res += 1

    for j in xrange(c):
        for i in xrange(r - 1):
            if assignment[i][j] == "1" and assignment[i + 1][j] == "1":
                res += 1

#    print res
    return res


def minForMap(assignment, r, c, idx, numPeople):
    if r*c == idx:
        if numPeople > 0:
            return INFTY
        else:
            return evalMap(assignment, r, c)
    else:
        i = idx / c
        j = idx % c
        if numPeople > 0:
            assignment[i][j] = "1"
            option1 = minForMap(assignment, r, c, idx + 1, numPeople - 1)
        else:
            option1 = INFTY
        assignment[i][j] = "0"
        option2 = minForMap(assignment, r, c, idx + 1, numPeople)
        return min(option1, option2)



__author__ = 'amolina'


if __name__ == "__main__":

    T = int(raw_input())

    memo = {}
    for cnt in xrange(T):
        r, c, n = map(int, raw_input().split())
        if (n,r,c) not in memo:
            assignment = collections.defaultdict(lambda:collections.defaultdict(str))
            memo[(n,r,c)] = minForMap(assignment, r, c, 0, n)
        print "Case #%s: %s" % (cnt + 1, memo[(n,r,c)])
