
f = open('a.txt', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	x, =[int(x) for x in f.readline().split()]
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	inputsize = [[] for i in range (0,x)];
	inputstr = ['']*x;
	cont = 1;
	for k in range (0,x):
		y, = f.readline().split()
		##print(x);
		print(len(y));
		a = '';
		for i in range (0, len(y)):
			if (a == y[i]):
				inputsize[k][-1] = inputsize[k][-1] +1;
			else:
				a = y[i];
				inputsize[k].append(1);
				inputstr[k]+=y[i];
		print(inputstr[k])
		if (inputstr[k] != inputstr[0]):
			f0.write('Fegla Won'+'\n');
			cont = 0;
			continue;
			
	if (cont):
		ans = 0;
		for i in range (0, len(inputsize[0])):
			a = []; 
			for j in range (0, x):
				a.append(inputsize[j][i]);
			a.sort();
			med = a[int(len(a)/2)];
			for j in range (0,x):
				ans = ans + abs(inputsize[j][i]-med);

		f0.write(str(ans)+'\n');	
			
	
			
				
				
