parties = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def is_safe(p):
    threshold = sum(p) // 2 + 1
    return all(pp < threshold for pp in p)

with open('A-small-attempt0 (1).in') as file_in, open('A.out', 'w') as file_out:
    lines = file_in.readlines()
    cases = int(lines[0])

    i = 1
    for case in range(1, cases + 1):
        n = int(lines[i])
        p = list(map(int, lines[i + 1].split()))
        i += 2

        result = []
        while sum(p) > 0:
            max_p = max(p)
            to_go = p.index(max_p)
            p[to_go] -= 1

            new_max = max(p)
            next_to_go = p.index(new_max)
            p[next_to_go] -= 1
            if is_safe(p):
                result.append(parties[to_go] + parties[next_to_go])
            else:
                result.append(parties[to_go])
                p[next_to_go] += 1

        file_out.write('Case #{}: {}\n'.format(case, ' '.join(result)))