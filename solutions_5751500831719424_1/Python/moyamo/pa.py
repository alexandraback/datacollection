#!/usr/bin/env python3

def read_input():
    N = int(input())
    words = list()
    for i in range(N):
        words.append(input())
    return words

def to_chars(word):
    chars = list()
    old_char = ''
    for c in word:
        if c != old_char:
            chars.append([c, 1])
            old_char = c
        else:
            chars[-1][1] += 1
    return chars

def solve():
    words = read_input()
    char_count = list()
    for w in words:
        char_count.append(to_chars(w))
    for i in range(len(char_count) - 1):
        if len(char_count[i]) == len(char_count[i + 1]):
            for j in range(len(char_count[i])):
                if char_count[i][j][0] != char_count[i + 1][j][0]:
                    return 'Fegla Won'
        else:
            return 'Fegla Won'
    acc = 0
    for i in range(len(char_count[0])):
        mini = float('inf')
        for j in range(len(char_count)):
            sumi = 0
            for k in range(len(char_count)):
                sumi += abs(char_count[j][i][1] - char_count[k][i][1])
            if sumi < mini:
                mini = sumi
        acc += mini
    return str(acc)




def main():
    T = int(input())
    for i in range(T):
        print('Case #' + str(i + 1) + ': ' + solve())

main()
