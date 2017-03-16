#! /usr/bin/python

import os, sys
from collections import OrderedDict

def debug(msg):
    if len(sys.argv) > 1 and sys.argv[1] == '-d':
        sys.stderr.write(msg)
        sys.stderr.write('\n')

T = int(sys.stdin.readline())
input_data = {}


def solve(strings, strings_uniq):
    check_str = strings_uniq[0]
    ret = 'Unkown'
    string0 = strings[0]
    check_equal = True
    for i in range(0, N):
        if string0 != strings[i]:
            check_equal = False
            break
    if check_equal:
        return 0
    for i in range(0, N):
        if check_str != strings_uniq[i]:
            return "Fegla Won"
    # offset of string:
    strings_offset = []
    for i in range(0, N):
        strings_offset.append(0)
    # loop for each letter
    loop_for = len(strings_uniq[0])
    debug('string ref = %s' % strings_uniq[0])
    total_moves = 0
    for l in range(0, loop_for):
        strings_letter_count = []
        letter = strings_uniq[0][l]
        idx = 0
        debug('letter = %s' % letter)
        for i in range(0, N):
            string = strings[i]
            count_letter = 0
            for j in range(strings_offset[i], len(string)):
                #debug('i=%s, j=%s' % (i, j))
                if string[j] == letter:
                    count_letter += 1
                else:
                    strings_offset[i] = j 
                    break
            strings_letter_count.append(count_letter)
        debug('stringlettercount = %s' % strings_letter_count)
        debug('strings_offset = %s' % strings_offset)
        # for the first:
        base = strings_letter_count[0]
        moves = 0
        for j in range(0, N):
            moves += abs(strings_letter_count[j] - base)
        best_moves = moves
        for i in range(1, N):
            base = strings_letter_count[i]
            moves = 0
            for j in range(0, N):
                moves += abs(strings_letter_count[j] - base)
            if moves < best_moves:
                best_moves = moves
        debug('local best = %s' % best_moves)
        total_moves += best_moves
    return total_moves


# For each test case
for t in range(1, T+1):
    N = int(sys.stdin.readline())
    strings = []
    strings_uniq = []
    for i in range(0, N):
        strings.append(sys.stdin.readline().strip('\n'))
    min_len = len(strings[0])
    max_len = len(strings[0])
    for i in range(0, N):
        debug(strings[i])
        #min_len = min(len(strings[i]), min_len)
        #max_len = max(len(strings[i]), max_len)
        str_list = []
        str_list.append(strings[i][0])
        str_char = strings[i][0]
        for j in range(1, len(strings[i])):
            if strings[i][j] != str_char:
                str_list.append(strings[i][j])
                str_char = strings[i][j]
        strings_uniq.append(''.join(str_list))
    debug('min = %s, max = %s, %s' % (min_len, max_len, strings_uniq))
    ret = solve(strings, strings_uniq)
    sys.stdout.write('Case #%s: %s\n' % (t, ret))
