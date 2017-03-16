import sys


def solve_case(case, party_sizes):
    party_sizes = [(size, chr(ord('A') + i)) for i, size in enumerate(party_sizes)]
    exit_plan = []
    while len(party_sizes):
        party_sizes.sort()
        size, party = party_sizes.pop()
        if size > 1:
            party_sizes.append((size - 1, party))
        exit_plan.append(party)
    exit_plan_merged = []
    if len(exit_plan) % 2 == 1:
        exit_plan_merged.append(exit_plan.pop(0))
    for i in xrange(0, len(exit_plan), 2):
        exit_plan_merged.append(''.join(exit_plan[i:i + 2]))
    print 'Case #%d: %s' % (case, ' '.join(exit_plan_merged))

with open(sys.argv[1]) as fd:
    lines = [line.strip() for line in fd.readlines()]

for case in xrange(2, len(lines), 2):
    solve_case(case / 2, [int(party) for party in lines[case].split()])
