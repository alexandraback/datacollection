import sys
from math import log
basename = "A-large"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

def moves(counts):
    N = len(counts)
    m = min(counts)
    M = max(counts)
    best = None
    for c in range(m, M+1):
        mvs = 0
        for count in counts:
            if count > c:
                mvs += count - c
            elif count < c:
                mvs += c - count
        if best == None or mvs < best:
            best = mvs
    return best

def process(word):
    letters = []
    letters.append([word[0], 1])
    pos = 0
    for i in range(len(word) - 1):
        if word[i+1] == word[i]:
            letters[pos][1] += 1
        else:
            pos += 1
            letters.append([word[i+1], 1])
    return letters

for case in range(1, test_cases+1):
    N = int(input_file.readline().rstrip())
    words = []
    for i in range(N):
        word = input_file.readline().rstrip()
        words.append(process(word))
    if len(set([len(word) for word in words])) != 1:
        solution = "Fegla Won"
    else:
        positions = len(words[0])
        if any([len(set([word[i][0] for word in words])) != 1 for i in 
            range(positions)]):
            solution = "Fegla Won"
        else:
            allmvs = []
            for pos in range(positions):
                allmvs.append(moves([word[pos][1] for word in words]))
            solution = str(sum(allmvs))
    
    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

