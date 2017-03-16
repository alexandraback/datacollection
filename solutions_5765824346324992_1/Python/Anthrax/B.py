#!/bin/env python3


def solution(B,N,M):
    #print([(i,sum([i//m for m in M])) for i in range(0,30)])  
    
    Tmax = N*(max(M)+1)
    Tmin = 0
    
    num = 0;
    
    while Tmax - Tmin > 1:
        T = (Tmax + Tmin) // 2
        num = sum([(T//m)+1 for m in M])
        
        if num < N:
            Tmin = T
        elif num >= N:
            Tmax = T

    T = Tmax
    num = sum([(T//m)+1 for m in M])
    A = [T%m for m in M]

    zeros = [i for i,a in enumerate(A) if a == 0]
    
    return zeros[len(zeros) - (num-N) - 1] + 1


#%% Main and input handling

def main():
    T = int(input())
    
    for t in range(T):
        do_case(t+1)

def do_case(t):
    B,N = [int(x) for x in input().split()]
    M = [int(x) for x in input().split()]
    
    print_case(t, solution(B,N,M))
    
def print_case(t,n):
    print("case #%d: %d" % (t,n))

if __name__ == "__main__":
    main()