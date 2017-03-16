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

def even_chess(R, C, N):
    #print 'even'
    mat = [[0]*C for i in xrange(R)]
    for y in xrange(R):
        for x in xrange(C):
            if (x+y) % 2 == 0:
                mat[y][x] = 1
                N -= 1
    while N > 0:
        # Try corners
        if mat[0][0] == 0:
            N-=1
            mat[0][0] = 1
            continue
        if mat[0][C-1] == 0:
            N-=1
            mat[0][C-1] = 1
            continue
        if mat[R-1][0] == 0:
            N-=1
            mat[R-1][0] = 1
            continue
        if mat[R-1][C-1] == 0:
            N-=1
            mat[R-1][C-1] = 1
            continue
        # Try edges
        # Left side
        for y in xrange(1, R, 2):
            if mat[y][0] == 0:
                N -= 1
                mat[y][0] = 1
                if N == 0:
                    break
        if N == 0:
            break
        # Right side:
        for y in xrange(C%2, R, 2):
            if mat[y][C-1] == 0:
                N -= 1
                mat[y][C-1] = 1
                if N == 0: 
                    break
        if N == 0:
            break
        # Top:
        for x in xrange(1, C, 2):
            if mat[0][x] == 0:
                N -= 1
                mat[0][x] = 1
                if N == 0:
                    break
        if N == 0:
            break
        # Bottom:
        for x in xrange(R%2, C, 2):
            if mat[R-1][x] == 0:
                N -= 1
                mat[R-1][x] = 1
                if N == 0:
                    break
        if N == 0:
            break
        # The rest:
        for y in xrange(1, R-1):
            for x in xrange(1, C-1):
                if mat[y][x] == 0:
                    N -= 1
                    mat[y][x] = 1
                    if N == 0:
                        break
            if N == 0:
                break

    return calc_happiness(mat, R, C)

def odd_chess(R, C, N):
    #print 'odd'
    mat = [[0]*C for i in xrange(R)]
    for y in xrange(R):
        for x in xrange(C):
            if (x+y) % 2 == 1:
                mat[y][x] = 1
                N -= 1
    while N > 0:
        # Try corners
        if mat[0][0] == 0:
            N-=1
            mat[0][0] = 1
            continue
        if mat[0][C-1] == 0:
            N-=1
            mat[0][C-1] = 1
            continue
        if mat[R-1][0] == 0:
            N-=1
            mat[R-1][0] = 1
            continue
        if mat[R-1][C-1] == 0:
            N-=1
            mat[R-1][C-1] = 1
            continue
        # Try edges
        # Left side
        for y in xrange(0, R, 2):
            if mat[y][0] == 0:
                N -= 1
                mat[y][0] = 1
                if N == 0:
                    break
        if N == 0:
            break
        # Right side:
        for y in xrange(1 - (C%2), R, 2):
            if mat[y][C-1] == 0:
                N -= 1
                mat[y][C-1] = 1
                if N == 0: 
                    break
        if N == 0:
            break
        # Top:
        for x in xrange(0, C, 2):
            if mat[0][x] == 0:
                N -= 1
                mat[0][x] = 1
                if N == 0:
                    break
        if N == 0:
            break
        # Bottom:
        for x in xrange(1 - (R%2), C, 2):
            if mat[R-1][x] == 0:
                N -= 1
                mat[R-1][x] = 1
                if N == 0:
                    break
        if N == 0:
            break
        # The rest:
        for y in xrange(1, R-1):
            for x in xrange(1, C-1):
                if mat[y][x] == 0:
                    N -= 1
                    mat[y][x] = 1
                    if N == 0:
                        break
            if N == 0:
                break
    return calc_happiness(mat, R, C)

def do_case(ncase):
    R, C, N = parse_line()
    print 'case',ncase
    if N <= (R*C+1)/2:
        print >>outputfile, out_s % (ncase, str(0))
        return

    if R == C == 1:
        print >>outputfile, out_s % (ncase, str(0))
        return

    # Try first zigzag
    op1 = even_chess(R, C, N)
    op2 = odd_chess(R, C, N)
    print >>outputfile, out_s % (ncase, str(min(op1, op2)))

T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    do_case(ncase)
    