import sys

# sys.stdin = open('b.in', 'r')
sys.stdin = open('B-small-attempt2.in', 'r')
sys.stdout = open('B-small-attempt2-1.out', 'w')
# sys.stdin = open('B-large-practice.in', 'r')
# sys.stdout = open('B-large-practice.out', 'w')


for t in range(int(input())):

    R, C, N = map(int, input().split())

    result = (R-1)*C + R*(C-1)

    for M in range(1 << R*C):
        cnt = sum([1 if c == '1' else 0 for c in bin(M)[2:]])
        if cnt != N:
            continue
        ans = 0
        for i in range(R):
            for j in range(C):
                if M & (1 << (i*C+j)):
                    if j > 0 and M & (1 << i*C+j-1):
                        ans += 1
                    if i > 0 and M & (1 << (i-1)*C+j):
                        ans += 1
        result = min(result, ans)

    print('Case #%d: %d' % (t + 1, result))

sys.stdin.close()
sys.stdout.close()