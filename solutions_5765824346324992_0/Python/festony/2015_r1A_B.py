'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'B-large'
curr_file_name = 'B-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        B, N = map(int, input_lines.pop(0).split(' '))
        M = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([B, N, M])
    return case_inputs
    
def process_func(func_input):
    B, N, M = func_input
    if N <= B:
        return N
    
    # print B, N, M
    # b and n start from 0
    def testBwithNinsub(b, n):
        waittime = 0
        if n > 0:
            waittime = M[b] * n
        customerahead = n
        for i in range(b):
            c = int(math.ceil((waittime + 1) / float(M[i])))
            customerahead += c
        for i in range(b+1, B):
            c = int(math.ceil(waittime / float(M[i])))
            customerahead += c
        # print 'testing ',b,n,': result', customerahead
        if customerahead+1 > N:
            return -1
        if customerahead+1 < N:
            return 1
        return 0
    
    def testB(b):
        up = N - 1
        down = 0
        
        while testBwithNinsub(b, up) > 0:
            up *= 2
        if testBwithNinsub(b, up) == 0:
            return True

        middle = (up + down) / 2
        while up - down > 1:
            testr = testBwithNinsub(b, middle)
            if testr > 0:
                down = middle
            elif testr < 0:
                up = middle
            else:
                return True
            middle = (up + down) / 2
        if testBwithNinsub(b, up) == 0:
            return True
        if testBwithNinsub(b, down) == 0:
            return True
        return False
    
    for i in range(B):
        if testB(i):
            return i+1
    
    return -1

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


