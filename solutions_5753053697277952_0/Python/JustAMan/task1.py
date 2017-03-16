import sys

A_NUM = ord('A')
def index2party(*idx):
    return ''.join(chr(A_NUM + x) for x in idx)

def solve(p):
    plan = []
    while any(x > 0 for x in p):
        idx1, _ = max(enumerate(p), key=lambda (i, v): v)
        p[idx1] -= 1
        idx2, _ = max(enumerate(p), key=lambda (i, v): v)
        p[idx2] -= 1
        if 2 * max(p) > sum(p):
            # cannot take second step
            p[idx2] += 1
            plan.append(index2party(idx1))
        else:
            plan.append(index2party(idx1, idx2))
    return ' '.join(plan)

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            N = int(inp.readline().strip())
            P = [int(x) for x in inp.readline().strip().split()]
            out.write('Case #%d: %s\n' % (t + 1, solve(P)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
