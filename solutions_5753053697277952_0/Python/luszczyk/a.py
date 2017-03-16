import string


def read_ints():
    return map(int, input().strip().split())


def test_case(tab):
    parties = list(zip(tab, string.ascii_uppercase))
    parties.sort(reverse=True)
    result = []
    diff = parties[0][0] - parties[1][0]
    result += parties[0][1] * diff
    parties[0] = (parties[0][0] - diff, parties[0][1])
    for party in parties[2:]:
        result += [party[1]] * party[0]
    result += [parties[0][1] + parties[1][1]] * parties[0][0]
    return result


def verify(inp, result):
    orig_inp = inp[:]
    for pair in result:
        for party in pair:
            num = ord(party) - ord('A')
            inp[num] -= 1
        assert max(inp) <= sum(inp) / 2., "{}, {}, {}".format(orig_inp, inp, result)


assert test_case([2, 2]) == ["BA", "BA"]
assert test_case([3, 2, 2]) == ["A", "B", "B", "AC", "AC"]
assert test_case([2, 2, 4]) == ["C", "C", "A", "A", "CB", "CB"]


def main():
    T, = read_ints()
    for t in range(T):
        n, = read_ints()
        tab = list(read_ints())
        ans = test_case(tab)
        verify(tab, ans)
        print("Case #{}: {}".format(t + 1, " ".join(ans)))


if __name__ == "__main__":
    main()