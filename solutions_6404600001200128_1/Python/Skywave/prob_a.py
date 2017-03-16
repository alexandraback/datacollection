in_file = open('A-large.in', 'r')
out_file = open('out.txt', 'w')

total_case_count = int(in_file.readline())

for i in range(total_case_count):
    case_length = int(in_file.readline())
    mushrooms = [int(x) for x in in_file.readline().split()]
    diff = list()

    method_a = 0
    method_b = 0
    max_diff = 0

    for j in range(case_length - 1):
        diff.append(mushrooms[j] - mushrooms[j + 1])
        max_diff = max(max_diff, diff[-1])

    for j in diff:
        if j > 0:
            method_a += j

    for j in range(case_length - 1):
        method_b += min(mushrooms[j], max_diff)

    out_file.write('Case #{}: {} {}\n'.format(i + 1, method_a, method_b))

in_file.close()
out_file.close()