#!/usr/bin/env python

import fileinput 
#from __future__ import print_function
import sys
 
 
def read_int():
    return int(input())
 
 
def read_ls():
    s = sys.stdin.readline()
    return [int(x) for x in s.split()]
 
 
def run():
    return 0
 
 
def main():
    # Read number of test cases
    for case in range(read_int()):
        # input data
        ans1 = read_int()

        for row in range(1,5):
            list1 = read_ls()
            if ans1 == row:
                set1 = set(list1)

        ans2 = read_int()

        for row in range(1,5):
            list1 = read_ls()
            if ans2 == row:
                set2 = set(list1)
        
        setout = set1 & set2

        if len(setout) == 1:
            msg = "{0}".format( setout.pop() )
        elif len(setout) == 0:
            msg = "Volunteer cheated!"
        else:
            msg = "Bad magician!"

        print("Case #{0:d}: {1:s}".format(case+1, msg))
        
 
if __name__ == "__main__":
    #profile.run('main()')
    sys.exit(main())
