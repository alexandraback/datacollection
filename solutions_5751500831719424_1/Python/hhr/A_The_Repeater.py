#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import argparse
import difflib
import numpy as np

class Case(object):

    def __init__(self, f_out, i, N, strings):
        self.f_out = f_out
        self.i = i
        self.N = N
        self.strings = strings

    def setify(self, s):
        last = '&'
        lst = []
        for e in s:
            if e != last:
                lst.append(e)
                last = e
        return lst

    def median(self, seq):
        return int(np.median(seq))

    def diff(self, seq):
        cal = 0
        me = self.median(seq)
        for e in seq:
            cal += np.abs(e - me)
        return cal

    def check_letters(self):
        strings = self.strings
        base = self.setify(strings[0])
        for i in range(1, len(strings)):
            if base != self.setify(strings[i]):
                return False, 0
        return True, base


    ###################### modify here #####################
    def get_result(self):
        strings = self.strings
        is_iden, base = self.check_letters()
        if not is_iden:
            return 'Fegla Won'

        count_matrix = []
        for ss in strings:
            c = 0
            c_list = []
            last = ss[0]
            for letter in ss:
                if letter == last:
                    c += 1
                else:
                    c_list.append(c)
                    last = letter
                    c = 1
            c_list.append(c)
            count_matrix.append(c_list)
        width = len(count_matrix[0])
        high = len(count_matrix)
        total_moves = 0
        for j in range(width):
            col = [count_matrix[i][j] for i in range(high)]
            total_moves += self.diff(col)
        return total_moves            

    ########################################################

    def run(self):
        result = self.get_result()
        ###################### modify here #####################
        self.f_out.write('Case #%d: ' % self.i)
        self.f_out.write('%s\n' % result)
        ########################################################
        return None


def parse_cmd_args():
    parser = argparse.ArgumentParser(description='initiate a Google code jam contest problem')
    parser.add_argument('input', help='input file path')
    args = parser.parse_args()
    input_path = os.path.abspath(args.input)
    return input_path


def read_line(f_in, typ=None):
    if isinstance(f_in, file):
        line = f_in.readline()
    elif isinstance(f_in, (str, unicode)):
        line = f_in
    else:
        raise TypeError('unknown parameter type: %s' % type(f_in))

    tokens = line.strip().split()
    if typ:
        r = [typ(e) for e in tokens]
    else:
        r = tokens
    return r


def read_a_case(f_in, m, func_list):
    r = []
    for i in range(m):
        line = f_in.readline().strip()
        func = func_list[i]
        r.append(func(line))
    return r


def sample_diff(path_a, path_b):
    with open(path_a) as f_a, open(path_b) as f_b:
        a = f_a.readlines()
        b = f_b.readlines()

    d = difflib.Differ()
    diff = d.compare(a, b)
    print ''.join(list(diff))
    return None


def check_result(in_path, an_path, out_path):
    if os.path.basename(in_path) == 'sample.in':
        # comparing sample answers and output
        print '######### comparing sample answers and output #######'
        sample_diff(an_path, out_path)
    else:
        # print the first k lines in output file
        k = 5
        print '######## the fist %d lines of %s #######' % (k, out_path)
        with open(out_path) as out:
            for i in range(k):
                print out.readline(),
    return None


def main():
    in_path = parse_cmd_args()
    out_path = in_path.rstrip('.in') + '.out'
    an_path = in_path.rstrip('.in') + '.an'

    f_in = open(in_path)
    f_out = open(out_path, 'wb')

    T = read_line(f_in, int)[0]
    print T

    count = 0
    for i in range(T):
        count += 1
        print count
        ############### modify here #######################
        N = read_line(f_in, int)[0]
        strings = []
        for j in range(N):
            s = read_line(f_in)[0]
            strings.append(s)
        c = Case(f_out, i + 1, N, strings)
        ##################################################
        # if count != 3:
        #     continue
        c.run()
        del c
        # break
    f_in.close()
    f_out.close()

    check_result(in_path, an_path, out_path)

    return None


if __name__ == '__main__':
    main()

