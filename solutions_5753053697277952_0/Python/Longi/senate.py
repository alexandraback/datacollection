#!/usr/bin/python3

import sys


def main():
    with open(sys.argv[1]) as input_file:
        content = [line.strip('\n') for line in input_file.readlines()]

    case_count = int(content[0])

    with open('output', 'w') as output_file:
        for case_number in range(1, case_count + 1):
            party_count = content[case_number * 2 - 1]
            member_count = content[case_number * 2].split(' ')

            # Do computations here
            result = evacuation_plan(int(party_count), [int(i) for i in member_count])

            output_file.write('Case #' + str(case_number) + ": " + result + '\n')


def evacuation_plan(party_count, member_count):
    plan = ""
    member_count = member_count[:party_count]

    while (not member_count.count(member_count[0]) == len(member_count)):
        index = member_count.index(max(member_count))
        plan += chr(ord('A') + index) + " "
        member_count[index] -= 1

    for i in range(2, party_count):
        while (member_count[i] > 0):
            plan += chr(ord('A') + i) + " "
            member_count[i] -= 1

    while (member_count[0] > 0):
        plan += chr(ord('A')) + chr(ord('B')) + " "
        member_count[0] -= 1
        member_count[1] -= 1

    return plan


if __name__ == '__main__':
    main()
