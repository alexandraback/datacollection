#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

f_input = open(sys.argv[1])
problems = int(f_input.readline().rstrip())
for probnum in xrange(1, problems+1):
    first_line = int(f_input.readline().rstrip())
    first_table = [map(int, f_input.readline().rstrip().split()) for i in xrange(4)]
    second_line = int(f_input.readline().rstrip())
    second_table = [map(int, f_input.readline().rstrip().split()) for i in xrange(4)]

    first_choice = set(first_table[first_line-1])
    second_choice = set(second_table[second_line-1])

    first_choice.intersection_update(second_choice)
    
    if len(first_choice) == 0:
        comment = "Volunteer cheated!"
    elif len(first_choice) > 1:
        comment = "Bad magician!"
    else:
        comment = str(first_choice.pop())
    print("Case #%i: %s" % (probnum, comment))
    
