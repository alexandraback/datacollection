import math
import sys
import collections

def print_result (case_num,result):
    print('Case #{}: {}'.format(case_num,result))

T = int(input())
for case_num in range(1,T+1):
    abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    N = int(input())
    nums = list(map(int,input().split()))
    r = []
    while sum(nums) > 0:
        assert max(nums) <= sum(nums)/2
        remaining = [i for i,a in enumerate(nums) if a > 0]
        if len(remaining) == 2:
            r += [abc[remaining[0]] + abc[remaining[1]]]
            for i in remaining:
                nums[i] -= 1
        elif len(remaining) == 1:
            c = min(nums[remaining[0]],2)
            r += [c*abc[remaining[0]]]
            nums[remaining[0]] -= c
        else:
            mx = max(nums)
            cur = [i for i,a in enumerate(nums) if a == mx]
            if len(cur) == 1:
                r += [abc[cur[0]]*2]
                nums[cur[0]] -= 2
            elif len(cur) == 2:
                r += [abc[cur[0]]+abc[cur[1]]]
                for i in cur:
                    nums[i] -= 1
            else:
                r += [abc[cur[0]]]
                nums[cur[0]] -= 1
    assert len([1 for a in nums if a != 0]) == 0
    print_result(case_num,' '.join(r))
        

