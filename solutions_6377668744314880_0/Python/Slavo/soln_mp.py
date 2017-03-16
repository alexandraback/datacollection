input_file = "C-large.in"
input_file = "sample_input.txt"
input_file = "C-small-attempt1.in"

from multiprocessing import Pool
from itertools import izip
from scipy.spatial import ConvexHull
import numpy as np


def line(f,_type=str):
    s = [_type(i) for i in f.readline().strip().split()]
    return s


##def f_star(bnL):
##    return f(*bnL)

def isBound(p,hull):
    for i in xrange(hull.nsimplex):
        i1 = hull.vertices[i]
        i2 = hull.vertices[(i+1)%hull.nsimplex]
        p1 = hull.points[i1]
        p2 = hull.points[i2]
        if (p[0]-p1[0])*(p[1]-p2[1]) == (p[1]-p1[1])*(p[0]-p2[0]):
            return True
    return False

def f(points):
    n = len(points)
    d = [None] * n
    try:
        hull = ConvexHull(points)
    except:
        return [0] * n
    hulls = [hull]
    val = 0
    while None in d:
        hullsNew = []
        for hull in hulls:
            for i in xrange(n):
                if d[i] == None:
                    if isBound(points[i],hull):
                        d[i] = val
                        if None not in d:
                            return d
            for i in hull.vertices:
                pointsNew = np.delete(hull.points, i, 0)
                try:
                    hullNew = ConvexHull(pointsNew)
                except:
                    print "CRITICAL ERROR"
                    pass
                hullsNew.append(hullNew)
        val += 1
        hulls = hullsNew
    return d

                
    

if __name__ == "__main__":
    with open(input_file) as fin:
        T = line(fin,int)[0]

        pointsList = []
        for case in range(1,T+1):
            n = line(fin,int)[0]
            points = []
            for i in xrange(n):
                points.append(line(fin,int))
            pointsList.append(points)

##    answers = []
##    for i in pointsList:
##        print len(i)
##        answers.append(f(i))

    pool = Pool()
    answers = pool.map(f,pointsList)

##    print answers

    with open('output_mp.txt','w') as fout:
        for i in range(len(answers)):
            case = i + 1
            answer = answers[i]
            s = "Case #%d:\n" % (case)
            for i in answer:
                s += "%d\n" % i
            print s,
            fout.write(s)
