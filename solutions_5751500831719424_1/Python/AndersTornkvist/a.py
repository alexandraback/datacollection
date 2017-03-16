#!/usr/bin/python

import os
import sys
import re

def problem_a(N, lines):
    order = []
    assert(len(lines)>1)
    last = ''
    for char in lines[0]:
        if char!=last:
            order.append(char)
            last = char
    counts = []
    for line in lines:
        my_count = []
        last = ''
        found = 0
        for char in line:
            if char!=last:
                if len(order)==found or order[found]!=char:
                    return 'Fegla Won'
                found += 1
                last = char
                my_count.append(0)
            else:
                my_count[-1] += 1
        if len(order)!=found:
            return 'Fegla Won'
        counts.append(my_count)
    total = 0
    for (inx, char) in enumerate(order):
        try:
            current = [x[inx] for x in counts]
        except IndexError:
            return 'Fegla Won'
        lowest = None
        for a in range(min(current), max(current) + 1):
            extra = 0
            for x in current:
                extra += abs(x - a)
            if lowest is None or extra < lowest:
                lowest = extra
        total += lowest
    return str(total)

def find_input_and_output_files():
    files = sorted(list(filter(os.path.isfile, os.listdir('.'))), reverse=True)
    patterns = ['^[A-Z]-large(-(attempt\d?|practice(-\d)?))?\.in$', '^[A-Z]-small(-(attempt\d?|practice(-\d)?))?\.in$', '^sample\.in$']
    for pattern in patterns:
        prog = re.compile(pattern)
        for file in files:
            if prog.match(file):
                return [file, re.sub('\.in$', '', file) + '.out']
    return ['input.in', 'output.out']

def main():
    files = find_input_and_output_files()
    print(files)
    with open(files[0], 'r') as f:
        with open(files[1], 'w') as o:
            T = int(f.readline().rstrip('\n'))
            for i in range(1, T+1):
                N = int(f.readline().rstrip('\n'))
                lines = []
                for j in range(N):
                    lines.append(f.readline().rstrip('\n'))
                result = "Case #" + str(i) + ": " + problem_a(N, lines)
                print(result)
                o.write(result + "\n")

if __name__=="__main__":
    main()
