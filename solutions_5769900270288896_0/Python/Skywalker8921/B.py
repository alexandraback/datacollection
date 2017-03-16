import sys,math

# def main_small(R,C,N):
#     res = 0
#     pos = set()
#     for i in range(C):
#         if N == 0:
#             break
#         for j in range(R):
#             if N == 0:
#                 break
#             if (i-1,j) not in pos and (i,j-1) not in pos:
#                 pos.add((i,j))
#                 N -= 1
#     i=j=0
#     while N > 0 and i < C:
#         if (i,j) not in pos:
#             nres = (((i-1,j) in pos)
#                     + ((i+1,j) in pos)
#                     + ((i,j-1) in pos)
#                     + ((i,j+1) in pos))
#             print("Placing someone in {}, {} new walls".format((i,j),nres),
#                   file=sys.stderr)
#             pos.add((i,j))
#             res += nres
#             N -= 1
#         j += 1
#         if j == R:
#             j = 0
#             i += 1
#     return res

def main_small(R,C,N):
    if R > C:
        return main_small(C,R,N)
    elif R == 1:
        if C % 2 == 0:
            if N <= C//2 :
                return 0
            else:
                k = N - (C//2 + 1)
                return 2*k+1
        else:
            if N <= (C+1)//2:
                return 0
            else:
                k = N - (C+1)//2
                return 2*k
    elif R == 2:
        if N <= C:
            return 0
        elif N <= C+2:
            k = N-C
            return 2*k
        else:
            k = N-(C+2)
            return 4 + 3*k
    elif R == 3:
        if C == 3:
            if N <= 5:
                return 0
            elif N == 6:
                return 3
            elif N == 7:
                return 6
            elif N == 8:
                return 8
            else:
                return 12
        elif C == 4:
            if N <= 6:
                return 0
            elif N <= 8:
                return 2*(N-6)
            elif N == 9:
                return 8
            elif N == 10:
                return 10
            elif N == 11:
                return 13
            else:
                return 17
        else: # C == 5
            if N <= 8:
                return 0
            elif N <= 10:
                return 3*(N-8)
            elif N <= 11:
                return 8
            elif N <= 13:
                return 3*(N-11)+8
            elif N == 14:
                return 18
            else:
                return 22
    elif R == 4: ## C == 4
        if N <= 8:
            return 0
        elif N <= 10:
            return 2*(N-8)
        elif N <= 14:
            return 4+3*(N-10)
        else:
            return 16+4*(N-14)
    else:
        return None
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        R,C,N = [int(i) for i in input().split()]
        ## Processing
        print("Case #{}:".format(c+1),file=sys.stderr)
        res = main_small(R,C,N)
        ## Output
        print("Case #{}: {}".format(c+1,res))
        print("Case #{}: {}".format(c+1,res),file=sys.stderr)

