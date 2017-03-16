
import csv
import itertools
import copy
import time


def read_file(filename):
    f = open(filename)
    csv_r = csv.reader(f, delimiter=' ')
    T = int(csv_r.next()[0])
    test_lst = []
    for i in xrange(T):
        B, N = csv_r.next()
        m_lst = [int(e) for e in csv_r.next()]
        test_lst.append([int(B), int(N), m_lst])
    f.close() 
    return test_lst 


def solve_test(test_case):
    B, N, m_lst = test_case
    p, z = 1, 0
    for m in m_lst:
        p *= m
    z = sum([p / m for m in m_lst])
    N = N % z
    if N == 0:
        N = z
    free_lst = [0] * len(m_lst)
    next_t = 0
    while True :
        for i_e, e in enumerate(free_lst):
            free_lst[i_e] = max(0, free_lst[i_e] - next_t) 
            if N-1>0 and free_lst[i_e] == 0:
                N-=1
                free_lst[i_e] = m_lst[i_e]
        next_t = min(free_lst)
        if N-1 == 0 and min(free_lst) == 0:
             break
    return 1+min([i_e for i_e, e in enumerate(free_lst) if e == 0])


def init():
    pass


def main(filename):
    test_lst = read_file(filename)
    init()
    for i_test, test_case in enumerate(test_lst):
        res = solve_test(test_case)
        print "Case #%i: %s" % (1+i_test, res)


if __name__ == '__main__':
    main('./B-small-attempt2.in')
    #main('simple.in')
    #main('./C-small-attempt2.in')

