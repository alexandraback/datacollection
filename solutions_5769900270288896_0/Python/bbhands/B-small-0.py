#!/usr/bin/python
# -*- coding: utf-8 -*-


if __name__ == "__main__":

    fin = open("B-small-0.in", "r")
    fout = open("B-small-0.out", "w")
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
        elif R == 1 or C == 1:
            if R*C%2:
	        answer = 2*(N-R*C/2-1)
	    else:
	        answer = 1 + 2*(N-R*C/2-1)
	elif R == 2 or C == 2:
	    answer = 2*(N-R*C/2) + max(N-R*C/2-2, 0)
	elif min(R, C) == 3:
	    if R*C == 9:
		if N == 8:
		    answer = total - 4
		else:
	            answer = total - 3*(R*C-N)
	    elif R*C == 12:
		if N == 7:
		    answer = total - 4-3-3-3-2
		elif N == 11:
		    answer = total - 4 - 3*(R*C-N-1)
		
	    elif R*C == 15:
		if N == 14 or N == 13:
		    answer = total - 4*(R*C-N)
	        elif N == 12 or N == 11:
		    answer = total - 8 - 3*(R*C-N-2)
		else:
		    answer = total - 4 - 3*(R*C-N-1)
        elif min(R, C) == 4:
	    if N == 15 or N == 14:
	        answer = total - 4*(R*C-N)
	    elif N in [13,12,11,10]:
	        answer = total - 8 - 3*(R*C-N-2)
	    else:
		answer = total - 8 - 12 - 2*(R*C-N-6)
	
        fout.write("Case #%i: %s\n" % (t+1, answer))

    fin.close()
    fout.close()

