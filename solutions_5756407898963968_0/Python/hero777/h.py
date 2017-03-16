f = open('A-small-attempt0.in', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()];
for j in range(0, a0[0]):
	a = [int(x) for x in f.readline().split()];
	for i in range(1,a[0]):
		f.readline()
	b = [int(x) for x in f.readline().split()];
	print b
	for i in range(1,5-a[0]):
		f.readline()
	c = [int(x) for x in f.readline().split()];
	for i in range(1,c[0]):
		f.readline()
	d = [int(x) for x in f.readline().split()];
	print d
	for i in range(1,5-c[0]):
		f.readline()
	e = list(set(b).intersection(d))
	f0.write('Case #')
	f0.write(str(j+1))
	f0.write(': ')
	if len(e) == 1:
		f0.write(str(e[0]))
		f0.write('\n');
	elif len(e) == 0:
		f0.write('Volunteer cheated!\n');
	else:
		f0.write('Bad magician!\n');
f0.close
f.close
	

