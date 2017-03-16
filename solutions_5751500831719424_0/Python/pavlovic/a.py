import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",

	n = int(sys.stdin.readline().strip())
	
	ref = ""
	reps = []
	wrong = False
	for j in range(n):
		s = sys.stdin.readline().strip()
		rep = []
		k = 0
		while k < len(s):
			r = 1
			while (k < len(s) - 1) and (s[k] == s[k + 1]):
				r += 1
				s = s[:k + 1] + s[k + 2:]
			rep.append(r)
			k += 1
		
		if j == 0:
			ref = s
		elif ref != s:
			print "Fegla Won"
			wrong = True
			break
			
		reps.append(rep)
			
	if wrong:
		continue
		
	ss = 0
	for j in range(len(reps[0])):
		a = []
		for k in range(len(reps)):
			a.append(reps[k][j])
		a.sort()
		pivot = a[len(a) // 2]
		for k in range(len(a)):
			ss += abs(pivot - reps[k][j])
			
	print ss
	
