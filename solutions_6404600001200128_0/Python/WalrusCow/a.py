import sys

def test():
    ''' Return y, z for first method, second method of mushroom eating. '''
    sys.stdin.readline()
    mushrooms = list(map(int, sys.stdin.readline().strip().split()))

    y = 0
    # First method
    for diff in map(lambda x: x[0] - x[1], zip(mushrooms, mushrooms[1:])):
        if diff > 0: y += diff

    z = 0
    # Second method
    rate = max(map(lambda x: x[0] - x[1], zip(mushrooms, mushrooms[1:])))
    for m in mushrooms[:-1]:
        if m < rate:
            z += m
        else:
            z += rate

    return y, z


def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        y, z = test()
        print('Case #{}: {} {}'.format(i+1, y, z))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
