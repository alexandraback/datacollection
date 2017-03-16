

nb_case = raw_input()

jeux = []

for i in xrange(int(nb_case)):
	for k in xrange(2):
		tmp = raw_input()
		for j in xrange(4):
			s = raw_input()
			if int(tmp) == j+1:
				jeux.append(map(int, s.split()))
	
for i in xrange(int(nb_case)):
	tmp = set(jeux[2*i]) & set(jeux[2*i+1])
	if len(tmp)==0:
		print("Case #%d: Volunteer cheated!" % (i+1))
	elif len(tmp)==1:
		print("Case #%d: %d" % (i+1,tmp.pop()))
	else:
		print("Case #%d: Bad magician!" % (i+1))

		 
