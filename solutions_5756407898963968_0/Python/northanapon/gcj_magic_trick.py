

f = open("A-small-attempt1.in.txt", 'r')
f2 = open("A-small-attempt1.out.txt", 'w')
num_cases = int(f.readline())

for i in range(num_cases):
	line = f.readline().strip()
	row = int(line)
	row = row -1
	nums = {}
	for j in range(4):
		line = f.readline().strip()
		if j == row:
			nums = set(line.split(' '))
	line = f.readline().strip()
	row = int(line)
	row = row -1
	intersect = []
	for j in range(4):
		line = f.readline().strip()
		if j == row:
			nums_2 = line.split(' ')
			for num in nums_2:
				if num in nums:
					intersect.append(num)
	f2.write("Case #" + str(i+1) +": ")
	if len(intersect) == 1 :
		f2.write(intersect[0]+"\n")
	elif len(intersect) >1 :
		f2.write("Bad magician!\n")
	else:
		f2.write("Volunteer cheated!\n")
	
	