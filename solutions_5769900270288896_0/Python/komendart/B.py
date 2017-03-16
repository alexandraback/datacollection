def solve(r, c, n):
    S = r * c
    result = float("inf")
    for mask in range(1 << S):
        table = [[0 for i in range(c + 2)] for j in range(r + 2)]
        k = 0
        for i in range(S):
            if mask & (1 << i):
                table[1 + i // c][1 + i % c] = 1
                k += 1
        if k == n:
            k = 0
            for i in range(1, r + 1):
                for j in range(1, c + 1):
                    if table[i][j]:
                        if table[i - 1][j]: k += 1
                        if table[i][j - 1]: k += 1
            result = min(result, k)
    return result
                

def main():
    with open("input.txt") as fin, open("output.txt", 'w') as fout:
        t = int(fin.readline())
        for i in range(1, t + 1):
            r, c, n = [int(i) for i in fin.readline().split()]
            print("Case #{0}: {1}".format(i, solve(r, c, n)), file=fout)
    
main()
