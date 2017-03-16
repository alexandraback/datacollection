import sys

def solve(fin):
    n = int(fin.readline())
    A = list(map(int, fin.readline().split()))
    x = y = sp = cur = 0
    for i in range(1, n):
        x += max(0, A[i - 1] - A[i])
        sp = max(sp, A[i - 1] - A[i])
    cur = 0
    for i in range(0, n):
        y += min(cur, sp)
        cur -= min(cur, sp)
        cur = A[i]
    print(x, y)

def main():
    fin = open("input.txt", "r")

    T = int(fin.readline())
    for _T in range(1, T + 1):
        print("Case #" + str(_T) + ": ", end = "")
        solve(fin)

    fin.close()

main()