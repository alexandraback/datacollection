def normalize(str):
	chs = []
	counts = []
	for ch in str:
		if not chs or ch != chs[-1]:
			chs.append(ch)
			counts.append(1)
		else:
			counts[-1] += 1
	# print str, chs, counts
	return chs, counts


def count_insts_at(a, idx):
	v = a[idx]
	count = 1
	for i in range(idx+1, len(a)):
		if a[i] != v:
			return count
		count += 1
	return count


def cost(counts):
	# print counts
	counts = sorted(counts)
	n = len(counts)
	idx = 0
	val = counts[0]
	left = 0
	count = count_insts_at(counts, 0)
	right =	n - count
	cost = sum(counts[idx+count:]) - right * val
	# print cost
	min_cost = cost
	while True:
		new_idx = idx + count
		if new_idx >= n:
			break
		new_val = counts[new_idx]
		new_left = left + count
		new_count = count_insts_at(counts, new_idx)
		new_right = right - new_count
		new_cost = cost + (new_val - val) * (new_left - right)
		# print '** ', cost, new_cost, new_left, right, new_val - val
		if new_cost < min_cost:
			min_cost = new_cost
		idx = new_idx
		val = new_val
		left = new_left
		count = new_count
		right = new_right
		cost = new_cost
	# print min_cost
	return min_cost


def solve(N, strs):
	chs0, counts = normalize(strs[0])
	all_counts = [counts]
	for i in range(1, N):
		chs, counts = normalize(strs[i])
		if chs != chs0:
			return None
		all_counts.append(counts)
	total_cost = 0
	for i in range(len(chs0)):
		c = cost([cs[i] for cs in all_counts])
		total_cost += c
	return total_cost




################################################################################


def read_ints(f):
	return [int(w) for w in f.readline().strip().split()]

def read_int(f):
	return int(f.readline().strip())


from sys import argv, setrecursionlimit

# setrecursionlimit(2200)

f = open(argv[1])

T = read_int(f);

for t in range(1, T+1):
	N = read_int(f)
	strs = N * [None]
	for i in range(N):
		strs[i] = f.readline().strip()
	res = solve(N, strs)
	if res is None:
		res = "Fegla Won"
	print 'Case #%s: %s' % (t, res)
