__author__ = 'Servy'

import sys


def to_unique_seq(s):
    prev = None
    counter = 0
    result = []
    for c in list(s):
        if c != prev:
            if counter > 0:
                result.append((prev, counter))
            counter = 1
            prev = c
        else:
            counter += 1
    if counter > 0:
        result.append((prev, counter))
    return result


def is_compatible(seq1, seq2):
    if len(seq1) != len(seq2):
        return False
    for i in range(len(seq1)):
        if seq1[i][0] != seq2[i][0]:
            return False
    return True


def calc_moves(seqItems, target):
    res = 0
    for item in seqItems:
        res += abs(item[1] - target)
    return res


def find_best_match(seqItems):
    bestTarget = 1000000000
    for target in range(1, 102):
        moves = calc_moves(seqItems, target)
        if moves < bestTarget:
            bestTarget = moves
    return bestTarget


testNumber = int(sys.stdin.readline().strip())
for test in range(1, testNumber + 1):
    n = int(sys.stdin.readline())
    seqs = []
    for i in range(n):
        s = str(sys.stdin.readline().strip())
        seqs.append(to_unique_seq(s))

    solutionExists = True
    referenceSeq = None
    for seq in seqs:
        if referenceSeq is None:
            referenceSeq = seq
        else:
            if not is_compatible(seq, referenceSeq):
                solutionExists = False
                break

    if solutionExists:
        result = sum(map(find_best_match, zip(*seqs)))
        print("Case #%d: %d" % (test, result))
    else:
        print("Case #%d: Fegla Won" % test)