'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


curr_file_name = 'A-large'
#curr_file_name = 'A-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        N = int(input_lines.pop(0))
        M = map(int, input_lines.pop(0).split(' '))
        case_inputs.append(M)
    return case_inputs
    
def process_func(func_input):
    M = func_input
    D = []
    for i in range(len(M) - 1):
        D.append(M[i+1]-M[i])
    print D
    
    # first method
    r1 = sum(filter(lambda x:x<0, D)) * -1
    #print r1
    
    # second method
    rateper10 = map(lambda x:-1*x, filter(lambda x:x<0, D))
    rateper10.append(0)
    rate = max(rateper10)
    r2 = 0
    for i in range(len(M)-1):
        r2 += min(rate, M[i])
    #print r2
    return '{} {}'.format(r1, r2)

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


