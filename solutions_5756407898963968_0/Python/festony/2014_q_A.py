'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'A-large-practice'
curr_file_name = 'A-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        row1 = int(input_lines.pop(0))
        arr1 = []
        for i in range(4):
            arr1.append(map(int, input_lines.pop(0).split(' ')))
        row2 = int(input_lines.pop(0))
        arr2 = []
        for i in range(4):
            arr2.append(map(int, input_lines.pop(0).split(' ')))
        case_inputs.append([row1, arr1, row2, arr2])
    return case_inputs
    
def process_func(func_input):
    print func_input
    row1, arr1, row2, arr2 = func_input
    g1 = arr1[row1-1]
    g2 = arr2[row2-1]
    print g1
    print g2
    poss = []
    for n in g1:
        if n in g2:
            poss.append(n)
    print poss
    if poss == []:
        return 'Volunteer cheated!'
    if len(poss) > 1:
        return 'Bad magician!'
    return poss[0]

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


