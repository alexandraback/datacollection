#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

    int_to_letter = {1:'A', 2:'B', 3:'C', 4:'D', 5:'E',
                     6:'F', 7:'G', 8:'H',  9:'I',  10:'J',
                     11:'K', 12:'L', 13:'M', 14:'N', 15:'O',
                     16:'P', 17:'Q', 18:'R', 19:'S', 20:'T',
                     21:'U', 22:'V', 23:'W', 24:'X', 25:'Y', 26:'Z'}

    N = readint()
    P = readarray(int)

    count = {}
    for p_i, p in enumerate(P):
        count[int_to_letter[p_i + 1]] = p


    if N == 2:
        exit = ['AB']*count['A']

    else:
        exit = []
        while True:

            # exit if count > 1
            max_count = 0
            max_letter_set = set()
            for letter in count:
                if count[letter] > max_count:
                    max_count = count[letter]
                    max_letter_set = set([letter])
                elif count[letter] == max_count: 
                    max_letter_set.add(letter)

            if max_count == 0:
                break

            if max_count > 1:
                this_letter = list(max_letter_set)[0]
                exit.append(this_letter)
                count[this_letter] -= 1

            # else exit single if odd
            elif len(max_letter_set) % 2 == 1:
                this_letter = list(max_letter_set)[0]
                exit.append(this_letter)
                count[this_letter] -= 1

            # else exit pair
            else:
                this_letter = list(max_letter_set)[0]
                other_letter = list(max_letter_set)[1]
                exit.append(this_letter + other_letter) 
                count[this_letter] -= 1
                count[other_letter] -= 1


    print 'Case #%i:'%(_t+1), ' '.join(exit)
    sys.stdout.flush()
