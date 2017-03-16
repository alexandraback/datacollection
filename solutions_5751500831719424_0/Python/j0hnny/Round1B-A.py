__author__ = 'j0hnny'
import sys


def convert(str):
    prev = None
    word = ""
    for s in str:
        if s == prev:
            continue
        prev = s
        word += s
    return word


def match(strs):
    pat = convert(strs[0])
    for str in strs:
        if convert(str) == pat:
            continue
        else:
            return False
    return True


def unify(strs):
    N = len(strs)
    ids = [0 for i in range(N)]
    prev = strs[0][0]
    mut = 0
    total_len = sum([len(x) for x in strs])
    while sum(ids) < total_len:
        m = 0
        n = 0
        for i in range(N):
            if strs[i][ids[i]] == prev:
                ids[i] += 1
                m += 1
            else:
                n += 1

        #print m, n
        if m < n:
            mut += m
        else:
            mut += n

        if n == N:
            prev = strs[0][ids[0]]
            for j in range(N):
                ids[j] += 1
    return mut


def check(strs):
    print "\n \n CASE:"
    #print strs
    if not match(strs):
        return "Fegla Won"
    else:
        val = unify(strs)
        return "%d" % val


if __name__ == '__main__':
    results = []

    with open('A-small-attempt0.in', 'r') as input:
        cases = int(input.readline())
        for case in range(cases):
            lines = int(input.readline())

            l = [input.readline() for i in range(lines)]
            results.append(check(l))

    with open('output', 'w') as output:
        for case in range(cases):
            res = results[case]
            s = 'Case #%d: %s\n' % (case+1, res)
            print s
            output.write(s)