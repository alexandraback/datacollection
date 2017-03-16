#!/usr/bin/python
# print repr(st)
# maze = [[['#' for i in range(N+2)] for i in range(M+2)] for i in range(4)]
# (M, N) = map(int, f.readline().split())
# l = f.readline()


def doit():
    (r,c,n) = map(int, raw_input().split())
    if r < c:
        (r,c) = (c,r)
    
    if c == 1:
        uh = r-1
        uh -= 2*(r-n)
        if uh < 0:
            uh = 0
        return uh
                
    if c == 2:
        n -= r
        if n <= 0:
            return 0
        if n == 1:
            return 2
        if n == 2:
            return 4
        return 3*n - 2
    
    if c == 3:
        if r == 3:
            if n <= 5:
                return 0
            if n == 6:
                return 3
            if n == 7:
                return 6
            if n == 8:
                return 8
            if n == 9:
                return 12
                
        if r == 4:
            if n <= 6:
                return 0
            n -= 6
            if n <= 2:
                return 2*n
            if n <= 5:
                return 3*n - 2
            return 17
            
        if r == 5:
            if n <= 8:
                return 0
            free = 15 - n
            if free == 0:
                return 22
            if free == 1:
                return 18
            if free == 2:
                return 14
            if free == 3:
                return 11
            if free == 4:
                return 8
            if free == 5:
                return 6
            if free == 6:
                return 4
            if free == 7:
                return 2
            if free == 8:
                return 0
                
    if n <= 8:
        return 0
        
    free = 16-n
    if free == 0:
        return 24
    if free == 1:
        return 20
    if free == 2:
        return 16
    if free == 3:
        return 13
    if free == 4:
        return 10
    if free == 5:
        return 7
    if free == 6:
        return 4
    if free == 7:
        return 2
    if free == 8:
        return 0
    
    

cases = input()
for case in range(1, cases+1):
    print ("Case #" + str(case) + ":"), doit()
