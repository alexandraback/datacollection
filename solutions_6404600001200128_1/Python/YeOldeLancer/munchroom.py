# Google Code Jam 2015, Round 1A
# Problem A. Mushroom Monster
# Lance C. Simons

def inconsistent_monster(plates):
	num_eaten = 0

	for i in range(len(plates)-1):
		diff = plates[i] - plates[i+1]
		if diff > 0:
			num_eaten += diff

	return num_eaten

def consistent_monster(plates):
	num_eaten = 0

	deltas = [plates[i]-plates[i+1] for i in range(len(plates)-1)]
	rate = max(deltas)

	for i in range(len(plates)-1):
		num_eaten += min(plates[i], rate)

	return num_eaten

def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		time_steps = int(inf.next().strip())
		plates = map(int, inf.next().strip().split())
		outf.write("Case #%d: %d %d\n" % (i+1, inconsistent_monster(plates), consistent_monster(plates) ) )


if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))
