import sys
import Queue

def fragment(string):
    parts = []
    for a in string:
        if not parts or a != parts[-1][0]:
            parts.append(a)
        else:
            parts[-1] += a
    return parts

def process(strings):
    parts = []

    # a | bb | c
    for string in strings:
        parts.append(fragment(string))

    lengths = map(len, parts)
    if len(set(lengths)) != 1:
        return None

    initials = map(lambda x: tuple(map(lambda y: y[0], x)), parts)
    if len(set(initials)) != 1:
        return None

    lengths = map(lambda x: tuple(map(len, x)), parts)
    average = [
        sum([
            length[i] for length in lengths
        ]) / len(parts)
        for i in range(len(parts[0]))
    ]

    steps = 0
    for length in lengths:
        for i in range(len(length)):
            steps += abs(length[i] - average[i])

    return steps

def main():
    cases = int(sys.stdin.readline())

    for case in range(cases):
        N = int(sys.stdin.readline())
        strings = []
        for _ in range(N):
            strings.append(sys.stdin.readline().strip())

        steps = process(strings)
        if steps is not None:
            print 'Case #%d: %s' % (case + 1, steps)
        else:
            print 'Case #%d: Fegla Won' % (case + 1)

if __name__ == '__main__':
    main()
