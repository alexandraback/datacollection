import sys

def main():
    t = int(sys.stdin.readline().strip())
    for k in xrange(t):
        n = int(sys.stdin.readline().strip())
        counts = [int(s) for s in sys.stdin.readline().strip().split(' ')]
        print "Case #{}:".format(k+1),
        sumv = sum(counts)
        while sumv:
            maxv = max(counts)
            s = ""
            for i in xrange(n):
                if counts[i] == maxv:
                    counts[i] -= 1
                    s += chr(65+i)
                    sumv -= 1
                    if len(s) == 2:
                        break
                    if len(s) == 1 and sumv == 2:
                        break
            if sumv > 1:
                print s,
            else:
                print s

main()
