import itertools

def get_data (len, max):
	if len <= 0: 
		if (max == 0): yield []
		return 

	for i in get_data(len-1, max):
		yield [False] + i

	if (max > 0):
		for i in get_data(len-1, max-1):
			yield [True] + i


def get_tables (N, R, C):
	for data in get_data(R*C, N):
		yield [data[i*C:(i+1)*C] for i in range(R)]

def count (table):
	res = 0

	for i in range(len(table)):
		for j in range(len(table[i])):
			if not table[i][j]: continue
			if i > 0 and table[i-1][j]: res += 1
			if j > 0 and table[i][j-1]: res += 1

	return res

for case in range(int(input())):
	R, C, N = [int(x) for x in input().strip().split()]

	print ("Case #{}: {}".format(case+1, min([count(table) for table in get_tables(N, R, C)])))