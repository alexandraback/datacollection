import sys
import itertools

def get_groups(s):
    return [(c, len(list(g))) for c, g in itertools.groupby(s)]

def is_constant(l):
    return len(list(itertools.groupby(l))) <= 1

def solve(data):
    groups = [get_groups(s) for s in data]
    lengths = [len(group) for group in groups]
    if not is_constant(lengths):
        return "Fegla Won"
    cols = zip(*groups)
    result = 0
    for col in cols:
        chars = [c for (c, l) in col]
        if not is_constant(chars):
            return "Fegla Won"
        counts = [l for (c, l) in col]
        target = int(round(1.0 * sum(counts) / len(counts)))
        for count in counts:
            result += abs(count - target)
    return result

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        data = []
        N = int(sys.stdin.readline())
        for i in range(N):
            data.append(sys.stdin.readline().strip())
        result = solve(data)
        print "Case #%d: %s" % (t + 1, result)

if __name__ == '__main__':
    main()
