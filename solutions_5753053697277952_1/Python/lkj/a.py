
def solve(p):
	s = ''
	n = len(p)
	while True:
		m = max(p)
		mi = p.index(m)
		sump = sum(p)
		if sump == 0:
			break
		if sump % 2:
			s += chr(ord('A')+mi) + ' '
			p[mi] -= 1
			assert(max(p) <= (sump-1)//2)
		else:
			sm = 0
			smi = -1
			for i in range(n):
				if p[i] > sm and i != mi:
					smi = i
					sm = p[i]
			assert(smi >= 0)
			s += chr(ord('A')+mi)+chr(ord('A')+smi)+' '
			p[mi] -= 1
			p[smi] -= 1
			assert(max(p) <= (sump-2)//2)
	return s[:-1]

tc = int(input())
for t in range(1,tc+1):
	n = int(input())
	p = [int(x) for x in input().split()]
	print('Case #{}: {}'.format(t,solve(p)))
