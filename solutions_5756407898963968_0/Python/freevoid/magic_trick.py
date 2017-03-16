import sys


def get_answer(test_case):
    selection1, cards1, selection2, cards2 = test_case
    variants1 = set(cards1[selection1 - 1])
    variants2 = cards2[selection2 - 1]
    answers = variants1.intersection(variants2)
    nanswers = len(answers)
    if nanswers == 1:
        return answers.pop()
    elif nanswers == 0:
        return 'Volunteer cheated!'
    else:
        return 'Bad magician!'


def read_matrix(fp, size=4, type_=int):
    matrix = []
    for i in range(size):
        matrix.append(map(type_, fp.readline().split(' ')))
    return matrix


def read_test_case(fp):
    selection1 = int(fp.readline())
    cards1 = read_matrix(fp)
    selection2 = int(fp.readline())
    cards2 = read_matrix(fp)
    return selection1, cards1, selection2, cards2


def read_input(path):
    with open(path) as fp:
        ncases = int(fp.readline())
        for i in range(ncases):
            yield read_test_case(fp)


def format_answer(n, answer):
    return 'Case #%d: %s' % (n, answer)


def main(input_path, output_path):
    with open(output_path, 'w') as out_fp:
        for i, test_case in enumerate(read_input(input_path)):
            out_fp.write(format_answer(i + 1, get_answer(test_case)))
            out_fp.write('\n')


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
