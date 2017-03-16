import sys

import psyco; psyco.full()

def get_unhappy(bld, x, y):
    n = 0
    # if bld[x][y] == ".":
        # return 0
        
    for xd,yd in ((-1,0), (1,0), (0,-1), (0,1)):
        if bld[x+xd][y+yd] == "X":
            n += 1
    return n

def test(R, C, N, mode):
    bld = []
    bld.append(["."] * (R+2))
    for i in xrange(C):
        x = ["."]
        x.extend(["X"] * R)
        x.append(".")
        bld.append(x)
    bld.append(["."] * (R+2))
    
    unhappy = R * C * 2 - (R + C)
    
    toremove = R*C - N

    if (R >= 3 and C >= 3) and toremove >= 1:
        if mode == "0":
            bld[2][2] = "."
            unhappy -= get_unhappy(bld, 2, 2)
            toremove -= 1
        elif mode == "1":
            bld[3][2] = "."
            unhappy -= get_unhappy(bld, 3, 2)
            toremove -= 1
        elif mode == "2":
            bld[2][3] = "."
            unhappy -= get_unhappy(bld, 2, 3)
            toremove -= 1
            
    for target in xrange(4, -1, -1):
        for y in xrange(1, R+1):
            for x in xrange(1, C+1):
                if toremove > 0 and get_unhappy(bld, x, y) == target and bld[x][y] == "X":
                    bld[x][y] = "."
                    unhappy -= target
                    toremove -= 1
    
    for y in xrange(1,R+1):
        s = ""
        for x in xrange(1,C+1):
            #s += str(get_unhappy(bld, x, y))#
            s += bld[x][y] + " "
        # print s
    # print unhappy
    # print
    
    return unhappy

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        R, C, N = [int(x) for x in f.readline().split()]
        #print R, C, N
        res = 9999999999999
        res = min(res, test(R, C, N, "0"))
        res = min(res, test(R, C, N, "1"))
        res = min(res, test(R, C, N, "2"))
        res = min(res, test(R, C, N, "3"))

        print "Case #%d: %d" % (caseno+1, res)
        
main()