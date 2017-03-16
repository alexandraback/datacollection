import sys
dirs = [[1,0],[0,-1],[-1,0],[0,1]]

def count(i):
    total = 0
    for c in range(16):
	    if ((1<<c) & i) != 0:
	        total += 1
    return total

def countUnHap(r, c, i):
    res = 0
    for x in range(c):
    	for y in range(r):
            if((1 << (y * c + x)) & i) == 0:
    			continue
            for d in dirs:
                nX = x + d[0]
                nY = y + d[1]
                if 0 <= nX < c and 0 <= nY < r:
        	        p = nY * c + nX
        	        if ((1<<p) & i) != 0:
        	            res += 1
   
    return res/2
        	  
def solve(r, c, n):
	
    minHap = 100000000
    for i in range(2**(r*c)):
	    if count(i) == n:
		    minHap = min(minHap, countUnHap(r, c, i))
    return minHap



if __name__ == '__main__':
    first = True
    idx = 1

    for line in sys.stdin:
        if first: 
            first = False
            T = int(line.strip())
        elif T > 0:
            nums = line.strip().split()
            R, C, N = int(nums[0]), int(nums[1]), int(nums[2])
            T -= 1
            print "Case #%d: %d"%(idx, solve(R,C,N))
            idx += 1

        else:
        	break