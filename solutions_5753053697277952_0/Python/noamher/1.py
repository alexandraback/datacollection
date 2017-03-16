import copy
import sys

################################################################################
import collections, operator

def solve(case_inputs):
    N, parties = case_inputs

    res = []
    party_info = [[int(parties[i]), chr(ord('A') + i)] for i in range(len(parties))]
    party_info = sorted(party_info)
    party_info.reverse()

    while party_info[0][0] > 0:
        if len(party_info) <= 1 or party_info[1][0] < party_info[0][0]:
            res.append(party_info[0][1])
            party_info[0][0] -= 1

        elif len(party_info) <= 2 or party_info[2][0] < party_info[1][0]:
            res.append(party_info[1][1] + party_info[0][1])
            party_info[1][0] -= 1
            party_info[0][0] -= 1

        else:
            res.append(party_info[0][1])
            party_info[0][0] -= 1

        party_info = sorted(party_info)
        party_info.reverse()

    return " ".join(res)


################################################################################

def read_case(f):
    N = read_int(f)
    parties = read_ints(f)
    return N, parties

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    return [reader(f, *args, **kwargs) for _ in range(R)]

def main():
    if len(sys.argv) != 2:
        print 'usage: python <file_name> <input_file>'
        sys.exit(1)

    with open(sys.argv[1], 'r') as f, open('res', 'w') as w:
        count = read_int(f)
        for i in xrange(1, count + 1):
            case_inputs = read_case(f)
            write_case(w, i, solve(case_inputs))

if __name__ == "__main__":
    main()


