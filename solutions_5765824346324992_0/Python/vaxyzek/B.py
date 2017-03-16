import os,sys, fractions

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
    (B, N) = ifile.readline().strip().split()
    B = int(B)
    N = int(N)
    M = ifile.readline().strip().split()
    M = [int(m) for m in M]
    
    P = M[0]
    if B > 1:
        for i in range(B):
            P = P*M[i]/fractions.gcd(P, M[i])


    #print "P=",P

    c = 0
    for i in range(B):
        c = c + P / M[i]

    #print M, N, P
    #print "Can cut",c,"customers for time", P
    #print N, "->", (N%c)
    N = N % c
    #print N

    if N == 0:
        N = c
    #print "Calc for N =",N
    R = [0] * B
    while N > 0:
        #print "-",R, N
        r = min(R)
        for i in range(B):
            R[i] = R[i] - r
            
        for i in range(B):
            if R[i] == 0:
                N = N - 1
                #print R, N
                if N == 0:
                    break
                R[i] = M[i]

                
    #print "Final",R
    r = min(R)
    b = 0
    for i in range(B):
        if R[i] == r:
            b = i
            break
    #print b

    ans = "Case #" + str(t+1) + ": " + str(b+1)
    print ans
    ofile.write(ans + "\n")