import sys

def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())
            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")
                # print testNum
                line1 = inputFile.readline().split()
                numBarbers, place = int(line1[0]), int(line1[1])
                times = inputFile.readline().split()
                times = [int(t) for t in times]
                # barberNumber = range(numBarbers)
                # barberNumber = [b+1 for b in barberNumber]
                
                barber = calcBarber(numBarbers, place, times)
                # temp = zip(times, barberNumber)

                outputFile.write("Case #%d: %d" % (testNum+1, barber))

def calcBarber(numBarbers, place, times):
    multiple = lcm(*times)
    served = numServed(times, multiple)
    place = place % served
    place += served
    p = 1
    waits = [0] * numBarbers
    while p < place:
        barber = waits.index(min(waits))
        waits[barber] += times[barber]
        p += 1
    return waits.index(min(waits))+1 

def numServed(times, lcm):
    numServed = 0
    for t in times:
        numServed += lcm/t
    return numServed



########## Code from here: https://gist.github.com/endolith/114336
# Greatest common divisor of more than 2 numbers.  Am I terrible for doing it this way?
 
def gcd(*numbers):
    """Return the greatest common divisor of the given integers"""
    from fractions import gcd
    # print gcd
    # print numbers
    return reduce(gcd, numbers)
 
# Least common multiple is not in standard libraries? It's in gmpy, but this is simple enough:
 
def lcm(*numbers):
    """Return lowest common multiple."""    
    # print numbers
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    return reduce(lcm, numbers, 1)
########### End copypasta


main()