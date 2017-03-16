"""Code written using Python 2.7.5, http://www.python.org/"""

import string, re
from itertools import groupby

def calc(case):
    
    oldc = ''
    regex = '^'
    for c in case[0]:
        if c != oldc:
            regex += c+'+'
            oldc = c

    regex += '$'

    prog = re.compile(regex)
    for s in case[1:]:
        result = prog.match(s)
        if not result:
            return "Fegla Won"

    chars = regex.strip('^$').split('+')

    charmap = []
    for c in case:
        charmap += [[[k, len(list(g))] for k, g in groupby(c)]]


    result = 0
    for i in range(len(charmap[0])):

        numbers = []
        for charm in charmap:
            numbers += [charm[i][1]]

        median = len(numbers) / 2

        numbers = sorted(numbers)
        goal = numbers[median]
        result += sum([abs(goal - n) for n in numbers])
        

    return str(result)


f = open('A-large.in', 'r')
lines = [r.strip() for r in f.readlines()]
f.close()
c = int(lines[0].split()[0])
lines = lines[1:]
#print c

cases = []
while len(lines) > 0:
    rows = int(lines[0].split(' ')[0])
    #print rows

    cases += [lines[1:rows+1]]
    lines = lines[rows+1:]

#print cases

of = open('output_a_large.txt', 'w')

for idx, case in enumerate(cases):
    of.write('Case #%(idx)i: %(i)s\n' % {'idx': idx + 1, 'i': calc(case)})

of.close()

