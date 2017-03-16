def ae(c):
	cl = c[0]
	eat = 0
	for x in c[1:]:
		if x < cl:
			eat += cl-x
		cl = x
	return eat

def ce(c):
	v = max(0, max(x-y for x,y in zip(c[:-1],c[1:])))
	cl = c[0]
	eat = 0
	for x in c[1:]:
		if cl > 0:
			eat += min(v,cl)
		cl = x
	return eat

t = int(raw_input())
for _ in range(1,t+1):
	n = int(raw_input())
	c = map(int,raw_input().split())
	print 'Case #%d: %d %d' % (_, ae(c), ce(c))