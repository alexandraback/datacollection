import sys

tc = int(sys.stdin.readline())

def readcase():
	r = int(sys.stdin.readline())
	result = ''
	for i in range(4):
		t = sys.stdin.readline()
		if i + 1 == r:
			result = t
	return result.strip().split()

for t in range(tc):
	a = readcase()
	b = readcase()
	ans = [num for num in range(1,17) if str(num) in a and str(num) in b]
	sys.stdout.write('Case #' + str(t+1) + ': ')
	if len(ans) == 1:
		print ans[0] 
	elif len(ans) == 0:
		print 'Volunteer cheated!'
	else:
		print 'Bad magician!'
	