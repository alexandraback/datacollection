#coding:utf8
import sys
result = {
	"fi": "A-small-attempt1.in",
	"fo": "a.out",
	"ct": ""
}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s


def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		r1 = int(lines.pop())
		b1 = [lines.pop(), lines.pop(), lines.pop(), lines.pop()]
		b1 = map(lambda x:map(int,x.split()), b1)
		print b1, r1

		r2 = int(lines.pop())
		b2 = [lines.pop(), lines.pop(), lines.pop(), lines.pop()]
		b2 = map(lambda x:map(int,x.split()), b2)
		print b2, r2
		good = [k for k in b1[r1-1] if k in b2[r2-1]]
		#print good

		myprint("Case #%d: " % i)
		if len(good) == 1:
			myprint(good[0], '\n')
		elif len(good) == 0:
			myprint("Volunteer cheated!",'\n')
		else:
			myprint("Bad magician!",'\n')
	with open(result['fo'], 'w') as f:
		f.write(result['ct'])

if __name__ == '__main__':
	main()