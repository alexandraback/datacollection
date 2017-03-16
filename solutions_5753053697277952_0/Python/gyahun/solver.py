from string import ascii_uppercase as uppers
from collections import namedtuple, Counter

Test = namedtuple('Test', 'S')

def read(line):
    return Test(Counter(dict(zip(uppers, map(int, line.split())))))

def solve(test):
    senators = Counter(test.S)
    evacuated = []
    while +senators:
        first = max(senators, key=senators.get)
        senators[first] -= 1
        if len(+senators) == 2 and all(n == 1 for n in (+senators).values()):
            evacuated.append(first)
        else:
            second = max(senators, key=senators.get)
            senators[second] -= 1
            evacuated.append(first + second)

    return ' '.join(evacuated)

if __name__ == '__main__':
    infile = 'A-small-attempt0.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[2::2]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
