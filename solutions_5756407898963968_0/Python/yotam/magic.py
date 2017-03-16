#!/usr/bin/env python
import sys

fin = sys.stdin
fout = sys.stdout
ferr = sys.stderr

def get_io(argv):
    fin = sys.stdin
    fout = sys.stdout
    ifn = ofn = "-"
    if len(argv) == 2:
        bfn = sys.argv[1]
        ifn = bfn + '.in'
        ofn = bfn + '.out'
    if len(argv) > 2:
        ifn = argv[1]
        ofn = argv[2]
    if ifn != '-':
        fin = open(ifn, "r")
    if ofn != '-':
        fout = open(ofn, "w")
    return (fin, fout)

def get_numbers():
    line = fin.readline()
    return map(int, line.split())

def get_number():
    return get_numbers()[0]

def get_line():
    line = fin.readline()
    if len(line) > 0 and line[-1] == '\n':
        line = line[:-1]
    return line

def get_string():
    line = fin.readline()
    return line.strip()

def magic():
    s = [None, None]
    for step in 0,1:
        a = get_number()
        for i in range(1, 5):
            if i == a:
                s[step] = set(get_numbers())
            else:
                get_line()
    possible = set.intersection(s[0], s[1])
    n = len(possible)
    if n == 1:
        r = "%d" % possible.pop()
    elif n == 0:
        r = "Volunteer cheated!"
    else:
        r = "Bad magician!"
    return r

if __name__ == "__main__":
    (fin, fout) = get_io(sys.argv)
    n_cases = get_number()
    for ci in range(n_cases):
        r = -1
        r = magic()
        fout.write("Case #%d: %s\n" % (ci + 1, r))

    fin.close()
    fout.close()
    sys.exit(0)
