def f(x):
	x = list(map(int, x.split()))
	
	ans = []
	while 1:
		m = max(x)
		if m == 0:
			return ' '.join(ans)
		indexes = [i for i, val in enumerate(x) if val == m]
		if len(indexes) == 1 or len(indexes) > 2:
			x[indexes[0]] -= 1
			ans.append(pc(indexes[0]))
		else:
			x[indexes[0]] -= 1
			x[indexes[1]] -= 1
			ans.append(pc(indexes[0]) + pc(indexes[1]))


def pc(i):
	return chr(ord('A') + i)



n = int(input())
for i in range(n):
	input()
	x = f(input())
	print("Case #{0}: {1}".format(i+1, x))