#!/usr/bin/env python

ALPHA = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N = int(f.readline().rstrip('\n'))
		Ps = map(int, f.readline().rstrip('\n').split())
		Pss = {}
		for i in xrange(N):
			Pss[ALPHA[i]] = Ps[i]

		Se = list(reversed(sorted(Pss.keys(), key=lambda k:Pss[k])))
		# print Se
		print 'Case #{}:'.format(T),

		while Se:
			if Pss[Se[0]] != Pss[Se[1]]:
				print Se[0]+Se[-1],
				Pss[Se[0]] -= 1
				Pss[Se[-1]] -= 1
				if Pss[Se[-1]] == 0:
					Se = Se[:-1]
			else:
				if len(Se) > 2:
					print Se[-1],
					Pss[Se[-1]] -= 1
					if Pss[Se[-1]] == 0:
						Se = Se[:-1]
				else:
					if Pss[Se[0]] == 1:
						print Se[0]+Se[1]
						break
					print Se[0]+Se[1],
					Pss[Se[0]] -= 1
					Pss[Se[1]] -= 1

		# print R, C, W


		# print find_speed(M)
		# res = (R-1)*not_here(C, W)+here(C, W)
		# print 'Case #{}: {}'.format(T, res)

if __name__ == '__main__':
	main()