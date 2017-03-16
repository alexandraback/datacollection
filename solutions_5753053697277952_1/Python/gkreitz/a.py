import sys

def forbidden(sens):
	m = max(sens)
	n = sum(sens)
	if 2*m > n:
		return True
	return False

def solve(i):
	sys.stdin.readline()
	sens = map(int, sys.stdin.readline().split())
	while max(sens) > 0:
		(_, i) = max(zip(sens, range(len(sens))))
		sens[i] -= 1
		if not forbidden(sens):
			sys.stdout.write(" %s" % chr(ord('A') + i))
		else:
			(_, i2) = max(zip(sens, range(len(sens))))
			sens[i2] -= 1
			assert not forbidden(sens)
			sys.stdout.write(" %s%s" % (chr(ord('A') + i), chr(ord('A') + i2)))
	sys.stdout.write("\n")


if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
