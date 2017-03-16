f = open('a.txt','r')
f0 = open('output.txt','w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	x = [int(x) for x in f.readline().split()]
	y = [int(q) for q in f.readline().split()]
	z = 0
	w = 0
	r = 0
	for index2 in range(0,x[0]-1):
		z = z+ long (max(0, y[index2]-y[index2+1]))
		w = max(w, long(y[index2]-y[index2+1]))
	for index3 in range(0,x[0]-1):
		if y[index3] < w:
			r = r + w-long(y[index3])
	p = long((x[0]-1))*long(w) - long(r)
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	f0.write(str(z))
	f0.write(' ')
	f0.write(str(p))
	f0.write('\n')
		



