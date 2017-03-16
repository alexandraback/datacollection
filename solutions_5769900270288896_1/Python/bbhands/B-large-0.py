#!/usr/bin/python
# -*- coding: utf-8 -*-


if __name__ == "__main__":

    fin = open("B-large-0.in", "r")
    fout = open("B-large-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        R, C, N = tuple(map(int, fin.readline().strip().split()))

	total = 2*R*C - R - C
	if N == 0:
	    answer = 0
	elif N == R*C:
	    answer = total
	elif R*C%2 == 0 and N <= R*C/2:
            answer = 0
	elif R*C%2 and N <= R*C/2+1:
	    answer = 0
        elif min(R, C) == 1:
            if R*C%2:
	        answer = 2*(N-R*C/2-1)
	    else:
	        answer = 1 + 2*(N-R*C/2-1)
	elif min(R, C) == 2:
	    answer = 2*(N-R*C/2) + max(N-R*C/2-2, 0)
        else:
	    n_four = ((R-2)*(C-2)+1)/2
	    n_two = 4 if R*C%2 else 2
	    n_three = (R*C+1)/2 - n_four - n_two
	    nn_four = (R-2)*(C-2) - n_four
	    nn_two = 4 - n_two
	    nn_three = 2*R + 2*C - 8 - n_three 
            vec = [4]*n_four + [3]*n_three + [2]*n_two
	    vec2 = [4]*nn_four + [3]*nn_three + [2]*nn_two
	    answer = total - max(sum(vec[:R*C-N]), sum(vec2[:R*C-N]))

        fout.write("Case #%i: %s\n" % (t+1, answer))

    fin.close()
    fout.close()

