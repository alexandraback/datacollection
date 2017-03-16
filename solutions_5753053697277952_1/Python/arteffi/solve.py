from heapq import heapify, heappush, heappop
INPUT_PATH = 'large.in'

def main():
    test_cases = parse_input(INPUT_PATH)
    solutions = []
    for i, test_case in enumerate(test_cases):
        print('-' * 10)
        print('Test case', i)
        solution = solve(test_case)
        print(test_case, '->', solution)
        solutions.append(solution)
    output_solutions(solutions)


def parse_input(path):
    test_cases = []
    with open(path) as f:
        n = int(f.readline())
        for i in range(n):
            parties = int(f.readline())
            counts = [int(c) for c in f.readline().split()]
            test_cases.append(counts)
    return test_cases


def output_solutions(solutions):
    with open('output', 'w') as f:
        for i, solution in enumerate(solutions, 1):
            f.write('Case #{i}: {result}\n'.format(i=i, result=' '.join(solution)))


def solve(counts):
    counts = list(zip([-c for c in counts], [chr(ord('A') + n) for n in range(26)]))
    heapify(counts)
    solution = []
    while counts:
        step = one_turn(counts)
        solution.append(step)
    return solution


def one_turn(counts):
    count1, party1 = heappop(counts)
    # case 1: only one party left
    if not counts:
        add_if_any_left(counts, count1 + 1, party1)
        return party1
    # case 2: two parties left
    count2, party2 = heappop(counts)
    if not counts:
        add_if_any_left(counts, count1 + 1, party1)
        add_if_any_left(counts, count2 + 1, party2)
        return party1 + party2
    # case 3: (1, 1, 1)
    count3, party3 = heappop(counts)
    if not counts and (count1 == count2 == count3 == -1):
        heappush(counts, (count2, party2))
        heappush(counts, (count3, party3))
        return party1
    # case 4: (>1, anything, anything, ...)
    add_if_any_left(counts, count1 + 1, party1)
    add_if_any_left(counts, count2 + 1, party2)
    heappush(counts, (count3, party3))
    return party1 + party2


def add_if_any_left(counts, count, party):
    if count != 0:
        heappush(counts, (count, party))


if __name__ == '__main__':
    main()
