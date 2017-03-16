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
        t = int(input_lines.pop(0))
        F = []
        for j in range(t):
            F.append(input_lines.pop(0))
        case_inputs.append(F)
    return case_inputs

def get_skeleton(s):
    sq = list(s)
    sk = []
    if sq == []:
        return sk
    sk.append(sq[0])
    for i in range(1, len(sq)):
        if sq[i] != sk[-1]:
            sk.append(sq[i])
    return sk

def sepa(s):
    secs = []
    if len(s) == 0:
        return secs
    sec = [s[0], 1]
    for i in range(1, len(s)):
        if s[i] == sec[0]:
            sec[1] += 1
        else:
            secs.append(sec)
            sec = [s[i], 1]
    secs.append(sec)
    return secs

#def sg_cmp(sg, target):
#    mv = 0
#    for i in range(len(sg)):
#        sec1 = sg[i]
#        sec2 = target[i]
#        mv += int(math.fabs(sec1[1] - sec2[1]))
#    return mv
#        
#
#def calc_mv(sgs, target):
#    mv = 0
#    for sg in sgs:
#        mv += sg_cmp(sg, target)
#    return mv
#
#def calc_step(s, target):
#    return

def calc_mv(sec, target):
    mv = 0
    for s in sec:
        mv += int(math.fabs(s - target))
    return mv

def get_min_mv(sec):
    mvs = []
    l = min(sec)
    u = max(sec)
    for i in range(l, u+1):
        mvs.append(calc_mv(sec, i))
    return min(mvs)

def process_func(func_input):
    F = func_input
    sk = tuple(get_skeleton(F[0]))
    sgs = []
    for f in F:
        tmpsk = tuple(get_skeleton(f))
        if sk != tmpsk:
            return 'Fegla Won'
        sgs.append(sepa(f))
    print sgs
    secs = []
    
    for i in range(len(sk)):
        sec = []
        for sg in sgs:
            sec.append(sg[i][1])
        secs.append(sec)
    
    print secs
    
    mv = 0
    
    for s in secs:
        mv += get_min_mv(s)
    
    return mv

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


