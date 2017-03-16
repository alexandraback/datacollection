T = int(raw_input())

def process(word):
	out = []
	current = -1
	for i in word:
		if i != current:
			out.append([i, 1])
			current = i
		else:
			out[-1][1] += 1
	return out

def sht(wordlist):
	return "".join([i[0] for i in wordlist])

def seq(wordlist):
	return [i[1] for i in wordlist]

for i in xrange(T):
	ans = 0
	N = int(raw_input())
	words = []
	for j in xrange(N):
		read = str(raw_input())
		words.append(read)
	words2 = [process(word) for word in words]
	words3 = [sht(word) for word in words2]
	words3.sort()


	chrlen = len(words3[0])
	if words3[0] != words3[-1]:
		print "Case #" + str(i+1) + ": " + "Fegla Won"
		continue


	words4 = [seq(f) for f in words2]


	for k in xrange(chrlen):
		wlist = [h[k] for h in words4]
		wlist.sort()
		loc = wlist[len(wlist)/2]
		ans += sum([abs(int(xx)-loc) for xx in wlist])


	print "Case #" + str(i+1) + ": " + str(ans)
