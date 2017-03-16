from itertools import groupby
from math import ceil

def main():
	for TEST in xrange(1, int(raw_input())+1):
		N = int(raw_input())
		strings = [raw_input() for _ in xrange(N)]

		groups = [ [(k, len(list(g))) for k, g in groupby(s)] for s in strings ]
		group_lengths = list(map(len, groups))

		impossible = False

		if len(set(group_lengths)) > 1:
			impossible = True
		else:
			moves = 0
			for c in zip(*groups):
				if len(set(k for k, _ in c)) != 1:
					impossible = True
					break
				max_consecutive = max(count for _,count in c)
				all_n_moves = [sum(abs(count - target_len) for _,count in c) for target_len in xrange(1, max_consecutive+1)]
				best_n_moves = min(all_n_moves)
				moves += best_n_moves

		if impossible:
			print "Case #%d: %s" % (TEST, "Fegla Won")
		else:
			print "Case #%d: %d" % (TEST, moves)
main()
