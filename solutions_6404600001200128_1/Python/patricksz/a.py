import os, sys, math
from numpy import rate

#__debug=True
__debug=False

def debug(str):
    if __debug:
        print "[DEBUG] %s" % str

def main():
    no_cases=int(sys.stdin.readline().strip())
    for i in range(1,no_cases+1):
        N=int(sys.stdin.readline().strip())
        mushrooms=[int(m) for m in sys.stdin.readline().strip().split(' ')]
        one=0
        for j in range(1,len(mushrooms)):
            if mushrooms[j]<mushrooms[j-1]:
                one+=mushrooms[j-1]-mushrooms[j]
        two=0
        rate=0
        for j in range(1,len(mushrooms)):
            rate=max(rate,mushrooms[j-1]-mushrooms[j])
        debug("rate %d" % rate)
        for j in range(0,len(mushrooms)-1):
            if rate>mushrooms[j]:
                two+=mushrooms[j]
            else:
                two+=rate
        print "Case #%d: %d %d" % (i, one, two)
    return 0


if __name__ == "__main__":
    main()
