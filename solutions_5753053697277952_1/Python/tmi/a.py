""" LIMITS:
    for i in xrange(100):
        for j in xrange(100):
            do_something(i, j)
    Binary search
"""

import unittest
import sys
from collections import Counter

problem_name = 'A'
attempt = None
attempt = '0'
attempt = 'L'
# attempt = 'p'
# attempt = 'P'


class TestSolveIt(unittest.TestCase):

    def test(self):
        self.assertEqual("A A B C A BC", solve_it("3 2 2"))
        self.assertEqual("AB", solve_it("1 1"))
        self.assertEqual("AB AB", solve_it("2 2"))
        self.assertEqual("C C AB", solve_it("1 1 2"))
        self.assertEqual("BA BB CA", solve_it("2 3 1"))


def pop_one(senators, non_zero_senators):
    closest = max(senators)
    closest_p = [idx for idx, p in enumerate(senators) if p == closest][0]
    senators[closest_p] -= 1
    if senators[closest_p] == 0:
        non_zero_senators.remove(closest_p)
    return closest_p


def solve_it(senators_str):
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    senators = senators_str.split(" ")
    senators = [int(s) for s in senators]
    non_zero_senators = {x for x in xrange(len(senators))}
    evacuation = ""

    remaining = sum(senators)
    while remaining:
        evacuation += " "
        if remaining == 2:
            first = non_zero_senators.pop()
            senators[first] -= 1
            second = non_zero_senators.pop()
            senators[second] -= 1
            evacuation += letters[first]
            evacuation += letters[second]
            remaining = sum(senators)
            break

        if len(non_zero_senators) == 1:
            # shouldn't happen
            import ipdb; ipdb.set_trace()

        closest_p = pop_one(senators, non_zero_senators)
        remaining = sum(senators)
        evacuation += letters[closest_p]

        # is there majority?
        closest = max(senators)
        closest_p = [idx for idx, p in enumerate(senators) if p == closest][0]
        if 2 * senators[closest_p] > remaining:
            closest_p = pop_one(senators, non_zero_senators)
            remaining = sum(senators)
            evacuation += letters[closest_p]

    return evacuation[1:]

# MAIN


if __name__ == '__main__':
    if attempt is None:
        unittest.main()
    else:
        if attempt == 'L':
            file_name = '%s-large' % problem_name
        elif attempt == 'p':
            file_name = '%s-small-practice' % problem_name
        elif attempt == 'P':
            file_name = '%s-large-practice' % problem_name
        else:
            file_name = '%s-small-attempt%s' % (problem_name, attempt)
        dir_path = __file__.rsplit('/', 1)[0]

        with open('%s/%s.in' % (dir_path, file_name), 'r') as cases_in:
            with open('%s/%s.out' % (dir_path, file_name), 'w') as cases_out:
                total_cases = int(cases_in.next()[:-1])

                # NEXT LINES ARE SPECIFIC

                for case_number in xrange(total_cases):
                    _ = cases_in.next()
                    senators = cases_in.next()[:-1]
                    out = solve_it(senators)
                    case_output = 'Case #%s: %s' % (case_number + 1, out)
                    print senators
                    print case_output
                    cases_out.write('%s\n' % case_output)
