def solve(n, p):
    total = sum(p)
    moves = []

    if n == 2:
        while p[0] > p[1]:
            moves.append('A')
            p[0] -= 1
        while p[0] < p[1]:
            moves.append('B')
            p[0] -= 1
        while p[0] > 0:
            moves.append('AB')
            p[0] -= 1

        return ' '.join(moves)

    while total > 0:
        max_ind = 0
        max_val = p[0]
        for i, e in enumerate(p):
            if e > max_val:
                max_ind, max_val = i, e

        for i, e in enumerate(p):
            if i == max_ind:
                continue

        p[max_ind] -= 1
        total -= 1
        moves.append(chr(ord('A') + max_ind))

    moves[-2] += moves[-1]
    moves = moves[:-1]
    return ' '.join(moves)

def main():
    T = int(input())
    for case_num in range(1, T + 1):
        n = int(input())
        p = list(map(int, input().split()))
        print("Case #{0}: {1}".format(case_num, solve(n, p)))

main()
