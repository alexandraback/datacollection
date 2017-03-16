import sys

filename = sys.argv[1]
f = open(filename, 'r')

numCases = int(f.readline())

for t in range(numCases):
	firstAns = int(f.readline())
	selected1 = []
	for r in range(4):
		if r+1 == firstAns:
			selected1 = f.readline().strip()
		else:
			f.readline()
	secondAns = int(f.readline())
	selected2 = []
	for r in range(4):
		if r+1 == secondAns:
			selected2 = f.readline().strip()
		else:
			f.readline()

	selected1 = selected1.split(' ')
	selected2 = selected2.split(' ')

	possible = [num for num in selected1 if num in selected2]

	printStr = 'Case #'+str(t+1)+': '
	if len(possible) > 1:
		print printStr+'Bad magician!'
	elif len(possible) < 1:
		print printStr+'Volunteer cheated!'
	else:
		print printStr+str(possible[0])
	




