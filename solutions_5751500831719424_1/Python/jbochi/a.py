import sys

lines = [line.strip().split(' ') for line in sys.stdin.readlines()]
T = int(lines[0][0])
line = 1

def median(mylist):
    sorts = sorted(mylist)
    length = len(sorts)
    return sorts[length / 2]

def letters_count(word):
    letters = []
    cl = None
    for l in word:
        if l != cl:
            letters.append([l, 0])
            cl = l
        letters[-1][1] += 1
    return letters

for t in range(T):
    cases = int(lines[line][0])
    for _ in range(cases):
        words = [l[0] for l in lines[line+1:line+cases+1]]
    line += cases + 1

    lc = map(letters_count, words)
    letters = [[x[0] for x in w] for w in lc]
    solvable = all(lts == letters[0] for lts in letters)
    solution = "Fegla Won"
    if solvable:
        solution = 0
        for i in range(len(letters[0])):
            counts = [lts[i][1] for lts in lc]
            md = median(counts)
            solution += sum(abs(c - md) for c in counts)
    print "Case #%d: %s" % (t + 1, solution)
