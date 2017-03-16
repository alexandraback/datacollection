import sys

T = int(sys.stdin.readline())


def num_served(time, a):
	total = 0
	for i in a:
		total += (time/i) + 1
	return total

def earliest_free(time, a, index):
	for i in range(0,len(a)):
		if (time+1) % a[i] == 0:
			if index == 0: 
				return i
			index -= 1

def finish_time(a, k):
	hi = 1
	while num_served(hi, a) < k:
		hi *= 2
	lo = 1
	while lo != hi:
		mid = (lo+hi + 1)/2
		if num_served(mid, a) >= k:
			hi = mid - 1
		else:
			lo = mid
	return lo

def ans(a, k):
	if k <= len(a):
		return k
	finish = finish_time(a, k)
	#print "Finish time: %d" % finish
	#print "Num completed: %d" % num_served(finish, a)
	return earliest_free(finish, a, k - num_served(finish, a) - 1) + 1


def solve():
	s = map(int, sys.stdin.readline().strip().split(' '))
	#print "s = ", s
	a = map(int, sys.stdin.readline().strip().split(' '))
	#print "a = ", a
	return ans(a, s[1])


for i in range(1, T+1):
	print "Case #%d: %d" % (i, solve())
