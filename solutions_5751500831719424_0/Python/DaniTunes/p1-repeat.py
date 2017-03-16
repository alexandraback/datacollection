import sys

def deldup(x):
    r = x[0]
    for c in x:
	if c != r[-1]:
	    r += c
    return r

def solve2(a, b):
    n = 0
    i = 0
    j = 0
    while i < len(a) and j < len(b):
	if a[i] == b[j]:
	    i += 1
	    j += 1
	else:
	    n += 1
	    if a[i] == a[i-1]:
		i += 1
	    else:
		j += 1
    return n + len(a) - i + len(b) - j

def solve(s):
    t = map(deldup, s)
    for x in t:
	if x != t[0]:
	    return "Fegla Won"
    if len(s) == 2:
	return solve2(s[0], s[1])
    return 0



data = sys.stdin.readlines()
n = int(data[0])
#print n
k = 1
for i in range(n):
    n = int(data[k])
    s = [x.strip() for x in data[k+1:k+n+1]]
    k += n+1
    print "Case #%d:" % (i+1), solve(s)

