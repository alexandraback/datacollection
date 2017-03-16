

f = open('A-small.in')
T = int(f.readline())
for t in range(1, T+1):
	an1 = int(f.readline())
	cands = []
	for i in range(1,5):
		row = f.readline()
		if i == an1:
			cands = map(int, row.split())	

	an2 = int(f.readline())
	cands2 = []
	for i in range(1,5):
		row = f.readline()
		if i == an2:
			cands2 = map(int, row.split())	

	num_sims = 0
	answer = 0
	for i in cands:
		if i in cands2:
			answer = i
			num_sims+=1

	if num_sims == 1:
		print 'Case #%d: %d' % (t, answer)
	elif num_sims == 0:
		print 'Case #%d: Volunteer cheated!' % t
	else:
		print 'Case #%d: Bad magician!' % t
