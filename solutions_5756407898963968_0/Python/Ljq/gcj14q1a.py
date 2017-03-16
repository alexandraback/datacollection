
import sys
sys.stdin = open('A-small-attempt0.in')
sys.stdout = open('A-small-attempt0.out', 'w')

if __name__ == '__main__':
	t = int(input())
	for tt in range(1, t + 1):
		r1 = int(input()) - 1
		lst1 = {x for x in [input().split() for i in range(4)][r1]}
		r2 = int(input()) - 1
		lst2 = {x for x in [input().split() for i in range(4)][r2]}
		lst = lst1.intersection(lst2)
		if len(lst) == 1: ret = lst.pop()
		elif len(lst) == 0: ret = 'Volunteer cheated!'
		else: ret = 'Bad magician!'
		print('Case #' + str(tt) + ':', ret)