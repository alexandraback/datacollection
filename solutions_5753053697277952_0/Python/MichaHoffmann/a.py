from string import ascii_uppercase
from collections import OrderedDict

od = OrderedDict((idx-1, ch) for idx, ch in enumerate(ascii_uppercase, 1))

def solve(l,n):
	solution = []
	while max(l) != 0:
		if max(l) > 1:
			a = l[l.index(max(l))]
			inda = l.index(a)
			l[inda] = a - 1
			b = l[l.index(max(l))]
			indb = l.index(b)
			l[indb] = b - 1
			evac = "".join([od[inda], od[indb]])
			solution.append(evac)
		else:
			if max(l) == 1:
				if l.count(1)%2 == 0:
					a = l[l.index(max(l))]
					inda = l.index(a)
					l[inda] = a - 1
					b = l[l.index(max(l))]
					indb = l.index(b)
					l[indb] = b - 1
					evac = "".join([od[inda], od[indb]])
					solution.append(evac)
				else:
					a = l[l.index(max(l))]
					inda = l.index(a)
					l[inda] = a - 1					
					solution.append(str(od[inda]))
	return " ".join(solution)



t = int(raw_input())
for i in xrange(1, t + 1):
	nump = int(raw_input())
	listrep =  [int(t) for t in raw_input().split(" ")]
	print "Case #{}: {}".format(i, solve(listrep,nump))
