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
	
def count_steps(s, t):
	chars_s = list_chars(s)
	chars_t = list_chars(t)
	l = len(chars_s)
	if len(chars_t) <> l:
		return (False, 0)
	else:
		res = 0
		for i in xrange(0, l):
			if (chars_s[i][0] == chars_t[i][0]):
				res += abs(chars_s[i][1] - chars_t[i][1] )
			else:
				return (False, 0)
		return (True, res)
		
inputfile = open("in.txt", "r")
outputfile = open("out.txt", "w")
t = int(inputfile.readline())
for k in xrange(0, t):
	n = int(inputfile.readline())
	s = inputfile.readline()
	t = inputfile.readline()
	 
	is_possible, steps =  count_steps(s, t) #= res[0], res[1]
	if (is_possible):
		outputfile.write("Case #" + str(k + 1) + ": " + str(steps) + "\n")
	else:
		outputfile.write("Case #" + str(k + 1) + ": Fegla Won\n")
inputfile.close()
outputfile.close()
	
	
	
	
