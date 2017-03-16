# Solution to "Mushroom Monster" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def solve(N, plate):
    #Method 1
    eaten1 = 0
    rate = 0
    for p in xrange(N - 1):
        next = plate[p] - plate[p + 1]
        if next > 0:
            eaten1 += next
            if next > rate:
                rate = next
    #Method 2
    eaten2 = 0
    for p in xrange(N - 1):
        eaten2 += min(rate, plate[p])
    return str(eaten1) + " " + str(eaten2)



def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            N = int(infile.readline())
            plate = [int(x) for x in infile.readline().split()]
            yield N, plate

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
