__author__ = 'rycus'

# Problem A: Senate Evacuation

FILENAME = 'res/2016_r1c_a.small'
OUTPUT_FILE = '%s.out' % FILENAME


def solve(n, p):
    plan = []

    while any(p[pid] > 0 for pid in p):
        largest = find_largest_parties(p)

        if len(largest) % 2 == 1:
            lid, _ = largest[0]

            if p[lid] > 1:
                p[lid] -= 2
                plan.append(lid * 2)

            else:
                p[lid] -= 1
                plan.append(lid)

        else:
            lid1, _ = largest[0]
            lid2, _ = largest[1]

            p[lid1] -= 1
            p[lid2] -= 1

            plan.append('%s%s' % (lid1, lid2))

    return ' '.join(plan)


def find_largest_parties(p):
    max_members = 0
    parties = []

    for pid, party in p.items():
        if party > max_members:
            parties = [(pid, party)]
            max_members = party

        elif party == max_members:
            parties.append((pid, party))

    return parties


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                N = int(input_file.readline().strip())
                P = {(chr(ord('A') + ID)): int(num) for ID, num in enumerate(input_file.readline().split())}
                result = solve(N, P)

                print 'Case #%d: %s' % (case, result)
                print >> output_file, 'Case #%d: %s' % (case, result)
