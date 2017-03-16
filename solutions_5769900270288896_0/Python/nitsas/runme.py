#!/usr/bin/env python3
"""
Noisy Neighbors problem
for Google Code Jam 2015
Round 1B

Link to problem description:
https://code.google.com/codejam/contest/8224486/dashboard#s=p1

Author: 
  Chris Nitsas
  (nitsas)

Language:
  Python 3(.4)

Date:
  May, 2015

Usage:
  python3 runme.py input_file
"""


import sys
import argparse
from collections import namedtuple
from itertools import combinations
# modules I've written:
from helpful import *


_program_description = \
'''TEMPLATE PROGRAM DESCRIPTION'''


_input_file_description = \
'''TEMPLATE INPUT FILE DESCRIPTION'''


TestCase = namedtuple('TestCase', ['rows', 'columns', 'N'])


def parse_args():
    """
    Parse the command line arguments and return them in a namespace.
    """
    parser = argparse.ArgumentParser(description=_program_description)
    parser.add_argument('input_file', help=_input_file_description)
    #parser.add_argument('-v', '--verbose', action='store_true', 
    #                    default=False, help='show progress')
    args = parser.parse_args()
    return args


class Building:
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
    
    def compute_min_unhappiness_level(self, N):
        apartments = range(self.rows * self.columns)
        placements = combinations(apartments, N)
        
        min_unhappiness = float('inf')
        for placement in placements:
            placement_set = set(placement)
            unhappiness = self._unhappiness_level_of_placement(placement_set)
            if unhappiness < min_unhappiness:
                min_unhappiness = unhappiness
        return min_unhappiness
    
    def _unhappiness_level_of_placement(self, placement):
        unhappiness_level = 0
        for apartment_no in placement:
            ap_row = apartment_no // self.columns
            ap_column = apartment_no % self.columns
            
            if ap_row > 0:
                south_ap_no = (ap_row - 1) * self.columns + ap_column
                if south_ap_no in placement:
                    unhappiness_level += 1
            if ap_column > 0:
                west_ap_no = apartment_no - 1
                if west_ap_no in placement:
                    unhappiness_level += 1
        return unhappiness_level


def read_test_case(file_):
    """Read and return a single test case."""
    return TestCase(*read_list_of_int(file_))


def output_of_test_case(tc):
    """Return the output of a single test case as a string."""
    building = Building(tc.rows, tc.columns)
    return str(building.compute_min_unhappiness_level(tc.N))


def main(filename):
    with open(filename, 'r', encoding='utf-8') as f:
        T = read_int(f)
        test_cases = [read_test_case(f) for i in range(T)]
    for i, tc in enumerate(test_cases, start=1):
        print("Case #{}: ".format(i) + output_of_test_case(tc))
    return 0


if __name__ == "__main__":
    status = main(parse_args().input_file)
    sys.exit(status)
