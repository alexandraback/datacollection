import sys
import itertools
import math
import collections
import functools

def read_word(f):
    return next(f).strip()
def read_int(f, b=10):
    return int(read_word(f), b)
def read_letters(f):
    return list(read_word(f))
def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]
def read_words(f, d=' '):
    return read_word(f).split(d)
def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]
def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]
def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res
def solve(solver,SMALL=True,PRACTICE=False):
    fn = sys.argv[0]
    fn = fn[ 1+fn.rfind('/'): fn.rfind('.') ]
    fn = fn+['-large','-small'][SMALL]+['','-practice'][PRACTICE]
    in_fn = fn + '.in'
    out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i+1, res)
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

#######################################################

def read_case(f):
    ans1 = read_int(f)
    for i in xrange(1,5):
        x = read_ints(f)
        if i == ans1: row1 = x
    ans2 = read_int(f)
    for i in xrange(1,5):
        x = read_ints(f)
        if i == ans2: row2 = x
    return row1,row2

#######################################################

def solver(case):
    r1,r2 = case
    r1 = set(r1)
    r2 = set(r2)
    z = r1.intersection(r2)
    if len(z) == 1: return z.pop()
    if len(z) > 1: return "Bad magician!"
    if len(z) == 0: return "Volunteer cheated!"



    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
