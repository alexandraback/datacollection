######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################

def solve():
    pass

if __name__ == '__main__':
    T = int(raw_input())

    for case in xrange(1, T + 1):
        N = int(raw_input())
        mi = map(int, raw_input().split())

        y = 0
        z = 0
        r = 0

        r = 0
        i = 0
        while (i < N - 1):
            r = max(r, mi[i] - mi[i + 1])
            i += 1

        for a, b in zip(mi, mi[1:]):
            if (a > b):
                y += a - b
            if (a != 0):
                if (a < r):
                    z += a
                else:
                    z += r

        print "Case #%d: %d %d" %(case, y, z)
