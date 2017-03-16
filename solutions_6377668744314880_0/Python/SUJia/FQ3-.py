import numpy as np
from scipy.spatial import ConvexHull
import matplotlib.pyplot as plt

    
    

#f = open('input', 'r')
#fr = open('output', 'w')
f = open('C-small-attempt2.in', 'r')
fr = open('C-small-attempt2.out', 'w')

line = f.readline()
#print line
ntot = int(line.split()[0])
for nline in range(ntot):
    line = f.readline()
    nPoints = int(line.split()[0])
    coords = np.zeros((nPoints,2))
    res = np.zeros(nPoints)
    
    for j in range(nPoints):
        line = f.readline()
        coords[j,0], coords[j,1] = map(int, line.split()[:])
    
    for i in range(nPoints):
            # find line connecting point i and another point
        res[i] = nPoints
        for j in range(i) + range(i+1, nPoints):
            #slope = 0
            #if abs(coords[j,0] - coords[i,0]) < 0.000001:
            #    slope = 1000000
            #else:
            slope = (coords[j,1] - coords[i,1]) / (coords[j,0] - coords[i,0])
            # line: y = slope * (x - coords[j,0]) + coords[j,1]
            nPos = 0
            nZero = 0
            nNeg = 0
            for k in range(nPoints):
                if abs(slope *  (coords[k,0] - coords[j,0]) + coords[j,1] - coords[k,1]) < 0.000001:
                    nZero = nZero + 1
                elif slope *  (coords[k,0] - coords[j,0]) + coords[j,1] - coords[k,1] > 0.000001:
                    nPos = nPos + 1
                else:
                    nNeg = nNeg + 1
            res[i] = min(res[i], nPos, nNeg)

        
    ''' 
    plt.plot(coords[:,0], coords[:,1], 'o')
    for simplex in hull.simplices:
        plt.plot(coords[simplex,0], coords[simplex,1], 'k-')
    
    plt.xlim((-5,15))
    plt.ylim((-5,15))
    plt.show()
    '''
    
    fr.write('Case #' + str(nline+1) + ':\n')
    for i in range(nPoints):
        fr.write(str(int(res[i])) + '\n')       
        
f.close()
fr.close()