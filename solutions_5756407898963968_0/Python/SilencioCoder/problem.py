
class Case(object):
    def __init__(self, lines):
        self.one = [lines[i].split(' ') for i in range(1, 5)][int(lines[0]) - 1]
        self.two = [lines[i].split(' ') for i in range(6, 10)][int(lines[5]) - 1]

    def solve(self):
        unique = set(self.one) & set(self.two)
        selected = [i for i in unique]
        
        result = len(selected)
        if result == 0:
            return 'Volunteer cheated!'
        elif result == 1:
            return selected[0]
        else:
            return 'Bad magician!'

def parse(input_lines):
    n_cases = int(input_lines.pop(0))
    cases = []

    for i in range(0, len(input_lines), 10):
        x = input_lines[i:i+10]
        if len(x) < 10:
            break
        cases.append(Case(x))

    return n_cases, cases

def solve(input_file):
    with open(input_file + '.in', 'r') as f:
        input_lines = f.read().split('\n')

    n_cases, cases = parse(input_lines)

    if n_cases != len(cases):
        raise ValueError('Unmatched cases!')

    solution = []

    for i in range(0, n_cases):
        answer = 'Case #%s: %s' % (i+1, cases[i].solve())
        solution.append(answer)

    with open(input_file + '.out', 'w') as f:
        for line in solution:
            f.write('%s\n' % line)

if __name__ == '__main__':
    solve('A-small-attempt0')
    #pass

