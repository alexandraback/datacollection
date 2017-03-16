import sys,re,math

def IsAbove(p1,p2,t):
    # determine if t is above the line formed by p1,p2; if p1_x == p2_x, above means left
    # if True: return 1; on the line, return 0; below, return -1
    if p1[0] == p2[0]:
        if t[0] == p1[0]: return 0
        elif t[0] > p1[0]: return 1
        else: return -1
    else:
        # compute the y coordinate of the line at t[0]
        slope = (p2[1] - p1[1]) * 1.0 / (p2[0] - p1[0])
        t_y = ( t[0] - p1[0] ) * 1.0 * slope + p1[1]
        if t_y == t[1]: return 0
        elif t_y > t[1]: return -1
        else: return 1

def NeedCut(trees,i):
    # how many trees ith tree needs to cut to be exposed
    # idea, try line i -- j for all j != i in trees, and figure out the min of points on the two sides
    s = trees[i]
    N = len(trees)
    mincut = []
    for j,t in enumerate(trees):
        if i == j: continue
        above = len([u for k,u in enumerate(trees) if (not k == i) and IsAbove(s,t,u)==1])
        below = len([u for k,u in enumerate(trees) if (not k == i) and IsAbove(s,t,u)==-1])
        #print 'above: %d; below: %d'%(above, below)
        mincut.extend([above, below])
    if not mincut: return 0
    else: return min(mincut)


T = int(sys.stdin.readline().strip('\n'))
for q in xrange(T):
    N = int(sys.stdin.readline().strip('\n'))
    trees = []
    for i in xrange(N):
        trees.append(tuple(map(int,sys.stdin.readline().strip('\n').split())))
    print 'Case #%d:'%(q+1)
    for i,t in enumerate(trees):
        print NeedCut(trees,i)


