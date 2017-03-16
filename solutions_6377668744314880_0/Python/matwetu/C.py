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
2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10
""".lstrip())

def case_reader(fileobj):
	n = int(fileobj.readline())
	p = []
	for i in xrange(n):
		p.append(map(int,fileobj.readline().split()))
	return {'n': n,'p': p}

def xp(a,b,c):
	p = [b[0]-a[0], b[1]-a[1]]
	q = [c[0]-a[0], c[1]-a[1]]
	return p[0]*q[1] - p[1]*q[0]
def calc(a,b,p):
	ret = [0,0,0]
	for i in p:
		x = xp(a,b,i)
		if x == 0:
			ret[0] += 1
		elif x > 0: 
			ret[1] += 1
		elif x < 0:
			ret[-1] += 1
	return min(ret[1], ret[-1])

def case_solver(**arg):
	out = []
	if arg['n'] < 4: return '\n0' * arg['n']
	p = arg['p']
	for i,m in enumerate(p):
		ri = arg['n']
		for j,t in enumerate(p):
			if i == j: continue
			ri = min(ri,calc(m,t,p))
		out.append(ri)
	return '\n'+ '\n'.join(map(str, out))

if __name__ == '__main__':
	main()
	pass