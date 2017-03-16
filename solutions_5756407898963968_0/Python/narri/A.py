import multiprocessing
import sys
import optparse
import os

def memoized(f):
    se = dict()
    def ret(*args):
        if args in se:
            return se[args]
        x = f(*args)
        se[args] = x
        return x
    return ret

import collections
import random
def solve_case(fq, ft, sq, st):
    ok = 0
    last_thing = None
    for i in xrange(1,17):
        if i in ft[fq-1] and i in st[sq-1]:
            ok += 1
            last_thing = i
    if ok == 1:
        return last_thing
    if ok != 0:
        return "Bad magician!"
    return "Volunteer cheated!"
                            
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    #print "CASES", N
    for t in xrange(N):
        fq = int(cin())
        first_thing = [[int(x) for x in cin().strip().split()]
                      for n in xrange(4)]
        sq = int(cin())
        second_thing = [[int(x) for x in cin().strip().split()]
                      for n in xrange(4)]
        yield (fq, first_thing, sq, second_thing)
        
def main():
    parser = optparse.OptionParser()
    parser.add_option('--nprocs', type='int', help='parallelize with n procs')
    parser.add_option('--skip', type='int', help='skip this many cases', default=0)
    options, args = parser.parse_args()

    np = options.nprocs
    
    skip = options.skip
    if np is not None:
        pool = multiprocessing.Pool(processes=np)
        procs = []
        cn = 0
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            procs.append((cn, pool.apply_async(solve_case, args=args)))
            cn += 1
        for i, proc in procs:
            ans = proc.get()
            print format_answer(i+1, ans)
    else:
        cn = 0
        #print "OMG"
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            ans = solve_case(*args)
            print format_answer(cn+1, ans)
            cn += 1            

if __name__ == '__main__':
    main()

