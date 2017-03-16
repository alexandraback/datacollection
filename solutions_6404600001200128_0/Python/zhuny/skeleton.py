def do():
    times = input()
    for i in xrange(times):
        print 'Case #%d:'%(i+1),
        calculate()

def conti(L):
    return zip(L[:-1],L[1:])

def calculate():
    N = input()
    L = map(int,raw_input().split())
    C = conti(L)
    
    interval = 10
    
    first = 0
    for bef,aft in C:
        first += max(bef-aft,0)
    
    second = 0
    rate = 0
    for bef,aft in C:
        rate = max(rate,bef-aft)
    for bef,aft in C:
        after_eat = max(bef-rate,0)
        second += bef-after_eat
    
    print first,second



if __name__ == '__main__':
    do()

