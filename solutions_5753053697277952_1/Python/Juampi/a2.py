#!/usr/bin/env python3

"""
Google Code Jam
Round 1B 2016
Problem A
"""

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

class TestCase:
    def __init__(self, n, s):
        self.n = n
        self.s = s
    def solve(self):
        evac = []
        while sum(self.s):
            turn = ""
            for idx, p in enumerate(self.s):
                if 2*p >= sum(self.s):
                    turn += letters[idx]
                    self.s[idx] -= 1
            if turn == "":
                for idx, p in enumerate(self.s):
                    if self.s[idx] > 0:
                        turn += letters[idx]
                        self.s[idx] -= 1
                        break
            evac.append(turn)
        return " ".join(evac)
        

def read_data(filename):
    with open(filename) as f:
        test_cases = []
        num_test_cases = int(f.readline())
        for _ in range(num_test_cases):
            n = int(next(f))
            s = [int(x) for x in next(f).split()]
            test_case = TestCase(n, s)
            test_cases.append(test_case)
    return num_test_cases, test_cases

if __name__ == "__main__":
    num_test_cases, test_cases = read_data("A-large.in")
    for it in range(num_test_cases):
        test_case = test_cases[it]
        print("Case #{}:".format(it + 1), test_case.solve())