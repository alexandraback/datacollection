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
        points=[]
        for j in range(0,N):
            variables=sys.stdin.readline().strip().split(' ')
            points.append((int(variables[0]),int(variables[1])))
        debug(points)
        min_x=min([p[0] for p in points])
        max_x=max([p[0] for p in points])
        min_y=min([p[1] for p in points])
        max_y=max([p[1] for p in points])
        debug("x range %d %d; y range %d %d"%(min_x,max_x,min_y,max_y))
        print "Case #%d:" % i
        for p in points:
            if p[0]==min_x or p[0]==max_x or p[1]==min_y or p[1]==max_y:
                print '0'
            else:
                min_points=100000
                for k in points:
                    if p==k:
                        continue
                    min_points=min(get_log(p, k, points),min_points)
                print min_points
                    
    return 0
#((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x))
def get_log(p, k, points):
    left_num=0
    right_num=0
    for z in points:
        debug("a %s b %s c %s" %(p,k,z))
        if ((k[0] - p[0])*(z[1] - p[1]) - (k[1] - p[1])*(z[0] - p[0])) <=0:
            left_num+=1
        else:
            right_num+=1
    debug("p %s k %s left %d right %d"%(p,k,left_num,right_num))
    return min(left_num, right_num)
        

if __name__ == "__main__":
    main()
