import sys

sys.stdin = open('A-small-attempt0.in', 'r')
sys.stdout = open('a.out', 'w')

for t in range(int(input())):

    k = int(input())
    r = [set(map(int, input().split())) for i in range(4)][k-1]

    k = int(input())
    r &= [set(map(int, input().split())) for i in range(4)][k-1]

    print('Case #%d: %s' % (
        t + 1,
        'Volunteer cheated!' if len(r) == 0
        else r.pop() if len(r) == 1
        else 'Bad magician!'
    ))

sys.stdin.close()
sys.stdout.close()