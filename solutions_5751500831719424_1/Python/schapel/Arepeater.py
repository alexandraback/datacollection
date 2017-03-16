#!/usr/bin/python3

from sys import argv

def encode(string):
    encoding = []
    prev = ''
    count = 1
    for i in range(len(string)):
        if string[i] == prev:
            count += 1
        elif prev != '':
            encoding.append((prev, count))
            count = 1
        prev = string[i]
    encoding.append((prev, count))
    return encoding

def answer(strings):
    encoded = []
    for s in strings:
        encoded.append(encode(s))
        #print(encode(s))
    for i in range(len(encoded)):
        if len(encoded[i]) != len(encoded[0]):
            return 'Fegla Won'
        for j in range(len(encoded[i])):
            if (encoded[i][j][0] != encoded[0][j][0]):
                return 'Fegla Won'
    moves = 0
    for i in range(len(encoded[i])):
        repeats = []
        for j in range(len(encoded)):
            repeats.append(encoded[j][i][1])
        #print(repeats)
        median = sorted(repeats)[len(repeats) // 2]
        #print(median)
        for r in repeats:
            moves += abs(r - median)
    return moves

if __name__ == '__main__':
    import doctest
    doctest.testmod()

    # Google Code Jam I/O
    infile = open(argv[1])
    cases = int(infile.readline())
    for i in range(cases):
        n = int(infile.readline())
        strings = []
        for j in range(n):
            strings.append(infile.readline().rstrip())
        print("Case #{}: {}".format(i+1, answer(strings)))
