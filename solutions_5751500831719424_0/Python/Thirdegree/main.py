import itertools


#this works. if nub list1 != nub list2, the game is impossible.
def nub(list_in):
	copy_list = []
	for i in xrange(len(list_in)):
		try:
			if list_in[i]!= list_in[i+1]:
				copy_list.append(list_in[i])
		except IndexError:
			copy_list.append(list_in[i])
	return copy_list

def group(list_in):
	return [''.join(list(g)) for k,g in itertools.groupby(list_in)]

def find_change_number(string_list):
	temp2 = 0
	for i in xrange(len(string_list)):
		string_list[i] = group(string_list[i])
	string_list = map(list, zip(*string_list))
	for i in xrange(len(string_list)):
		median = find_median(string_list[i])
		for j in xrange(len(string_list[i])):
			temp2+= abs(len(string_list[i][j])-median)
	return temp2


def find_median(string_list):
	temp1 = sorted(string_list, key=len)
	return len(temp1[len(temp1)/2])

output = open("output",'w')

with open("A-small-attempt0.in") as a:
	n = int(a.readline())
	for i in xrange(n):
		c = int(a.readline())
		temp = [a.readline().strip() for j in xrange(c)]
		nubd = all([nub(temp[j])==nub(temp[0]) for j in xrange(len(temp))])
		change_needed = find_change_number(temp)
		if nubd:
			output.write("Case #%d: %d\n"%(i+1, change_needed))
		else:
			output.write("case #%d: %s\n"%(i+1, "Fegla Won"))
