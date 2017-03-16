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
    
def main():
    input1 = open('input1.txt', 'r')
    output1 = open('output1.txt', 'w')

    T = int(input1.readline())      #number of test cases
    
    for casenum in xrange(1, T + 1):
        line = input1.readline().strip().split(' ')
        R = int(line[0])
        C = int(line[1])
        N = int(line[2])
        
        min_unhappiness = 10*N
        options = list(itertools.combinations(range(R*C), N))
        for set in options:
            housing = [['.' for j in xrange(C)] for i in xrange(R)]
            for i in set:
                housing[i/C][i%C] = 'x'
            unhappiness = countUnhappiness(R,C,housing)
            if(unhappiness < min_unhappiness):
                min_unhappiness = unhappiness
        
        outstr = 'Case #' + str(casenum) + ': '
        outstr += str(min_unhappiness)
        outstr += '\n'
        output1.write(outstr)

    input1.close()
    output1.close()
  
    
    
main()