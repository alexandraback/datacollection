"""Code written using Python 2.7.5, http://www.python.org/"""

import string, re
from itertools import groupby

def calc(case):
    
    #print case

    oldc = ''
    regex = '^'
    for c in case[0]:
        if c != oldc:
            regex += c+'+'
            oldc = c

    regex += '$'
    #print regex

    prog = re.compile(regex)
    for s in case[1:]:
        result = prog.match(s)
        if not result:
            return "Fegla Won"

    chars = regex.strip('^$').split('+')

    if len(case) > 2:
        return "Not supported"

    c1 = [[k, len(list(g))] for k, g in groupby(case[0])]
    c2 = [[k, len(list(g))] for k, g in groupby(case[1])]

    result = 0
    for i in range(len(c1)):
        result += abs(c1[i][1] - c2[i][1])


    return str(result)


f = open('A-small.in', 'r')
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

of = open('output_a_small.txt', 'w')

for idx, case in enumerate(cases):
    of.write('Case #%(idx)i: %(i)s\n' % {'idx': idx + 1, 'i': calc(case)})

of.close()

