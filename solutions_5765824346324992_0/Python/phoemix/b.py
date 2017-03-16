######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################


def lcm(x, y):
   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

def lcmm(*args):
    return reduce(lcm, args)

def solve(n, mi):
    time = 1
    last_i = -1
    while (1):
        for i, m in enumerate(mi):
            if (time%m == 0):
                n -= 1
                last_i = i
            if (n <= 0):
                return i
        time += 1

if __name__ == '__main__':
    T = int(raw_input())

    for case in xrange(1, T + 1):
        b, n = map(int, raw_input().split())
        mi = map(int, raw_input().split())

        if n < b:
            print "Case #%d: %d" %(case, n)
            continue
        n -= b

        mmc = lcmm(*mi)
        s = 0
        for a in mi:
            s += mmc/a

        temp =  n%s

        if temp == 0:
            print "Case #%d: %d" %(case, b)
        else:
            i = solve(n%s, mi)
            print "Case #%d: %d" %(case, i + 1)
