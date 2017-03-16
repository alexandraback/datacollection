import sys

def evacuate(parties, senators):
    alphas = [chr(ord('A') + i) for i in xrange(26)]
    total = sum(senators)
    ret = []
    for i in xrange(total):
        for j in xrange(parties):
            if senators[j] > 0:
                ret.append(alphas[j])
                senators[j] -= 1

    ret2 = []
    while (ret):
        if len(ret) == 3:
            ret2.append(ret.pop())
        else:
            r = ret.pop(), ret.pop()
            ret2.append("".join(r))
    return " ".join(ret2)


if __name__ == "__main__":
    output_file = open("%s.%s" % (sys.argv[1].split(".")[0], "out"), "w")
    file_name = sys.argv[1]
    input_file = open(file_name)
    case_count = int(input_file.readline())
    for i in xrange(case_count):
        parties = int(input_file.readline().strip())
        senators = map(int, input_file.readline().strip().split())
        result = evacuate(parties, senators)
        output_file.write("Case #%s: %s\n" % (i+1, result))

    output_file.close()
    input_file.close()
    print "Done!"

