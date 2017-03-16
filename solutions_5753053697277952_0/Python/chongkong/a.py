import sys

sys.stdout = open('output.txt', 'w')


class Party(object):
    def __init__(self, party_name, party_size):
        self.party_size = party_size
        self.party_name = party_name

    def __str__(self):
        return '<{} {}>'.format(self.party_name, self.party_size)

    def __repr__(self):
        return self.__str__()


def pick(parties):
    choice = parties[0]
    if choice.party_size <= 1:
        parties.remove(choice)

    choice.party_size -= 1
    return choice.party_name


def pick_two(parties):
    parties = sorted(parties, key=lambda x: x.party_size, reverse=True)
    choice1 = pick(parties)
    parties = sorted(parties, key=lambda x: x.party_size, reverse=True)
    choice2 = pick(parties)

    if len(parties) == 1:
        parties.append(Party(choice2, 1))
        choice2 = None

    return parties, choice1, choice2


def solve(party_sizes):
    party_names = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    parties = []
    for i in range(len(party_sizes)):
        party = Party(party_names[i], party_sizes[i])
        parties.append(party)

    ans = []
    while len(parties) > 0:
        parties, a, b = pick_two(parties)
        ans.append(a + b if b is not None else a)
    return ' '.join(ans)


def main():
    t = int(input())
    for i in range(t):
        party_count = input()
        party_sizes = list(map(int, input().split()))
        ans = solve(party_sizes)
        print('Case #{}: {}'.format(i + 1, ans))


main()
