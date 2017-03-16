import sys
import itertools




def processTest():
    LINE = [int(x) for x in f.readline()[:-1].split(' ')]
    R = LINE[0]
    C = LINE[1]
    N = LINE[2]

    minnoise = 100000000000
    for el in itertools.combinations(range(R*C),N):
        arr = [[0 for j in range(C)] for i in range(R)]
        for i in range(R):
            for j in range(C):
                if i+j*R in el:
                    arr[i][j] = 1
        #print(arr)
        def countNoise(arr):
            noiselvl = 0
            for i in range(R):
                for j in range(C):
                    if arr[i][j]>0:
                        if i<R-1 and arr[i+1][j]>0:
                            noiselvl +=1
                        if j<C-1 and arr[i][j+1]>0:
                            noiselvl +=1
            return noiselvl 
        noise = countNoise(arr)
        if noise<minnoise:
            minnoise = noise
    return minnoise

f = open(sys.argv[1],'r')
maxtests = int(f.readline())
testnum = 1
while testnum <= maxtests:
    y = processTest()
    print('Case #'+str(testnum)+': '+ str(y))
    testnum+=1

f.close()
