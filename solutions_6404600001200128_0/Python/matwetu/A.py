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
4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
""".lstrip())

def method1(m):
	s = m[0]
	t = 0
	for i in m:
		if s - i > 0: t += s - i
		s = i
	return t
def method2(m):
	d = map(lambda x:x[0]-x[1], zip(m,m[1:]))
	r = max(d)
	t = 0
	s = 0
	return sum(map(lambda x:min(x,r), m[:-1]))

def case_reader(fileobj):
	n = int(fileobj.readline())
	m = map(int, fileobj.readline().split())
	return {'n':n,'m':m}

def case_solver(**arg):
	return "%d %d" % (method1(arg['m']), method2(arg['m']))

if __name__ == '__main__':
	main()
	pass