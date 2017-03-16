#!/usr/bin/env python
# -*- coding: UTF-8 -*-
import argparse
import itertools
import sys

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-in', '--input', 
        metavar='FILE', 
        action='store', 
        type=argparse.FileType('r'), 
        help='input file', 
        default=sys.stdin)
    parser.add_argument('-out', '--output', 
        metavar='FILE', 
        action='store', 
        type=argparse.FileType('w'), 
        help='output file', 
        default=sys.stdout)
    (known_args, unknown_args) = parser.parse_known_args()
    
    T = int(known_args.input.readline().rstrip('\n'))
    
    for i in xrange(T):
        N = int(known_args.input.readline().rstrip('\n'))
        string_list = list()
        for j in xrange(N):
            string_list.append(known_args.input.readline().rstrip('\n'))
        x = repeater(string_list)
        known_args.output.write('Case #{0:d}: '.format(i + 1))
        if x < 0:
            known_args.output.write('Fegla Won\n')
        else:
            known_args.output.write('{0:d}\n'.format(x))

def repeater(string_list):
    chr_list_set = set()
    freq_list_list = list()
    for s in string_list:
        chr_list = list()
        freq_list = list()
        for k, g in itertools.groupby(s):
            chr_list.append(k)
            freq_list.append(len(list(g)))
        chr_list_set.add(''.join(chr_list))
        if len(chr_list_set) != 1:
            return -1
        freq_list_list.append(freq_list)
    simplified_string = chr_list_set.pop()
    distance = int()
    for i in xrange(len(simplified_string)):
        prog = [freq_list[i] for freq_list in freq_list_list]
        distance += find_minimum(prog)
    return distance

def find_minimum(num_list):
    minimum = None
    for x in range(min(num_list), max(num_list)+1):
        object_function = sum([abs(c-x) for c in num_list])
        if minimum is None or object_function < minimum:
            minimum = object_function
    return minimum

if __name__ == '__main__':
    main()
