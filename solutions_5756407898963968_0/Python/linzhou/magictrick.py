from sets import Set

fp = open('./A-small-attempt1.in','r')
linearray = []
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

op = open('./first.out','w')
T = int(linearray[0])
for i in range(0,T):
	r1 = int(linearray[i*10+1])
	r2 = int(linearray[i*10+6])
	row1 = linearray[i*10+1+r1]
	row2 = linearray[i*10+6+r2]

	set1 = Set([])
	s1 = row1.split()
	for s in s1:
		set1.add(int(s))

	set2 = Set([])
	s2 = row2.split()
	for s in s2:
		set2.add(int(s))
	ints = set1.intersection(set2)

	if (len(ints) == 0):
		op.write("Case #%s: Volunteer cheated!\n" % (i+1))
	elif (len(ints) == 1):
		op.write("Case #%s: %s\n" % (i+1,ints.pop()))
	else:
		op.write("Case #%s: Bad magician!\n" % (i+1))
op.close()
