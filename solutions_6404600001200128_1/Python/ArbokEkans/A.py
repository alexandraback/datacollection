T = int(input())

def case(t):
    n = int(input())
    nums = [int(x) for x in input().split()]

    diffs = list(zip(nums, nums[1:]))
    
    max_diff = max(a-b for (a, b) in diffs)
    
    eat = 0
    eat_other = 0
    rate = max_diff
    for (a, b) in diffs:

        if a > b: eat_other += a-b

        if a <= max_diff:
            eat += a
        else:
            eat += max_diff
    print("Case #{}: {} {}".format(t, eat_other, eat))

for i in range(1, T+1):
    case(i)
