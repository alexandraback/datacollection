__author__ = 'User'
import string

PARTY_NAMES = string.ascii_uppercase


def make_order(list_of_members):
    empty_members = 0
    order = []
    while sum(list_of_members) > 0:
        party = list_of_members.index(max(list_of_members))
        letter = PARTY_NAMES[party]
        list_of_members[party] -= 1
        if list_of_members[party] == 0:
            empty_members += 1
        if len(list_of_members) - empty_members == 1 or len(list_of_members) == 2:
            party = list_of_members.index(max(list_of_members))
            letter += PARTY_NAMES[party]
            list_of_members[party] -= 1
            if list_of_members[party] == 0:
                empty_members += 1
        order.append(letter)
    return order


with open("file_name.txt", "r") as file:
    with open("result.txt", "w") as write_file:
        for i, line in enumerate(file):
            if i == 0 or i % 2 == 1:
                continue
            input_list = line.strip().split(' ')
            x = make_order([int(j) for j in input_list])
            write_file.write("Case #" + str(i//2) + ": " + " ".join(x) + "\n")