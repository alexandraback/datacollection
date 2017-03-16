letter_str = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def get_max_and_index(nums):
	max_value = max(nums)
	max_index = nums.index(max_value)
	return max_value, max_index

def solve(nums):
	if sum(nums) == 0:
		return ''
	max_value, max_index = get_max_and_index(nums)
	nums[max_index] -= 1
	next = letter_str[max_index]
	if (max(nums) * 2 > sum(nums)):
		max_value, max_index = get_max_and_index(nums)
		nums[max_index] -= 1
		next = next + letter_str[max_index]
	return next + ' ' + solve(nums)


T = input()
for i in range(T):
	N = input()
	nums = [int(el) for el in raw_input().split()]
	print 'Case #' + str(i + 1) + ': ' + solve(nums)[:-1]
