# -*- coding: utf-8 -*-

# start of common segment

import sys

with open(sys.argv[1].strip()) as fp:
	INPUT_LINES = map(str.strip, fp.readlines())


# end of common segment

NCASES = int(INPUT_LINES[0])
del INPUT_LINES[0]

for case_n in xrange(NCASES):
	MYDATA = INPUT_LINES[:10]
	INPUT_LINES = INPUT_LINES[10:]

	ROW_FIRST, ROW_SECOND = int(MYDATA[0]), int(MYDATA[5])

	# first iterate
	candidates = set(map(int, MYDATA[ROW_FIRST].split()))

	# second
	candidates = candidates & set(map(int, MYDATA[5 + ROW_SECOND].split()))

	if len(candidates) == 1:
		print("Case #%d: %d" % (case_n + 1, list(candidates)[0]))
	elif len(candidates) == 0:
		print("Case #%d: Volunteer cheated!" % (case_n + 1))
	else:
		print("Case #%d: Bad magician!" % (case_n + 1))
