import sys

def deldup(x):
    r = x[0]
    for c in x:
	if c != r[-1]:
	    r += c
    return r

def counts(x):
    r = []
    oldc = x[0]
    n = 0
    for c in x:
	if c == oldc:
	    n += 1
	else:
	    r.append(n)
	    oldc = c
	    n = 1
    r.append(n)
    return r

def transpose(t):
    r = []
    for i in range(len(t[0])):
	row = []
	for j in range(len(t)):
	    row.append(t[j][i])
	r.append(row)
    return r

def median(x):
    y = sorted(x)
    return y[len(y)/2]

def solve(s):
    t = map(deldup, s)
    for x in t:
	if x != t[0]:
	    return "Fegla Won"
    t = map(counts, s)
    t = transpose(t)
    n = 0
    for x in t:
	m = median(x)
	#print x, 'median', m
	for k in x:
	    n += abs(m - k)
    return n



data = sys.stdin.readlines()
n = int(data[0])
#print n
k = 1
for i in range(n):
    n = int(data[k])
    s = [x.strip() for x in data[k+1:k+n+1]]
    k += n+1
    print "Case #%d:" % (i+1), solve(s)

