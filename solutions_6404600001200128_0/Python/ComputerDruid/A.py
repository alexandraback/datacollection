#!/usr/bin/env python3

T = int(input())
for t in range(T):
    N = int(input())
    nums = [ int(x) for x in input().split(" ") ]
    rate = 0
    sum_1 = 0
    sum_2 = 0
    last = nums[0]
    for val in nums:
        if last - val > rate:
            rate = last - val
        if last - val > 0:
            sum_1 += last - val
        last = val
    for val in nums[:-1]:
        if val > rate:
            sum_2 += rate
        else:
            sum_2 += val
    print("Case #" + str(t+1) + ": " + str(sum_1) + " " + str(sum_2))
