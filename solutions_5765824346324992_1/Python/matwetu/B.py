import sys
import math
import StringIO
import os
import re

target_dir = 'C:\\Users\\lijia_000\\Downloads'
def search_file():
	problem_id = os.path.basename(sys.argv[0]).split('.')[0].lower()
	large_list = filter(lambda x: re.match('^%s.*large.*\.in$' % problem_id, x.lower()) is not None, os.listdir(target_dir))
	if large_list:
		return max(large_list)
	small_list = filter(lambda x: re.match('^%s.*small.*\.in$' % problem_id, x.lower()) is not None, os.listdir(target_dir))
	if small_list:
		return max(small_list)
	sys.stderr.write("No file available\n")

def problem_solver(fileobj_in, fileobj_out):
	n = int(fileobj_in.readline())
	for i in xrange(n):
		result = case_solver(**case_reader(fileobj_in))
		assert(type(result) is str)
		if not result.endswith('\n'): result += '\n'
		fileobj_out.write("Case #%d: %s" % (i+1, result))
def main():
	problem_solver(f_in, f_out)

file_name = None
file_name = search_file()
if file_name:
	f_in = open(os.path.join(target_dir, file_name), 'r')
	f_out = open(os.path.basename(file_name[:-3]) + '.out', 'w')
else:
	f_out = sys.stdout
	f_in = StringIO.StringIO("""
3
2 4
10 5
3 12
7 7 7
3 8
4 2 1
""".lstrip())

def totalout(b,t):
	return sum([(t + i - 1)/i for i in b])

def case_reader(fileobj):
	m,n = map(int,fileobj.readline().split())
	b = map(int,fileobj.readline().split())
	return {'n': n,'b': b}

def case_solver(**arg):
	left = 0
	right = 10**15
	while left + 1 < right:
		mid = (left + right)/2
		if totalout(arg['b'],mid) < arg['n']:
			left = mid
		else:
			right = mid
	q = arg['n'] - totalout(arg['b'], left)
	print q, arg['b'], arg['n']
	for i,m in enumerate(arg['b']):
		if (right-1) % m == 0:
			q -= 1
			if q == 0:
				return str(i + 1)
	assert False

if __name__ == '__main__':
	main()
	pass