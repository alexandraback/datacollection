__author__ = 'Lior'
import itertools


def solve(R, C, N):
    if R*C == N:
        return R*(C-1)+C*(R-1)
    if N <= R*C/2:
        return 0


    if R == 1 or C == 1:
        if (R*C)%2 == 0:
            if N <= R*C/2:
                return 0
            if N == R*C/2 + 1:
                return 1
            return 1+(N-(R*C/2)-1)*2
        if (R*C)%2 == 1:
            if N <= (R*C+1)/2:
                return 0
            return 2*(N-(R*C+1)/2)

    if (R*C) % 2 == 1:
        if N <= R*C/2 + 1:
            return 0
        done = R*C/2
        if N <= done + 4:
            return (N-done)*2
        done += 4
        payment = 8
        three_squares = ((R-2)/2)*2 + ((C-2)/2)*2
        if N <= done + three_squares:
            return payment + (N-done)*3
        done += three_squares
        payment += three_squares*3
        return payment + (N-done)*4

    # R*C is even:
    if N < R*C/2:
        return 0
    done = R*C/2
    if N <= done + 2:
        return (N-done)*2
    payment = 4
    done += 2
    three_squares = ((R-2) if (R%2)==0 else ((R-1)/2+(R-3)/2)) + ((C-2) if (C%2)==0 else ((C-1)/2+(C-3)/2))
    #print 'three_squares', three_squares
    #print 'payment', payment
    if N <= done + three_squares:
        return payment + (N-done)*3
    payment += three_squares*3
    done += three_squares
    return payment + (N-done)*4


def process_files(in_file, out_file):
    num_of_test_cases = int(in_file.next().strip())
    for test_number in xrange(num_of_test_cases):
        R, C, N = [int(a) for a in in_file.next().strip().split(' ')]
        assert N <=R*C
        print 'Test number', test_number+1, R, C, N
        result = solve(R, C, N)
        print result
        out_file.write('Case #%d: %s\n' % (test_number+1, result))

if __name__ == '__main__':
    import sys, os
    in_file = sys.argv[1]
    out_file = in_file.replace('.in', '.out')
    with open(in_file, 'rb') as in_file:
        with open(out_file, 'wb') as out_file:
            process_files(in_file, out_file)
