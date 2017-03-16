from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in range(num):
        B, N = map(int, r.next().split(" "))
        M = map(int, r.next().split(" "))

        if N <= B:
            ans.append(N)
            continue

        t = 1
        while calcNum(M, t) < N:
            t *= 2

        left, right = t/2, t
        while right - left > 1:
            mid = (left + right)/2
            if calcNum(M, mid) < N:
                left = mid
            else:
                right = mid

        ans.append(getAns(M, N, left, right))


    write("output", ans)

def getAns(M, N, l, r):
    diff = N - calcNum(M, l)
    for i in range(len(M)):
        m = M[i]
        if r % m == 0:
            diff -= 1
        if diff == 0:
            return i + 1

# Calculates the number of people that have began a haircut up to time t
def calcNum(M, t):
    return sum([1 + (t / m) for m in M])

if __name__ == '__main__':
    main()
