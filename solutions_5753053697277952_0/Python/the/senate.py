input_file = "A-small-attempt0.in"
output_file = "result.out"

def majority(sen):
    sen_sum = sum(sen) / 2
    return any([x > sen_sum for x in sen])

with open(input_file) as in_file, open(output_file, 'w') as out_file:
    testcases = int(in_file.readline())
    for i in range(1, testcases + 1):
        p = int(in_file.readline())

        sen = [int(x) for x in in_file.readline().split()]
        sen_sum = sum(sen)

        res = []
        while sen_sum > 0:
            evac = ''
            index = 0
            max_val = 0
            for ind, s in enumerate(sen):
                if s > max_val:
                    max_val = s
                    index = ind

            evac += chr(index + 65)
            sen[index] -= 1
            sen_sum -= 1

            if majority(sen):
                index = 0
                max_val = 0
                for ind, s in enumerate(sen):
                    if s > max_val:
                        max_val = s
                        index = ind

                evac += chr(index + 65)
                sen[index] -= 1
                sen_sum -= 1

            res.append(evac)



        out_file.write('Case #{}: {}\n'.format(i, ' '.join(res)))
