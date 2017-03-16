from sys import stdin

def readTest():
    a1 = int(stdin.readline()) - 1
    g1 = [[int(x) for x in stdin.readline().split(' ')] for i in xrange(4)]
    a2 = int(stdin.readline()) - 1
    g2 = [[int(x) for x in stdin.readline().split(' ')] for i in xrange(4)]
    return (a1, g1, a2, g2)

def solve(a1, g1, a2, g2):
   common = set(g1[a1]) & set(g2[a2])
   if len(common) == 0: 
       return "Volunteer cheated!"
   if len(common) > 1:
       return "Bad magician!"
   return list(common)[0]

if __name__ == "__main__":
    T = int(stdin.readline())
    for t in xrange(T):
        a1, g1, a2, g2 = readTest()
        print "Case #{0}: {1}".format(t + 1, solve(a1, g1, a2, g2))
