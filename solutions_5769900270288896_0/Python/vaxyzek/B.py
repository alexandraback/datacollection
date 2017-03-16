import os,sys, itertools

def unhapiness(R, C, c):
    x = []
    for i in range(R):
        row = [0] * C
        x.append(row)

    for index in c:
        x[index / C][index % C] = 1

    u = 0
    for i in range(R):
        for j in range(C):
            if i < R - 1:
                if x[i][j] == 1 and x[i+1][j] == 1:
                    u = u + 1
            if j < C - 1:
                if x[i][j] == 1 and x[i][j+1] == 1:
                    u = u + 1

    return u

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "B-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

T = int(ifile.readline().strip())
for t in range(T):
    R,C,N = ifile.readline().strip().split()
    R,C,N = int(R), int(C), int(N)

    r = [i for i in range(R*C)]
    u = 2*R*C
    for c in itertools.combinations(r, N):
        u = min(u, unhapiness(R, C, c))


    ans = "Case #" + str(t+1) + ": " + str(u)
    print ans
    ofile.write(ans + "\n")