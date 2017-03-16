import itertools


def foo(R,C,N):
    c1 = C/2
    r1 = R/2
    if N < R*c1 + 1:
        return 0
    if N < C*r1 + 1:
        return 0
    squares = [(x,y) for x in range(1,C+1) for y in range (1,R+1)]
    minHappy = 4*R*C
    for arr in itertools.combinations(squares, N):
        happy = 0
        positions= {}
        for pos in arr:
            positions[pos] = True
        for pos in arr:
            x,y = pos
            if (x+1,y) in positions:
                happy += 1
            if (x,y+1) in positions:
                happy += 1
            if (x-1,y) in positions:
                happy += 1
            if (x,y-1) in positions:
                happy += 1
        happy = happy / 2
        if happy < minHappy:
            minHappy  = happy
    if minHappy == 4*R*C:
        return 0
    return minHappy
        
        
        


##def chooseSquares(squares, N):    
##    if N == 0:
##        return []
##    elif N == 1:
##        return [[x] for x in squares]
##    elif len(squares) == N:
##        return [squares]
##    else:
##        notFirst = chooseSquares(squares[1:], N)
##        withFirst = chooseSquares(squares[1:], N-1)
##        for elt in withFirst:
##            elt.append(squares[0])
##        return withFirst.extend(notFirst)
            
    

f = open("one.in", "r").read()

#new_file = open("sma.txt", "w")
splitted_file = f.split("\n")[:]

lineCounter =1
amountOfLines = len(splitted_file)

case = 0

while(lineCounter < amountOfLines):
    case += 1
    firstLine = splitted_file[lineCounter]
    lineCounter += 1

    R,C,N = [int(x) for x in firstLine.split(" ")]

    out = foo(R,C,N)
    print "Case "+ "#"+str(case) +": " + str(out)
    
    
