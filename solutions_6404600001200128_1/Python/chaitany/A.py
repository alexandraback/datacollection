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

def get_min_for_any(nums):
    sum_decrs = 0
    for index in range(len(nums)):
        if index >= 1:
            if nums[index-1] - nums[index] >= 0:
                sum_decrs = sum_decrs + nums[index-1] - nums[index]
    return sum_decrs

def get_min_for_constant(nums):
    largest_rate = -1
    for index in range(len(nums)):
        if index >= 1:
            if nums[index-1] - nums[index] >= 0:
                if largest_rate == -1:
                    largest_rate = nums[index-1] - nums[index]
                elif nums[index-1] - nums[index] > largest_rate:
                    largest_rate = nums[index-1] - nums[index]
    if largest_rate == -1:
        return 0
    current_value = nums[0]
    sum_decrs = 0
    for index in range(len(nums)):
        if index >= 1:
            temp = nums[index-1] - (largest_rate)
            if temp <= 0:
                sum_decrs = sum_decrs + nums[index-1]
            else:
                sum_decrs = sum_decrs + (largest_rate)
    return sum_decrs

def main():
    streamformat = "%(message)s"
    logging.basicConfig(level=logging.INFO,
                        format=streamformat)
    data = sys.stdin.readlines()
    i = 0
    nums = [int(n) for n in data[i].split()]
    num_test_cases = nums[0]
    for j in range(num_test_cases):
        i = i + 1
        nums = [int(n) for n in data[i].split()]
        N = nums[0]
        i = i+1
        nums = [int(n) for n in data[i].split()]               
        value1 = get_min_for_any(nums)
        value2 = get_min_for_constant(nums)
        logger.info("Case #{0}: {1} {2}".format(j+1, value1, value2))

if __name__ == "__main__":
    main()
