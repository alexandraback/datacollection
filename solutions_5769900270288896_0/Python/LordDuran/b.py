from pprint import pprint
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

def calc_happiness(mat, R, C):
    uh  = 0
    val = lambda y,x: 0 <= y < R and 0 <= x < C
    for y in xrange(R):
        for x in xrange(C):
            #print R,C,y,x
            if mat[y][x] == 0:
                continue
            if val(y-1,x) and mat[y-1][x] == 1:
                uh += 1
            if val(y+1,x) and mat[y+1][x] == 1:
                uh += 1
            if val(y, x-1) and mat[y][x-1] == 1:
                uh += 1
            if val(y, x+1) and mat[y][x+1] == 1:
                uh += 1
    return uh/2

def try_give(mat, R, C, n, minn):
    if minn >= R*C and n != 0:
        return 99999999999
    if n == 0:
        return calc_happiness(mat, R, C)
    if R*C - minn <= n: #minn places left
        mat[minn / C][minn % C] = 1
        mini = try_give(mat, R, C, n - 1, minn + 1)
        mat[minn / C][minn % C] = 0
        return mini

    mat[minn/C][minn % C] = 1
    op1 = try_give(mat, R, C, n-1, minn+1)
    mat[minn/C][minn % C] = 0
    op2 = try_give(mat, R, C, n, minn+1)
    return min(op1, op2)

def do_case(ncase):
    R, C, N = parse_line()
    mat = [[0]*C for i in xrange(R)]
    print >>outputfile, out_s % (ncase, str(try_give(mat, R, C, N, 0)))

T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    do_case(ncase)
    