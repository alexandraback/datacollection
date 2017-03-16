from fractions import gcd


def read_number(f):
    return int(f.readline().strip())


def read_list(f):
    return list(map(int, f.readline().split()))


def lcm(a, b):
    return a * b // gcd(a, b)

def computation(B, N, M):
    # compute lcm

    l = 1
    for i in M:
        l = lcm(l, i)

    tmp = [l // i for i in M]
    N = N % sum(tmp)
    if N == 0:
        N = sum(tmp)


    idx = 0
    current = [0] * B
    for i in range(N):
        mi = min(current)
        idx = current.index(mi)
        current = [val - mi for val in current]
        current[idx] = M[idx]

    return idx + 1


def main():
    with open('B-small-attempt0.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            #do stuff
            B, N = read_list(f)
            M = read_list(f)
            output = computation(B, N, M)
            print('Case #{}: {}'.format(test_case + 1, output))
            #print()

if __name__ == '__main__':
    main()
