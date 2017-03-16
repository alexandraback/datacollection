import numpy as np
def solve(N, P):
    print N, P 
    res = ""
    letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    Q = sum(P)
    
    while Q > 0: 
        idx = np.argmax(P, axis = 0)
        P[idx] -= 1;
        res += ' '+letters[idx]
        
        idx = np.argmax(P, axis = 0)
      #  print float(P[idx])/Q, P[idx], Q 
        if float(P[idx])/Q >= 0.5: 
            res += letters[idx]
            P[idx] -= 1
            
        Q  = sum(P)
        
        
        
    
    return res 


if __name__ == "__main__":
    #f = open('practice.in','r')

    f = open('A-large.in', 'r')

    w = open('A-large-1.out', 'w+')

    for t in xrange(int(f.readline())): 
        N = int(f.readline())
        P = map(int, f.readline().split(' '))
        
        res = 'Case #' + str(t+1) + ': ' + str(solve(N,P))
        print res 
        w.write(res+ "\n") 

    w.close() 