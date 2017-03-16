#coding:utf8
import sys
result = {
	"fi": "A-small-attempt0.in",
	#"fi":"a.in",
	"fo": "a.out",
	"ct": ""
}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s

def getID(x):
	r = [x[0]]
	last = 0
	c = []
	for i in range(1,len(x)):
		if x[i] != x[i-1]:
			r.append(x[i])
			c.append(i-last)
			last = i
	c.append(len(x)-last)
	return (''.join(r),c)

def getMM(x):
	a = sorted(x)[len(x)/2]
	return sum(map(lambda s:abs(s-a),x))

def getMin(x):
	r = 0
	for i in range(len(x[0])):
		gg = [j[i] for j in x]
		r += getMM(gg)
	return r

def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		res = True
		nn = int(lines.pop())
		ss = [lines.pop() for j in range(nn)]
		yy = [getID(x) for x in ss]
		for j in yy:
			if j[0] != yy[0][0]:
				res = False
				break
		if res:
			out = getMin([j[1] for j in yy])

		myprint("Case #%d: " % i)
		if res:
			myprint(out)
		else:
			myprint("Fegla Won")
		myprint('\n')
	with open(result['fo'], 'w') as f:
		f.write(result['ct'])


if __name__ == '__main__':
	print getID('c1')
	print getMM([1,9,3])
	main()
