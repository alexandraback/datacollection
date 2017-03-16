from heapq import *

def evac(l):
    s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    el = [(-j,s[i]) for i,j in enumerate(l)]
    #l = sorted(hist.items(), key=lambda a:a[1])
    heapify(el)
    while el:
        #print el
        an, a = heappop(el)
        if an <= -2:
            if an == -2:
                if len(el) == 1:
                    print a,
                    heappush(el, (an+1, a))    
                else:
                    print a*2,
            else:
                print a*2,
                heappush(el, (an+2, a))
            continue
        if el:
            bn, b = heappop(el)
            print a + b,
            if bn < -1:
                heappush(el, (bn+1, b))
        else:
            print a,
    print 
            
t = int(raw_input())

for i in range(t):
    n = int(raw_input())
    s = map(int, raw_input().split())
    print "Case #{}:".format(i+1),
    evac(s)
    
