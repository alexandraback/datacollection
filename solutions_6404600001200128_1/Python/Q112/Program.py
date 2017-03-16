import sys
import os
import math

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

def solve():
      
    Intervals = int(In.readline())
    m = In.readline().rstrip('\n').split(' ')
    print(m)
    first = 0
    for k in range(len(m)-1):
        first += max(int(m[k])-int(m[k+1]),0)
        print(first)
    second = 0
    rate = max([int(m[k])-int(m[k+1]) for k in range(len(m)-1)])
    for k in range(len(m)-1):
        second += min(int(m[k]),rate)
    return '{} {}'.format(first,second) 
        
        
    
    
        
if __name__ == '__main__':

    T = int(In.readline())
    for x in range(T):
        Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
