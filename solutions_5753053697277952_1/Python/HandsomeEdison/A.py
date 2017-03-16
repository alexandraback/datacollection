# -*- coding: utf-8 -*-
# @Author: zeyuan.shang
# @Date:   2016-05-08 17:01:08
# @Last Modified by:   zeyuan.shang
# @Last Modified time: 2016-05-08 17:17:37
if __name__ == "__main__":
	T = input()
	for i in xrange(1, T + 1):
		n = input()
		p = map(int, raw_input().split())
		s = []
		for j in xrange(len(p)):
			s.append([p[j], j])
		ans = []
		m = sum(p)
		while m > 0:
			s = sorted(s, reverse = True)
			a, b = s[0], s[1]
			if a[0] == b[0] and m != 3:
				ans.append(chr(ord('A') + a[1]) + chr(ord('A') + b[1]))
				a[0] -= 1
				b[0] -= 1
				m -= 2
			else:
				ans.append(chr(ord('A') + a[1]))
				a[0] -= 1
				m -= 1
			s = [a, b] + s[2:]
		print 'Case #{}: {}'.format(i, ' '.join(ans))
