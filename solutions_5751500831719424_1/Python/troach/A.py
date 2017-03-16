from __future__ import print_function
import sys
import math

def main():
	t = int(sys.stdin.readline())
	for case in range(1, t+1):
		sys.stderr.write('processing case %d\n' % case)
		process_case(case)
	sys.stderr.write('Finished!\n')

def process_case(case):
	n, = map(int, sys.stdin.readline().split())
	words = [get_char_lengths(sys.stdin.readline().strip()) for i in range(n)]
	print('', words, file=sys.stderr)
	for word in words:
		if len(word) != len(words[-1]):
			sys.stdout.write('Case #%d: %s\n' % (case, 'Fegla Won'))
			return

	moves = 0
	for i in range(len(words[0])):
		amts = []
		for word in words:
			if word[i][0] != words[0][i][0]:
				sys.stdout.write('Case #%d: %s\n' % (case, 'Fegla Won'))
				return
			amts.append(word[i][1])
		amts.sort()
		moves += get_smallest_moves(amts)
		sys.stderr.write('moves after %d index: %d\n' % (i, moves))

	sys.stdout.write('Case #%d: %d\n' % (case, moves))

def get_char_lengths(word):
	char_lengths = []
	c = ''
	for ch in word:
		if ch == c:
			char_lengths[-1][1] += 1
		else:
			c = ch
			char_lengths.append([ch, 1])
	return char_lengths

def get_smallest_moves(amts):
	mid = int(len(amts) / 2)
	d = get_distance_sum(amts, mid)
	if mid - 1 >= 0:
		d_left = get_distance_sum(amts, mid - 1)
	else:
		d_left = -1

	if mid + 1 < len(amts):
		d_right = get_distance_sum(amts, mid + 1)
	else:
		d_right = -1

	if d_left > d and d_right > d:
		return d
	elif d_left <= d:
		while mid > 1:
			mid = mid - 1
			d = d_left
			d_left = get_distance_sum(amts, mid - 1)
			if d < d_left:
				return d
		return min(d, d_left)
	else:
		while mid < len(amts) - 2:
			mid = mid + 1
			d = d_right
			d_right = get_distance_sum(amts, mid + 1)
			if d < d_right:
				return d
		return min(d, d_right)

def get_distance_sum(amts, index):
	# print('', amts, file=sys.stderr)
	# sys.stderr.write('index: %d, length: %d\n' % (index, len(amts)))
	s = 0
	for i, amt in enumerate(amts):
		if i == index:
			continue
		s += math.fabs(amts[index] - amt)
	return s

if __name__ == '__main__':
	main()
