file1 = open("A-large.in", "r")
my_file = open("output.txt", "r+")


t = int(file1.readline())
i = 0
while (i < t):
	z = file1.readline()
	a = 0
	b = 0
	rate = 0
	inputs1 = (file1.readline().split())
	inputs = [int(j) for j in inputs1]
	for x in range(len(inputs)-1):
		if inputs[x] > inputs[x+1]:
			a += (inputs[x] - inputs[x+1])
	for x in range(len(inputs)-1):
		if inputs[x] > inputs[x+1]:
			if rate < (inputs[x] - inputs[x+1]):
				rate = (inputs[x] - inputs[x+1])
	for x in range(len(inputs)-1):
		if inputs[x] >= rate:
			b += rate
		else:
			b += inputs[x]
	
	i+=1		
	my_file.write(("Case #%d: %d %d\n" % (i,a,b)))
my_file.close()
file1.close()
