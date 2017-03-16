import sys

t = int(sys.stdin.readline().strip())
for i in range(t):
    sys.stdout.write("Case #%d:" % (i + 1))    
    n = int(sys.stdin.readline().strip())

    p = map(int, sys.stdin.readline().strip().split())

    while sum(p) > 0:
        sys.stdout.write(" ")

        parties = 0
        for j in range(n):
            if p[j] > 0:
                parties += 1

        for k in range(1 if parties > 2 else 2):
            m = -1
            for j in range(n):
                if ((m == -1) or (p[j] > p[m])):
                    m = j
            
            sys.stdout.write("%s" % chr(65 + m))
            p[m] -= 1

    sys.stdout.write("\n")

