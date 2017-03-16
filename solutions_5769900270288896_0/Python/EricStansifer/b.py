from common import *

def main(casenum):
    r, c, n = readints()

    if r == 1 or c == 1:
        r = max(r, c)

        if r % 2 == 0:
            A = r // 2
            B = 1
            C = r - A - B

            un = 0
            n -= A
            if n > 0:
                un += 1 * min(n, B)
                n -= B
                if n > 0:
                    un += 2 * n
        else:
            A = (r + 1) // 2
            B = 0
            C = r - A - B

            un = 0
            n -= A
            if n > 0:
                un += 2 * n

        writecase(casenum, un)
        return

    def compute_un(A, B, C, D, n):
        u = 0
        n -= A
        if n <= 0:
            return u
        u += 2 * min(n, B)
        n -= B
        if n <= 0:
            return u
        u += 3 * min(n, C)
        n -= C
        if n <= 0:
            return u
        u += 4 * n
        return u

    if (r * c) % 2 == 0:
        A = (r * c) // 2
        B = 2
        C = r + c - 4
        D = r * c - A - B - C

        un = compute_un(A, B, C, D, n)

    else:
        A1 = (r * c + 1) // 2
        B1 = 0
        C1 = r + c - 2
        D1 = r * c - A1 - B1 - C1

        un1 = compute_un(A1, B1, C1, D1, n)

        A2 = (r * c - 1) // 2
        B2 = 4
        C2 = r + c - 6
        D2 = r * c - A2 - B2 - C2

        un2 = compute_un(A2, B2, C2, D2, n)

        un = min(un1, un2)

    writecase(casenum, un)

run(main)
