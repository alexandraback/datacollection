
def diff(l):
  diffs = []
  for i in range(len(l) - 1):
    diffs.append(l[i] - l[i+1])
  return diffs

f = open("1.in");
lines = [l.strip() for l in f]

ncases = int(lines[0])

outfile = open("1.out", "w")
output_str = 'Case #{0}: {1} {2}'

for i in range(1, ncases+1):
	n_inputs = int(lines[2*i - 1])
	inp = [int(x) for x in lines[2*i].split()]
	
	diffs = diff(inp)
	
	# method 1 - sum of positive diffs
	meth_1 = sum([d for d in diffs if d > 0])
	
	min_rate = max(max(diffs), 0)
	deficits = [max(min_rate - amount, 0) for amount in inp]
	
	# eat at min_rate unless our plate could be empty
	meth_2 = min_rate * len(diffs) - sum(deficits[:-1])
	
	print(output_str.format(i, meth_1, meth_2))
	
#	print(inp)
#	print(diff(inp))
