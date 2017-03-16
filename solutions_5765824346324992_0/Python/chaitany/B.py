#!/usr/bin/env python
#
# Copyright (c) 2013 NetApp, Inc.
# All rights reserved.
#
"""
"""
# IMPORTANT
# Run as 
# python template.py < A-small-practice.in >& A-small-practice.out

from __future__ import print_function
import argparse
import getpass
import glob
import imp
import itertools
import logging
import pkg_resources
import pkgutil
import sys
import re
import ystockquote
import requests
import threading
from multiprocessing import Process
import time
import bisect


# This function will take a certain number, and generate the 'base' representation
# of it. And it will output that in the form of a array ..
# you have to provide how many 'bits' you want .. if there are excess, the leading
# ones will be zero.
def convert_number_to_bit_string(number, num_bits, base=2):
    string_bits = [0 for i in range(num_bits)]
    index = len(string_bits) - 1
    while index >= 0:
        string_bits[index] = number%base
        number = number / base
        index = index -1
    return string_bits

#USE THE function bisect.insort() whenever necessary
#If a is sorted in ascending order, e.g a = [5, 7, 10, 17]
# bisect.insort(a, 12) will insert 12 into the sorted array using binary search.
# bisect.insort(a, 12) will result in [5, 7, 10, 12, 17]

logger = logging.getLogger(__name__)

def lcm(x, y):
   """This function takes two
   integers and returns the L.C.M."""

   # choose the greater number
   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

def simulate_customer_array(M_array, N):
    customer_assignment = []
    lcm_value = M_array[0]
    for index in range(len(M_array)):
        if index >= 1:
            lcm_value = lcm(lcm_value, M_array[index])
    current_time = 0
    time_left = [0 for n in M_array]
    while current_time < lcm_value:
        for index in range(len(time_left)):
            if time_left[index] == 0:
                customer_assignment.append(index)
                time_left[index] = M_array[index]
        current_time = current_time + 1
        for index in range(len(time_left)):
            time_left[index] = time_left[index] - 1
        
    mod_value = N%len(customer_assignment)
    if mod_value == 0:
        mod_value = len(customer_assignment) - 1
    else:
        mod_value = mod_value - 1

    #logger.info("lcm_value = {0} time_left after lcm_value =  {1} customers = {2}".format(lcm_value, time_left, customer_assignment))

    return customer_assignment[mod_value] + 1 
    
def main():
    streamformat = "%(message)s"
    logging.basicConfig(level=logging.INFO,
                        format=streamformat)
    data = sys.stdin.readlines()
    i = 0
    nums = [int(n) for n in data[i].split()]
    num_test_cases = nums[0]
    for j in range(num_test_cases):
        i = i+1
        nums = [int(n) for n in data[i].split()]
        B = nums[0]
        N = nums[1]
        i = i+1
        nums = [int(n) for n in data[i].split()]
        M_array = nums
        answer = simulate_customer_array(M_array, N)
        logger.info("Case #{0}: {1}".format(j+1, answer))

if __name__ == "__main__":
    main()
