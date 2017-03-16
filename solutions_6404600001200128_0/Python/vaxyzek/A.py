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
    M = ifile.readline().strip().split()
    m = [int(m) for m in M]

    #print M

    a = 0
    b = 0
    drop = 0
    for i in range(1, N):
        #print i
        if m[i] < m[i-1]:
            a = a + (m[i - 1] - m[i])
            drop = max(drop, m[i - 1] - m[i])

    #print "Drop =", drop
    for i in range(N - 1):
        #print b
        b = b + min(drop, m[i])

    ans = "Case #" + str(t+1) + ": " + str(a) + " " + str(b)
    print ans
    ofile.write(ans + "\n")