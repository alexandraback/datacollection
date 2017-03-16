def work(case_vars):
    a1, b1, a2, b2 = case_vars

    s1 = set(b1[a1])
    s2 = set(b2[a2])

    res = s1.intersection(s2)

    return "Volunteer cheated!" if len(res) == 0 else list(res)[0] if len(res) == 1 else "Bad magician!"


def get_cases(f):
    #read num of cases
    cases = int(f.readline())
    for case in range(cases):
        #read first answer
        a1 = int(f.readline()) - 1
        b1 = [[int(i) for i in f.readline().split()] for _ in range(4)]

        #read second answer
        a2 = int(f.readline()) - 1
        b2 = [[int(i) for i in f.readline().split()] for _ in range(4)]

        yield case+1, a1, b1, a2, b2


def main():
    flag = 1

    input_name = "test.in" if flag == 0 else "A-small-attempt0.in"
    output_name = input_name[:-2] + "out"
    print input_name
    print output_name

    with open(input_name, 'rb') as in_file,  open(output_name, 'w') as out_file:
        for case_vars in get_cases(in_file):
            case = case_vars[0]
            c = work(case_vars[1:])
            out_file.write("Case #%d: %s" % (case, c) + "\n")


main()
