#!/bin/env python3

def solution(N,P):
    a = 0;
    for i in range(1,len(P)):
        if P[i-1]>P[i]:
            a += P[i-1]-P[i]
    
    M = max([P[i-1]-P[i] for i in range(1,len(P))])
    
    b = 0
    for i in range(0,len(P)-1):
        b += min(M,P[i])
    
    return a,b


#%% Main and input handling

def main():
    T = int(input())
    
    for t in range(T):
        do_case(t+1)

def do_case(t):
    N = int(input())
    P = [int(x) for x in input().split()]
    
    a,b = solution(N,P)
    print_case(t, a, b)
    
def print_case(t,a,b):
    print("case #%d: %d %d" % (t,a,b))

if __name__ == "__main__":
    main()