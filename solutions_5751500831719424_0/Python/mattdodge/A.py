
def out(case_num, st):
    print("Case #%d: %s" % (case_num, st))


def get_min_string(st):
    out_st = ""
    prev_c = "*"
    for c in st:
        if c == prev_c:
            continue

        prev_c = c
        out_st += c

    return out_st


def get_diff(st, target_st):
    target_st_pos = 0
    out_list = [-1 for i in range(len(target_st))]
    for x in st:
        if x != target_st[target_st_pos]:
            target_st_pos += 1
        out_list[target_st_pos] += 1

    return out_list


def get_score(string_scores, st_length):
    score = 0
    for i in range(st_length):
        # which letter we are working on
        score += min([sum([abs(x[i] - offset) for x in string_scores])
                     for offset in range(101)])

    return score


def run_case(case_num, input):
    N = int(input.readline())
    strings = [input.readline().rstrip("\n") for i in range(N)]

    min_strings = set([get_min_string(x) for x in strings])

    if len(min_strings) != 1:
        out(case_num, "Fegla Won")
        return

    target_st = min_strings.pop()

    string_scores = [get_diff(x, target_st) for x in strings]
    out(case_num, get_score(string_scores, len(target_st)))


# GCJ boiler plate...call run_case for each case given
if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    with sys.stdin as f:
        [run_case(i + 1, f) for i in range(int(f.readline()))]
