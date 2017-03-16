def parse_string():
	st = raw_input()
	lastc = None
	count = 0
	toReturn = []
	for c in st:
		if lastc is None or lastc == c:
			pass
		else:
			toReturn.append((lastc, count))
			count = 0
		lastc = c
		count += 1
	toReturn.append((lastc, count))
	return toReturn 

def subsolve(letters):
	letter = letters[0][0]
	counts = []
	for record in letters:
		if record[0] != letter:
			return None
		else:
			counts.append(record[1])
	counts.sort()
	aftersum = sum(counts[1:])
	beforesum = 0	
	beststeps = None
	#print "Array : ", counts
	for i in range(len(counts)):
		steps = counts[i] * i - beforesum + aftersum - counts[i] * (len(counts) - i - 1)
		#print beforesum, aftersum, steps
		if beststeps is None:
			beststeps = steps
		else:
			beststeps = min(beststeps, steps)
		beforesum += counts[i]
		if i < len(counts) - 1:
			aftersum -= counts[i+1]
	return beststeps
		
			

t = int(raw_input())
for case in xrange(1, t+1):
	doable = True
	n = int(raw_input())
	total_result = 0
	parsed = []
	for st in xrange(n):
		parsed.append(parse_string())
	lengths = map(lambda x : len(x), parsed)
	if min(lengths) != max(lengths):
		doable = False
	else:
		parsed = zip(*parsed)
		for x in parsed:
			res = subsolve(x)
			if res is None:
				doable = False
				break
			else:
				total_result += res
	print "Case #%d: %s" % (case, "Fegla Won" if not doable else str(total_result))
