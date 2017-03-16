import itertools

def countUnhappiness(R,C,housing):
    unhappiness = 0
    
    for i in xrange(R):
        for j in xrange(C-1):
            if(housing[i][j] == 'x' and housing[i][j+1] == 'x'):
                unhappiness += 1
    for i in xrange(R-1):
        for j in xrange(C):
            if(housing[i][j] == 'x' and housing[i+1][j] == 'x'):
                unhappiness += 1
    
    return unhappiness

def countBadness(r,c,housing):    
    if(housing[r][c] == '.'):
        return -1
    
    R = len(housing)
    C = len(housing[0])
    badness = 0
    if((r > 0) and housing[r-1][c] == 'x'):
        badness += 1
    if((r < (R-1)) and housing[r+1][c] == 'x'):
        badness += 1
    if((c > 0) and housing[r][c-1] == 'x'):
        badness += 1
    if((c < (C-1)) and housing[r][c+1] == 'x'):
        badness += 1

    
    return badness
        
def main():
    input1 = open('input1.txt', 'r')
    output1 = open('output1.txt', 'w')

    T = int(input1.readline())      #number of test cases
    
    for casenum in xrange(1, T + 1):
        line = input1.readline().strip().split(' ')
        R = int(line[0])
        C = int(line[1])
        N = int(line[2])
        
        housing = [['x' for j in xrange(C)] for i in xrange(R)]
        to_remove = R*C - N
        
        t = 4
        while(t>=0 and to_remove > 0):
            r = 0
            while(r < R and to_remove > 0):
                c = 0
                while(c < C and to_remove > 0):
                    if(t == countBadness(r,c,housing)):
                        housing[r][c] = '.'
                        to_remove = to_remove - 1
                    c += 1
                r += 1
            t = t - 1
            
        
        for i in xrange(to_remove):
            worst_badness = -1
            worst_row = -1
            worst_col = -1
            for r in xrange(R):
                for c in xrange(C):
                    badness = countBadness(r,c,housing)
                    if(badness > worst_badness):
                        worst_badness = badness
                        worst_row = r
                        worst_col = c
            housing[worst_row][worst_col] = '.'
        
        outstr = 'Case #' + str(casenum) + ': '
        outstr += str(countUnhappiness(R,C,housing))
        outstr += '\n'
        output1.write(outstr)

    input1.close()
    output1.close()


main()