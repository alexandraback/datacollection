#!/usr/bin/python

import sys;
import os.path; 
THIS_DIR = os.path.dirname(sys.argv[0]);
sys.path.append(THIS_DIR + '/..')
from util import *;

def main():
    nt = readi();
    for t in range(1, nt+1):
        r1 = readi();
        for i in range(1, 5):
            nums = readia();
            if i == r1:
                nums1 = set(nums);
        r2 = readi();
        for i in range(1, 5):
            nums = readia();
            if i == r2:
                nums2 = set(nums);
        
        foundNum = False;
        badMagic = False;
        theN = -1;

        for n in nums1:
            if n in nums2:
                if not foundNum:
                    theN = n;
                    foundNum = True;
                else:
                    badMagic = True;
                    break;

        if badMagic:
            res = "Bad magician!";
        elif foundNum:
            res = str(theN);
        else:
            res = "Volunteer cheated!";
        
        print "Case #%d: %s" % (t, res);
    

main();
