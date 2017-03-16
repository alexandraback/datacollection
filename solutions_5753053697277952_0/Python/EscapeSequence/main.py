def solve(n,count):
	eject = []
	total = sum(count)
	while total > 0:
		biggest = max(count)
		indices = [i for i, x in enumerate(count) if x == biggest]
		if biggest*2 > total:
			print("ERROR ")
			print(count)	
		if len(indices) >= 2:
			if total == 3:
				eject.append(chr(indices[0] + ord('A')))
				count[indices[0]] -= 1
				total -= 1
			else:
				eject.append(chr(indices[0] + ord('A')) + chr(indices[1] + ord('A')))
				count[indices[0]] -= 1
				count[indices[1]] -= 1
				total -= 2
		else:
			if (biggest == 1) or (biggest == 2 and total == 3):
				eject.append(chr(indices[0] + ord('A')))
				count[indices[0]] -= 1
				total -= 1
			else:
				eject.append(chr(indices[0] + ord('A')) + chr(indices[0] + ord('A')))
				count[indices[0]] -= 2
				total -= 2
	return eject

f = open('A-small-attempt0.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	n = int(f.readline())
	count = [int(x) for x in f.readline().split()]
	output = 'Case #{0}: '.format(case) + ' '.join([str(x) for x in solve(n,count)]) + "\n"
	print(output)
	out.write(output)

out.close()