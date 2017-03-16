import re
import numpy as np

def ProcessOne():
	N = int(raw_input())
	core = None
	broken = False
	lenses = []

	for j in range(N):
		strr = raw_input()

		currentCore = ""
		lens = []
		while strr != "":
			currentCore += strr[0]
			lens.append (len(re.match(r"((.)\2*)", strr).group(1)))
			strr = re.sub(r"((.)\2*)", "", strr, count=1)

		lenses.append(lens)

		if core and core != currentCore:
			broken = True

		if core == None:
			core = currentCore

	if broken:
		print ("Case #%(id)s: Fegla Won" % {"id" : i+1})
		return

	# Winning scenario - calculate the distances
	letterdistances = np.transpose(lenses)
	lettermedians = np.around(np.median(letterdistances, 1))

	dist = 0
	for j in range(len(letterdistances)):
		distances = np.absolute(np.subtract(letterdistances[j], lettermedians[j]))
		dist += np.sum(distances)

	print ("Case #%(id)s: %(dist)s" % {"id" : i+1, "dist" : int(np.around(dist))})

T = int(raw_input())

for i in range(T):
	ProcessOne()




