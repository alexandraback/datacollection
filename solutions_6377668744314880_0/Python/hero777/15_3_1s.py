f = open('a.txt','r')
f0 = open('output.txt','w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	x, = [int(x) for x in f.readline().split()]
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	f0.write('\n')
	x1 = [1]*x
	y1 = [1]*x
	for index2 in range (0,x):
		x1[index2], y1[index2], = [int(q) for q in f.readline().split()]
	for index2 in range (0,x):
		counter = x-2
		for index3 in range (0, x):
			counter1 = 0
			counter2 = 0
			if index3 == index2:
				continue
			for index4 in range (0, x):
				if (index4 == index3 or index4 == index2):
					continue
				z = long(y1[index3]-y1[index2])*long(x1[index4] - x1[index3]) - long(x1[index3] - x1[index2])*long(y1[index4] 						- y1[index3])
				print(z)
				if z < 0:
					counter1 = counter1 +1
				if z>0:
					counter2 = counter2 +1
				we = min(counter1,counter2)
			counter = min(counter, we)
		ans = max(counter,0)
		f0.write(str(ans))
		f0.write('\n')
			
				


