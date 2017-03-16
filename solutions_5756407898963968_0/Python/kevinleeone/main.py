import sys

def solve():
    guess = int(sys.stdin.readline().split()[0])
    for i in range(guess - 1):
        sys.stdin.readline()

    first = set(map(int, sys.stdin.readline().split()))

    for i in range(4 - guess):
        sys.stdin.readline()

    guess = int(sys.stdin.readline().split()[0])
    for i in range(guess - 1):
        sys.stdin.readline()

    second = set(map(int, sys.stdin.readline().split()))

    for i in range(4 - guess):
        sys.stdin.readline()

    first &= second
    if len(first) == 1:
        return str(list(first)[0])
    elif len(first) == 0:
        return 'Volunteer cheated!'
    else:
        return 'Bad magician!'

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %s' % (i + 1, solve()))

