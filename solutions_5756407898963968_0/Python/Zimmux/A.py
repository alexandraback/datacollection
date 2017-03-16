import fileinput
stdin = fileinput.input()

def solveCase():
	ans1  = int(stdin.next())
	rows1 = [
		map(int,stdin.next().split()),
		map(int,stdin.next().split()),
		map(int,stdin.next().split()),
		map(int,stdin.next().split())
	]
	ans2  = int(stdin.next())
	rows2 = [
		map(int,stdin.next().split()),
		map(int,stdin.next().split()),
		map(int,stdin.next().split()),
		map(int,stdin.next().split())
	]
	
	cards = set(rows1[ans1-1]) & set(rows2[ans2-1])
	if len(cards)==0:
		return "Volunteer cheated!"
	elif len(cards)==1:
		return list(cards)[0]
	else:
		return "Bad magician!"

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())
