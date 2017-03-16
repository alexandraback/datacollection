T= int(raw_input())
    
for test in range(1,T+1):
    raw_input()
    mushroom=map(int,(raw_input()).split())
    drops=[max(0,-a+b) for (a,b) in zip(mushroom[1:],mushroom)]
    speed=max(drops)
    strat2=[min(speed,mush) for mush in mushroom[:-1]]
    print "Case #{0}: {1} {2}".format(test,sum(drops),sum(strat2))
    
