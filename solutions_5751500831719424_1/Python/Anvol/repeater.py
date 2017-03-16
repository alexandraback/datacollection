def main():
    inp = open("input.txt", "r")
    out = open("output.txt", "w")
    test_count = int(splited_line(inp)[0])
    for x in xrange(1, test_count + 1):
        N = int(splited_line(inp)[0])
        lines = []
        for s in xrange(0, N):
            lines.append(inp.readline().strip('\r\n'))
        a = solve(lines)
        ans = "Case #%s: %s\n"
        print ans % (x, a)
        out.write(ans % (x, a))


def group_tuples(s):
    char = s[0]
    groups = []
    count = 1
    for x in xrange(1, len(s)):
        if s[x] == char:
            count += 1
        else:
            groups.append(count)
            char = s[x]
            count = 1
    groups.append(count)
    return groups


def distinct_chars(s):
    char = s[0]
    chars = s[0]
    for x in xrange(1, len(s)):
        if s[x] != char:
            chars += char
            char = s[x]

    return chars


def solve(lines):
    all_groups = [group_tuples(l) for l in lines]

    group_count = min([len(s) for s in all_groups])

    if len(set([distinct_chars(s) for s in lines])) > 1:
        return "Fegla Won"

    if group_count != max([len(s) for s in all_groups]):
        return "Fegla Won"

    steps = 0

    for i in xrange(0, group_count):
        diff = (all_groups[0][i]) - (all_groups[1][i])
        steps += abs(diff)

    return steps


def splited_line(f):
    return f.readline().strip('\r\n').split(' ')

if __name__ == '__main__':
    main()
