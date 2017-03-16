import string

def find_first_largest(parties):
    return parties.index(max(parties))

def solve_step(parties):
    ix = find_first_largest(parties)
    parties[ix] -= 1
    out1 = string.ascii_uppercase[ix]
    if max(parties) > 0:
        if sum(parties) == 2:
            out2 = ""
        else:
            ix = find_first_largest(parties)
            parties[ix] -= 1
            out2 = string.ascii_uppercase[ix]
    else:
        out2 = ""
    return out1 + out2


def solve(parties):

    out = []
    while max(parties) > 0:
        out.append(solve_step(parties))

    return " ".join(out)


def main():
    n_tests = int(input())

    

    for ix_t in range(1, n_tests+1):
        n_parties = int(input())
        parties = input().split()
        parties = [int(x) for x in parties]
        print("Case #{}: {}".format(ix_t, solve(parties)))

if __name__ == "__main__":
    main()
