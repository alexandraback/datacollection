import os,sys

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "A-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

T = int(ifile.readline().strip())
for t in range(T):
	N = int(ifile.readline().strip())
	strs = []
	for n in range(N):
		strs.append(ifile.readline().strip())

	rstrs = []
	nstrs = []
	for n in range(N):
		pc = ' '
		cc = 0
		rs = []
		nrs = []
		for c in strs[n]:
			if c != pc:
				if pc != ' ':
					rs.append(pc)
					nrs.append(cc)
				pc = c
				cc = 1
			else:
				cc = cc + 1
		rs.append(pc)
		nrs.append(cc)
		#print rs, nrs
		rstrs.append(rs)
		nstrs.append(nrs)

	#print [len(rs) for rs in rstrs]
	lengths = set([len(rs) for rs in rstrs])

	failed = True
	moves = 0
	if len(lengths) == 1:
		failed = False
		for L in lengths:
			for l in range(L):
				characters = set([rs[l] for rs in rstrs])
				if len(characters) != 1:
					failed = True
					break;
				else:
					counts = set([nrs[l] for nrs in nstrs])
					M = max(counts)
					mn = N * M
					#print l, "max "
					for m in range(M + 1):
						#print l, "Max = ", m, "Sum = ", [abs(m - nrs[l]) for nrs in nstrs]
						mn = min(mn, sum([abs(m - nrs[l]) for nrs in nstrs]))
					#print l, mn
					moves = moves + mn 
			if failed:
				break


	ans = "Case #" + str(t+1) + ": " + (failed and "Fegla Won" or str(moves))
	print ans
	ofile.write(ans + "\n")