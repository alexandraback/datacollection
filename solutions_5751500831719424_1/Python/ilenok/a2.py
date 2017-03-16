def list_chars(s):
	res = []
	slen = len(s)
	res.append((s[0], 1))
	for i in xrange(1, slen):
		if (s[i] == res[-1][0]):
			res[-1]= (res[-1][0], res[-1][1] + 1)
		else:
			res.append((s[i], 1))
	return res
	
def count_steps(strs, n):
	chars_lists = []
	for s in strs:
		chars_lists.append(list_chars(s))
	l = len(chars_lists[0])
	print l,  chars_lists[0]
	for i in xrange(1, n):
		if len(chars_lists[i]) <> l:
			return (False, 0)
	else:
		
		for j in xrange(0, l):
			for i in xrange(1, n):
				if (chars_lists[i][j][0] <> chars_lists[0][j][0]):
					return (False, 0)
		res = 0
		for j in xrange(0, l):
			nch = []
			for i in xrange(0, n):
				nch.append(chars_lists[i][j][1])
				
			print j, nch
			nch.sort()			
			tmp = nch[(n + 1) / 2 - 1];
			if ( n % 2 == 0):
				tmp += nch[(n + 1) / 2]
				tmp /= 2
			print tmp
			for i in xrange(0, n):	
				res += abs(chars_lists[i][j][1] - tmp)
		return (True, res)
		
inputfile = open("in.txt", "r")
outputfile = open("out.txt", "w")
t = int(inputfile.readline())
for k in xrange(0, t):
	n = int(inputfile.readline())
	strs = []
	for i in xrange(0, n):
		strs.append(inputfile.readline().strip())	 
	is_possible, steps =  count_steps(strs, n) #= res[0], res[1]
	if (is_possible):
		outputfile.write("Case #" + str(k + 1) + ": " + str(steps) + "\n")
	else:
		outputfile.write("Case #" + str(k + 1) + ": Fegla Won\n")
inputfile.close()
outputfile.close()
	
	
	
	
