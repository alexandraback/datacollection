#!/usr/bin/env python


def get_char_and_cnt(string):
    if len(string) == 0:
        return None, None, None
    else:
        char = string[0]
        idx = 1
        try:
            while string[idx] == char:
                idx += 1
            return char, idx, string[idx:]
        except IndexError:
            return char, idx, ''

def get_min_action_cnt_char_to_be_same(cnts):
    min_num = min(cnts)
    max_num = max(cnts)
    min_action = 10000000
    for n in range(min_num, max_num + 1):
        action = 0
        for cnt in cnts:
            action += abs(cnt - n)
        min_action = min(min_action, action)
    return min_action



def get_min_action_cnt_to_be_same(strings):
    char_and_cnts_list = list()
    string_cnt = len(strings)

    first_string = strings[0]
    strings = strings[1:]
    while len(first_string) > 0:
        the_char, cnt, first_string = get_char_and_cnt(first_string)
        cnts = list()
        cnts.append(cnt)
        for i in range(string_cnt-1):
            char, cnt, strings[i] = get_char_and_cnt(strings[i])
            if the_char != char:
                return -1
            else:
                cnts.append(cnt)
        char_and_cnts_list.append( (the_char, cnts) )
    for string in strings:
        if len(string) > 0:
            return -1
    total_action = 0
    for char, cnts in char_and_cnts_list:
        total_action += get_min_action_cnt_char_to_be_same(cnts)
    return total_action


def solve(lines):
    strings = lines
    action_cnt = get_min_action_cnt_to_be_same(strings)
    if action_cnt == -1:
        return 'Fegla Won'
    else:
        return str(action_cnt)


import sys
#import pdb

if __name__ == '__main__':
    filename_prefix = sys.argv[1]
    filename_in = filename_prefix + ".in"
    filename_out = filename_prefix + ".out"

    with open(filename_in, 'r') as file_in:
        lines = file_in.readlines()

    testcnt = int(lines[0])
    idx = 1

    with open(filename_out, 'w') as file_out:
        #pdb.set_trace()
        for test in range(testcnt):
            string_cnt = int(lines[idx].strip())
            idx += 1
            res = solve(lines[idx:idx+string_cnt])
            file_out.write("Case #%d: %s\n" % (test + 1, res))
            idx += string_cnt
