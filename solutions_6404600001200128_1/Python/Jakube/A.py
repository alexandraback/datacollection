def read_number(f):
    return int(f.readline().strip())


def read_list(f):
    return list(map(int, f.readline().split()))


def min_mushrooms(mushrooms):
    # method 1:
    s1 = sum(i - j for i, j in zip(mushrooms, mushrooms[1:]) if i > j)

    # method 2:
    m = max([i - j for i, j in zip(mushrooms, mushrooms[1:]) if i > j] + [0])
    if m < 0: m = 0

    s2 = 0
    for i in mushrooms[:-1]:
        if i >= m:
            s2 += m
        else:
            s2 += i

    return s1, s2


def main():
    with open('A-large.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            n = read_number(f)
            mushrooms = read_list(f)
            s1, s2 = min_mushrooms(mushrooms)
            print('Case #{}: {} {}'.format(test_case + 1, s1, s2))

if __name__ == '__main__':
    main()
