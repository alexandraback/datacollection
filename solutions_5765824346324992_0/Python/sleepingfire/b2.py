import sys
from fractions import gcd

def solve(B, N, M):
    if N <= B:
        return N
    ll = lcm(M)
    mm = 0
    for i in range(B):
        mm += ll / M[i]
    if N > mm:
        N = N % mm
    if N == 0:
        N = mm
    return _solve(B, N, M)

def _solve(B, N, M):
    if N <= B:
        return N
    N = N - B
    Q = M[:]
    while N > 0:
        t = min(Q)
        A = []
        for i in range(B):
            Q[i] -= t
            if Q[i] == 0:
                A.append(i)
        for b in A:
            N -= 1
            Q[b] = M[b]
            if N == 0:
                return b+1
    
def lcm(M):
    num = 1
    for i in range(len(M)):
        num = num * M[i] / gcd(num, M[i])
    return num

def finished(t, M):
    num = 0
    for i in range(len(M)):
        num += t / M[i]
    return num

#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    T = int(in_file.readline())
    for case_num in range(T):
        B, N = [int(z) for z in in_file.readline().split()]
        M = [int(z) for z in in_file.readline().split()]
        num = solve(B, N, M)
        print "Case #{}: {}".format(case_num+1, num)

    in_file.close()
