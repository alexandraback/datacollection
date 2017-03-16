import sys


def how_many_eaten(a, b):
    eaten = a - b
    return eaten if eaten > 0 else 0


def eat_with_fist_strategy(mushrooms):
    last_mushroom = 0
    eaten = 0
    for mushroom in mushrooms:
        eaten += how_many_eaten(last_mushroom, mushroom)
        last_mushroom = mushroom
    return eaten


def eat_with_second_strategy_(mushrooms):
    max_eaten = max(map(lambda ab: ab[0] - ab[1], zip(mushrooms[:-1], mushrooms[1:])))
    eaten = 0
    for mushroom in mushrooms[:-1]:
        if mushroom > max_eaten:
            eaten += max_eaten
        else:
            eaten += mushroom
    return eaten


def solve_case(mushrooms, case_number):
    print "Case #%d: %d %d" % (case_number, eat_with_fist_strategy(mushrooms), eat_with_second_strategy_(mushrooms))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        r.readline()  # Skip how many mushrooms which is not necessary.
        mushrooms = map(int, r.readline().strip().split(' '))
        solve_case(mushrooms, case_number)


if __name__ == '__main__':
    main()