#!/usr/bin/python3
# -*- coding: utf-8 -*-

def main():
    in_file = open("A-large.in", mode='r')
    out_file = open("A-large.out", mode='w')

    T = int(in_file.readline())
    
    for i in range(T):
        N = int(in_file.readline())
        strings = []
        for j in range(N):
            strings.append(normalize(in_file.readline()))
        result = match(strings)

        out_file.write("Case #" + str(i+1) + ": " + result + "\n") 

    in_file.close()
    out_file.close()

def match(strings):
    letters = [[t[0] for t in s] for s in strings]
    counts = [[int(t[1]) for t in s] for s in strings]

    for i in range(len(strings)-1):
        if len(letters[i]) != len(letters[i+1]):
            return "Fegla Won"
        if letters[i] != letters[i+1]:
            return "Fegla Won"

    result = 0
    new_counts = []
    for i in range(len(counts[0])):
        new_counts.append([c[i] for c in counts])

    for i in range(len(new_counts)):
        m = sorted(new_counts[i])[len(new_counts[i])//2]
        result += sum([abs(c - m) for c in new_counts[i]])

    return str(result)


def normalize(ss):
    lastChar = ''
    lastCount = 0;
    result = []

    for c in ss:
        if c == lastChar:
            lastCount += 1
        else:
            if lastCount != 0:
                result.append((lastChar, lastCount))
            lastChar = c
            lastCount = 1

    return result

    
if __name__ == '__main__':
    main()