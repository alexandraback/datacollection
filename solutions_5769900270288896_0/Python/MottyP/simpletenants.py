import sys

def bitcount(num):
    return bin(num).count('1')

def calc(r, c, n):
    best = r*c*4
    rightSideClearMask = ~sum(1<<(row*c) for row in range(r))
    for bitmap in range(2**(r*c)):
        if bitcount(bitmap) != n:
            continue
        vertUnhappy = bitcount(bitmap & (bitmap >> c))
        horizUnhappy = bitcount(bitmap & (bitmap << 1) & rightSideClearMask)
        unhappy = vertUnhappy + horizUnhappy
        best = min(best, unhappy)
    return best

if __name__ == '__main__':
    ncases = int(sys.stdin.readline())
    for cs in range(1, ncases+1):
        r, c, n = [int(part) for part in sys.stdin.readline().split()]
        best = calc(r, c, n)
        print 'Case #%d: %d' % (cs, best)

