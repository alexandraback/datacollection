import sys
import numpy as np

def findMax(nums):
    first = 0
    second = None
    for i in xrange(len(nums)):
        if nums[i] >= nums[first]:
            second = first
            first = i
        elif second is not None and nums[i] >= nums[second]:
            second = i
        
    if second is None:
        return first, second
    if nums[first] == nums[second]:
        return first, second
    if nums[first] > nums[second] + 1:
        return first, first
    return first, None
T = int(sys.stdin.readline())
for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    N = int(sys.stdin.readline())
    nums = map(int, sys.stdin.readline().split())
    nums = np.array(nums)
    #print nums
    while np.any(nums > 1): 
        a, b = findMax(nums)
        nums[a] -= 1
        if b is not None:
            nums[b] -= 1
        a = chr(65 + a)
        if b is None:
            b = ''
        else:
            b = chr(65 + b)
        sys.stdout.write('%s%s ' % (a, b))
        #print nums
    count = np.sum(nums)
    remaining = np.arange(len(nums))[nums == 1]
    #print remaining
    remaining = map(lambda x: chr(x+65), remaining)
    for i in remaining[:-2]:
        sys.stdout.write(i + ' ')
    sys.stdout.write('%s%s ' % (remaining[-1], remaining[-2]))
    sys.stdout.write('\n')

