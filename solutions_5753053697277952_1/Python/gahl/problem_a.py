def num_parties(p):
	return sum([1 for a in p if a > 0])

def get_biggest_parties(p):
	l = [0]
	for i, a in enumerate(p):
		if i == 0:
			continue
		if p[l[0]] < a:
			l = [i]
		elif p[l[0]] == a:
			l.append(i)

	return l


def one(line):
	parties = [int(a) for a in line.split(' ')]
	out = []
	biggest = get_biggest_parties(parties)
	while num_parties(parties) > 2 or len(biggest) == 1:
		out.append(biggest[0])
#		print 'out: %d, ' % biggest[0],
		parties[biggest[0]] -= 1
		biggest = get_biggest_parties(parties)


	if num_parties(parties) != 2:
		raise "WWWW"

	while num_parties(parties) > 0:
		out.append(biggest)
#		print 'out: %s, ' % biggest,
		for p in biggest:
			parties[p] -= 1
		biggest = get_biggest_parties(parties)

	x = []
	for a in out:
		if isinstance(a, int):
			x.append(chr(ord('A') + a))
		else:
			x.append(''.join(chr(ord('A') + b) for b in a))

	return ' '.join(x)


def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		num = raw_input()
		parties = raw_input()
		print "Case #%d: %s" % (x + 1, one(parties))

main()