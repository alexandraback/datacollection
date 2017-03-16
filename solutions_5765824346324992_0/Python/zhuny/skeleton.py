def do():
    times = input()
    for i in xrange(times):
        print 'Case #%d:'%(i+1),
        calculate()

from fractions import Fraction as Frac

def calculate():
    B,N = map(int,raw_input().split())
    M = map(int,raw_input().split())

    if B >= N:
        print N
        return

    per = sum(Frac(1,m) for m in M)
    t = max(int((N-1)/per)-3,0)

    while True:
        done = 0
        reminder = 1000000
        doing = []
        
        for i,m in enumerate(M,1):
            d,r = divmod(t,m)
            done += d
            doing.append((t-r,i))
            reminder = min(reminder,m-r)

        doing.sort()
        if done < N <= done+B:
            print doing[N-done-1][1]
            break
        
        t += reminder



if __name__ == '__main__':
    do()

