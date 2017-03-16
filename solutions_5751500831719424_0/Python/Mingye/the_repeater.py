
f = open('/Users/Wanli/Downloads/A-small-attempt1.in.txt')
# f = open('rinput.txt')
ncases = int(f.readline())

for case in range(ncases):
	nstrings = int(f.readline())
	strings = []
	for n in range(nstrings):
		string = f.readline().rstrip()
		strings.append(string)

	characters = []
	for string in strings:
		chars = [1]
		for i in range(1, len(string)):
			if string[i] == string[i-1]:
				chars[-1] += 1
			else:
				chars.append(1)
		characters.append(chars)

	if len(set([len(cs) for cs in characters])) > 1:
		print 'Case #%d: Fegla Won' % (case+1)
		continue

	total = 0
	for i in range(len(characters[0])):
		counts = sorted([cs[i] for cs in characters])
		median = counts[nstrings/2-1]
		for count in counts:
			total += abs(count - median)

	print 'Case #%d: %d' % (case+1, total)
