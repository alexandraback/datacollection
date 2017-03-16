import string


parties_names = string.ascii_uppercase

tests = int(input())



def solve(d, maj):
	m = max(maj.values())
	key = None
	taken = []
	for i in maj:
		if maj[i] == m:
			key = i
			break

	taken.append(key)

	d[key] -= 1
	if d[key] == 0:
		d.pop(key)
	
	total = sum(d.values())
	
	for i in d:
		maj[i] = d[i] / total

	m = max(maj.values())
	if m > 0.5:
		key = None
		for i in maj:
			if maj[i] == m:
				key = i
				break

		taken.append(key)
		d[key] -= 1
		if d[key] == 0:
			d.pop(key)
	return taken

test = 1

while test <= tests:
	num = int(input())
	parties = list(map(int, input().split(' ')))
	maj = dict()
	d = dict()
	total = sum(parties)
	for i in range(len(parties)):
		d[parties_names[i]] = parties[i]
		maj[parties_names[i]] = parties[i] / total

	taken = []
	while len(d) > 0:
		taken.append(solve(d, maj))

	print('Case #%d: ' % (test,), end='')
	for i in taken:
		print(''.join(i), end=' ')

	print('')
	
	test += 1

