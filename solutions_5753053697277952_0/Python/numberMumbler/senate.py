#!/usr/bin/env python


import sys


__outputTemplate = 'Case #{0}: {1}\n'


def getPlan(n, ps):
    result = []
    while sum(ps):
        if max(ps) == 1 and sum(ps) % 2 == 1:
            i = ps.index(max(ps))
            evac = partyName(i)
            ps[i] -= 1
            result.append(evac)
            continue
        i = ps.index(max(ps))
        evac = partyName(i)
        ps[i] -= 1
        if sum(ps):
            i = ps.index(max(ps))
            evac += partyName(i)
            ps[i] -= 1
        result.append(evac)
        assert max(ps) <= sum(ps)/2.0, '{}'.format(ps)
    return ' '.join(result)


def partyName(n):
    return chr(n+65)


def action(inFile, outFile):
    case = 0
    t = int(inFile.readline())
    for i in range(t):
        case = i + 1
        n = int(inFile.readline())
        ps = [int(p) for p in inFile.readline().strip().split(' ')]
        result = getPlan(n, ps)
        outFile.write(__outputTemplate.format(case, result))


def main():
    """
    command line arguments are:
        input path
        output path (will overwrite existing)
    """
    assert len(sys.argv) == 3
    inputPath, outputPath = sys.argv[1:3]
    with open(inputPath, 'r') as inFile:
        with open(outputPath, 'w+') as outFile:
            action(inFile, outFile)


if __name__ == '__main__':
    main()
