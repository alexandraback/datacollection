import sys
import os
import math
import functools

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

def solve():
      
    B,N = map(int,In.readline().rstrip('\n').split(' '))
    M = [m for m in map(int,In.readline().rstrip('\n').split(' '))]
    multiple = M[0]
    for k in range(B-1):
           multiple = lcm(multiple,M[k+1])
    Subtract = 0
    for k in range(B):
        Subtract += int(multiple/M[k])
    print(Subtract)
    N = (N-1)%Subtract
    print(N)
    Occupied = [0 for m in M]
    Available = 0
    for i in range(N+1):
        Available = Occupied.index(min(Occupied))
        if Occupied[Available]!= 0:
            wait = Occupied[Available]
            for k in range(B):  
                Occupied[k] = Occupied[k]-wait
        Occupied[Available]+= M[Available]
        print(Occupied)
    return Available+1
            
        
        
    
    
        
if __name__ == '__main__':

    T = int(In.readline())
    for x in range(T):
        Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
