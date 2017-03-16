#!/usr/bin/env python
import sys

case_num = 1
def printres(result):
    global case_num
    print "Case #%s: %s" % (case_num, result)
    case_num += 1

def readline(): 
    return sys.stdin.readline().rstrip('\n')
def splitline(f):
    return map(f, readline().split())

def calc1(nums):
    eaten = 0
    last = nums[0]
    for n in nums[1:]:
        if n < last:
            eaten += last - n
        last = n
    return eaten

def calc2(nums):
    slope = 0
    last = nums[0]
    for n in nums[1:]:
        slope = max(slope, last-n) 
        last = n

    eaten = 0
    for n in nums[:-1]:
        eaten += min(slope, n)

    return eaten

def solve():
    readline()
    nums = splitline(int)
    c1 = calc1(nums)
    c2 = calc2(nums)
    printres("%d %d" % (c1, c2))

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

