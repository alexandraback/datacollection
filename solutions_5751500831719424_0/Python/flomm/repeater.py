import sys
from functools import reduce
import math


def solve(strings):
    c = strings[0][0]
    moves = 0
    splitted_strings = []
    for i, string in enumerate(strings):
        counter = 0
        last_char = string[0]
        splitted_strings.append([])
        for c in string:
            if c == last_char:
                counter += 1
            else:
                splitted_strings[-1].append((last_char, counter))
                last_char = c
                counter = 1
        splitted_strings[-1].append((last_char, counter))

    for i in range(len(splitted_strings[0])):
        try:
            current = list(x[i] for x in splitted_strings)
        except:
            return 'Fegla Won'
        last = current[0][0]
        temp = 0
        for element in current:
            if element[0] != last:
                return 'Fegla Won'
            else:
                last = element[0]
                temp += element[1]
        length = round(temp/len(splitted_strings))
        for element in current:
            moves += abs(length - element[1])

    return moves

if __name__ == '__main__':
    in_file = sys.argv[1]
    f = open(in_file, 'r')
    cases = int(f.readline())
    for i in range(cases):
        num_of_strings = int(f.readline())
        strings = []
        for _ in range(num_of_strings):
            strings.append(f.readline().replace('\n', ''))
        print('Case #{0}: {1}'.format(i+1, solve(strings)))
    f.close()