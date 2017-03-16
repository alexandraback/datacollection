__author__ = 'barbapapa'
from collections import *
import pickle
import itertools as itt
import numpy as np
import bisect
import math


def read_input(f_name):
    cases = []
    with open(f_name) as f:
        nr_cases = int(f.readline().strip())
        for c in range(nr_cases):
            nr_strings = int(f.readline().strip())
            str_list = []
            for i in range(nr_strings):
                str = f.readline().strip()
                str_list.append(str)
            cases.append(str_list)
    return cases

def write_output(f_name, results):
    with open(f_name, 'w') as f:
        for i, r in enumerate(results):
            f.write('Case #'+str(i+1)+': '+r+'\n')

def alt_repr(str):
    last_char = ''
    repr = []
    count = 1
    for i in range(len(str)):
        if str[i] == last_char:
            count += 1
        else:
            if last_char != '':
                repr.append((last_char, count))
            last_char = str[i]
            count = 1
    repr.append((last_char, count))
    return repr

def get_word(repr):
    word = ''
    for i in repr:
        word += i[0]
    return word

def get_counts(repr_list, i):
    counts = []
    for repr in repr_list:
        counts.append(repr[i][1])
    return counts

def solve_case(data):
    str_list = data
    alt_repr_list = [alt_repr(x) for x in str_list]
    word = get_word(alt_repr_list[0])
    for w in alt_repr_list:
        if get_word(w) != word:
            return 'Fegla Won'
    actions = 0
    for i in range(len(word)):
        counts = get_counts(alt_repr_list, i)
        counts.sort()
        if len(counts) % 2 == 1:
            med = counts[len(counts)//2]
            actions += sum([abs(x-med) for x in counts])
        else:
            med1 = counts[len(counts)//2]
            med2 = counts[len(counts)//2-1]
            act1 = sum([abs(x-med1) for x in counts])
            act2 = sum([abs(x-med2) for x in counts])
            actions += min(act1, act2)
    return str(actions)


#file_name = 'A-test'
file_name = 'A-small-attempt0'
#file_name = 'A-large'
cases = read_input(file_name+'.in')
#print cases
solution = [solve_case(x) for x in cases]
write_output(file_name+'.out', solution)
