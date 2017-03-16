import re
from math import ceil
def n_ary(f):
    """Given binary function f(x, y), return an n_ary function such
    that f(x, y, z) = f(x, f(y,z)), etc. Also allow f(x) = x."""
    def n_ary_f(x, *args):
        if len(args) == 0:
            return x
        else:
            return f(x, n_ary_f(args[0], *args[1:]))
        # your code here
    return n_ary_f

def trace(f):
	indent = '    '
	trace.level = -1
	def _f(*args):
		trace.level += 1
		txt = '===>%s(%s)' % (f.__name__, map(repr, args))
		print indent*trace.level + txt
		try:
			result = f(*args)
			txt2 = '<===%s(%s) : %s' % (f.__name__, map(repr, args), str(result))
			print indent*trace.level + txt2
		finally:
			trace.level -= 1
		return result
	return _f

def test(f):
	test.count = 0
	def _f(*args):
		test.count += 1
		result = f(*args)
		if test.count <= 10:
			print f.__name__
			print "input: %s" % map(repr, args)
			print "output: %s" % str(result)
		return result
	return _f

def writeFile(n, outputs, path = 'd:\small-practice.out'):
	with open(path, 'wb+') as f:
		for i in range(1, n+1):
			out = outputs[i-1]
			f.write("Case #%s: %s\n" % (i, out))


def process(n, inputs):
	outputs = []
	for i in range(n):
		outputs.append(process_aux(inputs[i]))
	return outputs

def readFile(path = 'd:\small-practice.in'):
		with open(path, 'rb+') as f:
			l1 = f.readline()
			n = int(l1)
			inputs = []

			cnt = 0
			for i in range(n):
				snum = f.readline()
				snum = int(snum)

				slist = []				
				for j in range(snum):
					buf = f.readline()
					buf = buf.rstrip()
					slist.append(buf)

				elem = (snum, slist)
				inputs.append(elem)
		return n, inputs

#input -> String with \n
@test
def process_aux(input):
	output = ""
	snum = input[0]
	slist = input[1]
	possibleNum = possibility(slist)
	if possibleNum == 1:
		lenList = lengthing(slist)
		steps = 0
		for j in range(len(lenList[0])):
			steps += calcSteps([elem[j] for elem in lenList])
		return str(steps)
	else:
		return "Fegla Won"



	return output

def calcSteps(lenList):
	sortedList = sorted(lenList)
	median1 = sortedList[(len(sortedList)/2)-1]
	median2 = sortedList[(len(sortedList)/2)]
	buf1 = 0
	buf2 = 0
	for elem in sortedList:
		buf1 += abs(elem-median1)
		buf2 += abs(elem-median2)
	return min(buf1, buf2)


def lengthing(slist):
	result = []
	for elem in slist:
		length = len(elem)
		count = 1
		rbuf = []
		for i in range(length-1):
			if elem[i] == elem[i+1]:
				count += 1
			else:
				rbuf.append(count)
				count = 1
		rbuf.append(count)
		result.append(rbuf)
	return result


	return result

def possibility(slist):
	s = set()
	for elem in slist:
		s.add(suppress(elem))
	return len(s)

def suppress(charset):
	result = ""
	length = len(charset)
	result += charset[0]
	for i in range(length-1):
		if charset[i] != charset[i+1]:
			result += charset[i+1]
	return result



file1 = "A-small-attempt0"
file2 = "B-large-attempt0"

print "hi"
print lengthing(["aaabbc", "abcccc", "aabbcc"])

n, ins = readFile(file1 + ".in")
print n
#print ins
outs = process(n, ins)
#print outs
writeFile(n, outs, file1 + "output.txt")
print "done!"





