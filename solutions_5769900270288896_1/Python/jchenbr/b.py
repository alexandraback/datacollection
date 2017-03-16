
import sys
import math

def try_occ(n, m, to_do, to_go):
		
	count = [0 for i in range(5)];
	grid = [[0 for j in range(m)] for i in range(n)];
	
	to_go
	to_beg = to_go;
	for i in range(n):
		to_beg ^= 1;
		for j in range(to_beg, m, 2):
			grid[i][j] = 0
			if (i > 0):
				grid[i - 1][j] += 1
			if (i < n - 1):
				grid[i + 1][j] += 1
			if (j > 0):
				grid[i][j - 1] += 1
			if (j < m - 1):
				grid[i][j + 1] += 1
				
	for i in range(n):
		for j in range(m):
			count[grid[i][j]] += 1;
			
	ans = 0
	for i in range(5):
		tmp = min(to_do, count[i]);
		ans += tmp * i;
		to_do -= tmp;
		
	return ans;
	
	
if __name__ == "__main__":

	fin = open(sys.argv[1], 'r')
	
	data = fin.readlines();
	#print data, data
	
	total = int(data[0]);
	
	for case in range(1, total + 1):
		r,c,n = [int(item) for item in data[case].split()];
		
		ans = min(try_occ(r, c, n, 0), try_occ(r, c, n, 1));
		
		print "Case #" + str(case) + ":", ans