def toSingle(s):
    single = ''
    last_c = ''
    charCount = []
    last_n = 0
    for i in range(len(s)):
	if last_c != s[i]:
	    single += last_c
	    if i != 0:
		charCount.append(last_n)
	    last_c = s[i]
	    last_n = 1
	else:
	    last_n += 1
    single += last_c
    charCount.append(last_n)
    #print '///', s, single, charCount
    return single, charCount

t = int(raw_input())
for case in range(t):
    n = int(raw_input())
    allStr = []
    for i in range(n):
	s = raw_input()
	allStr.append(s)
    valid = True
    allCount = []

    base, baseCount = toSingle(allStr[0])
    allCount.append(baseCount[:])
    for s in allStr[1:]:
	if valid:
	    single, charCount = toSingle(s)
	    allCount.append(charCount[:])
	    if single != base:
		valid = False

    if not valid:
	print 'Case #%d: Fegla Won' % (case+1)
	continue
    else:
	step = 0
	l = len(base)
	for i in range(l):
	    lst = [allCount[x][i] for x in range(n)]
	    st = list(set(lst))
	    least = sum(lst)
	    for j in st:
		c = sum([abs(x-j) for x in lst])
		if c < least:
		    least = c
	    step += least
	print 'Case #%d: %d' % (case+1, step)

