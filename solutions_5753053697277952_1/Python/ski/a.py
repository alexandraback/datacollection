import sys
import logging

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger(__name__)


def solve(case):
    #case = {chr(ord('A') + i): n for i, n in enumerate(case)}
    log.info('Solving: %r', case)

    plan = []
    total = sum(case)
    partyn = len(case)
    
    while total > 1:
        a = max(case)
        ai = case.index(a)
        b = None
        bi = None

        case[ai] -= 1
        total -= 1

        if a == 1:
            partyn -= 1

        b = max(case)
        bi = case.index(b)

        assert b > 0  # last step must contain 2 party members, else error!

        if b > 1 or partyn != 2:
            case[bi] -= 1
            total -= 1
            if b == 1:
                partyn -= 1
            plan.append((ai, bi))
        else:
            plan.append((ai, ))

    return ' '.join([''.join(chr(ord('A') + i) for i in ni) for ni in plan])


        


def get_cases(lines):
    lines = [map(int, ln.split()) for ln in lines]

    for ln in lines[2::2]:
        yield ln


def main():
    lines = [ln.strip() for ln in sys.stdin]

    for i, case in enumerate(get_cases(lines), 1):
        result = solve(case)
        log.info('Case #%d: %s', i, result)
        print 'Case #%d: %s' % (i, result)


if __name__ == '__main__':
    main()

