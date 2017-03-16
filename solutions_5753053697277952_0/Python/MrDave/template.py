
import csv
import itertools
import copy
import time
import numpy as np


def read_file(filename):
    f = open(filename)
    csv_r = csv.reader(f, delimiter=' ')
    T = int(csv_r.next()[0])
    test_lst = []
    for i in xrange(T):
        N = int(csv_r.next()[0])
        test_lst.append((N, [int(e) for e in csv_r.next()]))
    f.close() 
    return test_lst 


def solve_test(test_case):
    N, l=test_case
    res=[]
    while not all([e==0 for e in l]):
        m=np.max(l)
        idx_lst=[i_e for i_e, e in enumerate(l) if e == m]
        if len(idx_lst)>1 and sum(l)!=3:
            res.append((idx_lst[0],idx_lst[1]))
            l[idx_lst[0]]-=1
            l[idx_lst[1]]-=1
        else:
            res.append((idx_lst[0],))
            l[idx_lst[0]]-=1
    s=""
    for e in res:
        if len(e) == 2:
            s+= chr(ord('A')+e[0])+chr(ord('A')+e[1])
        else:
            s+= chr(ord('A')+e[0])
        s+=" "
    return s
        

def main(filename):
    test_lst = read_file(filename)
    for i_test, test_case in enumerate(test_lst):
        res = solve_test(test_case)
        print "Case #%i: %s" % (1+i_test, res)


if __name__ == '__main__':
    #main('./simple.in')
    main('./A-small-attempt2.in')
    #main('./A-large.in')


