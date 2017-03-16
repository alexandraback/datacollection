import sys
sys.stdin = open('input.txt')
sys.stdout = open('output123.txt', 'w')

def pref(l):
	l = [x for x in l if x[0] != 0]
	l.sort(key=lambda x: -x[0])
	return l


def check(l):
	l = pref(l)
	sm = 0
	for x in l:
		sm += x[0]
	for x in l:
		if x[0] > sm / 2:
			print('FUUUUUUUUUUUCK', l)


def solve(l):
	l = [[l[i], chr(ord('A') + i)] for i in range(len(l))]
	l = pref(l)
	dels = []
	while l:
		if len(l) == 1:
			l[0][0] -= 1
			dels.append(l[0][1])		
		elif len(l) == 2 and [l[0][0], l[1][0]] == [1, 1]:
			dels.append(l[0][1] + l[1][1])
			l[0][0] -= 1
			l[1][0] -= 1
		elif l[0][0] == 1:
			l[0][0] -= 1
			dels.append(l[0][1])
		elif l[0][0] == l[1][0]:
			dels.append(l[0][1] + l[1][1])
			l[0][0] -= 1
			l[1][0] -= 1
		else:
			dels.append(l[0][1])
			l[0][0] -= 1

		l = pref(l)
		check(l)
	return dels





cnt_cases = int(input())
for i in range(cnt_cases):
	n = int(input())
	l = list(map(int, input().split()))
	print('Case #%d: ' % (i + 1), end='')
	print(' '.join(solve(l)))