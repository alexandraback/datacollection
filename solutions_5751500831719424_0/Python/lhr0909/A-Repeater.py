from itertools import *
from copy import deepcopy
from collections import OrderedDict

def calculate_moves(sets, dicts, n):
    min_moves = -1
    letter_counts = map(lambda d: d[n], dicts)
    for i in xrange(len(letter_counts)):
        moves = 0
        counts_copy = deepcopy(letter_counts)
        baseline = counts_copy.pop(i)
        for j in counts_copy:
            moves += abs(baseline - j)
        if min_moves < 0:
            min_moves = moves
        elif moves < min_moves:
            min_moves = moves
    return min_moves

def custom_reduce(x, y):
    if x == y:
        return x
    elif x == False:
        return False
    else:
        return False

def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        answer = ""
        #data read
        N = int(fin.readline())
        sets = []
        dicts = []
        for i in xrange(N):
            string = fin.readline().strip()
            letters = []
            counts = []
            k = 0
            for j in xrange(len(string)):
                if j == 0:
                    letters.append(string[j])
                    counts.append(1)
                else:
                    if string[j] == letters[k]:
                        counts[k] += 1
                    else:
                        k += 1
                        letters.append(string[j])
                        counts.append(1)
            sets.append(tuple(letters))
            dicts.append(tuple(counts))

        #print sets
        #print dicts
        #print reduce(custom_reduce, sets)
        reduced_set = reduce(custom_reduce, sets)
        if reduced_set == False:
            for s in sets:
                print s
            answer = "Fegla Won"
        else:
            answer = 0
            for i in xrange(len(reduced_set)):
                answer += calculate_moves(sets, dicts, i)
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()

if __name__ == "__main__":
    solve("A-small-attempt4")