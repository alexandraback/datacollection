from itertools import combinations

def compute(R,C,N):
    apartments = R*C
    l = []
    for combo in combinations(list(range(apartments)), N):
        s = 0
        for i in combo:
            if i % C and i-1 in combo:
                s += 1
            if i+C in combo:
                s += 1
        l.append(s)
    return min(l)


def read_number(f):
    return int(f.readline().strip())

def read_numbers(f):
    return map(int, f.readline().strip().split())

def main():
    with open('B-small-attempt0.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            R,C,N = read_numbers(f)
            print('Case #{}: {}'.format(test_case + 1, compute(R,C,N)))

if __name__ == '__main__':
    main()