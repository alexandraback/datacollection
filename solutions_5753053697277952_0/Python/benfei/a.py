#!/usr/bin/env python3
"""
Senate Evacuation
Code Jam 2016, Round 1C, Problem A

HOW TO USE:
#~: python a.py < input.in > output.out
"""

from string import ascii_uppercase


def evacuate(senators):
    parties = dict()
    remaining_senators = sum(senators)
    plan = []
    for party_num, party_letter in enumerate(ascii_uppercase[:len(senators)]):
        parties[party_letter] = senators[party_num]

    while remaining_senators > 2:
        party = max(parties, key=parties.get)
        step = party
        parties[party] -= 1
        remaining_senators -= 1
        if remaining_senators > 2:
            party, party_senators = max(parties.items(), key=lambda x: x[1])
            if 2 * party_senators > remaining_senators:
                step += party
                parties[party] -= 1
                remaining_senators -= 1
        plan.append(step)

    # handle when remaining senators <= 2
    remaining_parties = []
    for party_letter, party_senators in parties.items():
        remaining_parties += [party_letter] * party_senators
    plan.append("".join(remaining_parties))

    return plan


def handle_case():
    """Handle the IO of the case, and return the answer"""
    num_of_parties = int(input())
    senators = [int(x) for x in input().split(" ")]
    result = evacuate(senators)

    return result


def handle_result(result):
    """Parse the result into the required format"""
    return " ".join(result)


def main():
    """Get the number of cases, solve each case and print its result"""
    num_of_tests = int(input())

    # iterate over test cases
    for test_case in range(1, num_of_tests + 1):
        result = handle_case()
        printable_result = handle_result(result)
        print("Case #{}: {}".format(test_case, printable_result))


if __name__ == "__main__":
    main()
