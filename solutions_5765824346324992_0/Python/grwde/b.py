T= int(raw_input())

def time(t):
    return [1+t/s for s in barberspeed]

def numberofclients(t):
    return sum(time(t))

def binary_search(target,low, high,fun):
    while high-low>1:
        pivot=(low+high)/2
        if fun(pivot)<target:
            low=pivot
        else:
            high=pivot
    return high

for test in range(1,T+1):
    n=map(int,raw_input().split())[1]
    barberspeed=map(int,(raw_input()).split())
    if n<=len(barberspeed):
        print "Case #{0}: {1}".format(test,n)
        continue
    mytime=binary_search(n,0,n*max(barberspeed)+1,numberofclients)
    dif=[k+1 for (k,(a,b)) in enumerate(zip(time(mytime-1),
        time(mytime))) if not a==b]
    mybarber=dif[n-numberofclients(mytime-1)-1]
    print "Case #{0}: {1}".format(test,mybarber)
    
