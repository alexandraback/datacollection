import fileinput
from collections import Counter



def update(pair, data):
	for index in pair:
		data[index] += 1
	return ''.join(chr(ord('A') + index) for index in pair)


def main():
	stream = fileinput.input()
	cases = int(next(stream))
	for case in xrange(cases):
		next(stream)
		target = map(int, next(stream).strip().split(' '))
		source = len(target) * [0]
		steps = []
		updated = True
		while updated:
			updated = False
			pair = []
			for i in xrange(len(target)):
				if target[i] - source[i] > 0:
					updated = True
					pair.append(i)
					if len(pair) == 2:
						step = update(pair, source)
						steps.append(step)
						pair = []
			if pair:
				steps.append(update(pair, source))
				pair = []
		print "Case #%d: %s" % (case + 1, ' '.join(reversed(steps)))


if __name__ == '__main__':
	main()
