import sys
import os


def problem_specific_parser(src):
    num_parties = int(next(src))
    num_delegates = [int(e) for e in next(src).split(' ')]
    return num_parties, num_delegates


def valid(delegates):
    num_delegates = sum([n for n, _ in delegates])
    majority = num_delegates // 2 + 1

    has_majority = [n >= majority for n, _ in delegates]
    negative = [n < 0 for n, _ in delegates]
    return sum(has_majority) == 0 and sum(negative) == 0


def solve(data):
    num_parties, delegates = data
    delegates = [(e, chr(i + ord('A'))) for i, e in enumerate(delegates)]

    sequence = []
    num_delegates = sum([n for n, _ in delegates])

    while num_delegates > 0:
        delegates = sorted(delegates, reverse = True)

        delegates[0] = (delegates[0][0] - 2, delegates[0][1])
        if valid(delegates):
            num_delegates -= 2
            sequence.append("{}{}".format(delegates[0][1], delegates[0][1]))
            continue

        delegates[0] = (delegates[0][0] + 1, delegates[0][1])
        if valid(delegates):
            num_delegates -= 1
            sequence.append("{}".format(delegates[0][1]))
            continue

        delegates[1] = (delegates[1][0] - 1, delegates[1][1])
        if valid(delegates):
            num_delegates -= 2
            sequence.append("{}{}".format(delegates[0][1], delegates[1][1]))
            continue

        assert(False)

    return " ".join(sequence)

def parse(src):
    lines = iter(src.split(os.linesep))
    nproblems = int(next(lines))

    for problem in range(nproblems):
        yield problem_specific_parser(lines)


def main():
    src = sys.stdin.read()
    for i, data in enumerate(parse(src)):
        print("Case #{0}: {1}".format(i + 1, solve(data)))

    
if __name__ == '__main__':
    main()
