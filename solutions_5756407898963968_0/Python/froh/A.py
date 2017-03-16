#!/usr/bin/env python3

# (C) 2014 Susanne Oberhauser-Hirschoff
# The MIT License applies: http://opensource.org/licenses/MIT

# Google codejam 2014
# Problem A. Magic Trick

from codejam_2014 import *

class X: pass
class Codejam_2014_A(Codejam_2014):
    def parse_one_problem_set(self):
        # one problem set consists of two identical blocks
        x = X()
        x.answer_1, x.rows_1 = self.parse_one_answer()
        x.answer_2, x.rows_2 = self.parse_one_answer()
        return x

    def parse_one_answer(self):
        answer = int(self.file.readline()) - 1
        rows = []
        for i in range(4):
            line = self.file.readline()
            row = [int(x) for x in line.split()]
            rows.append(row)
        return answer, rows

    def solve_problem(self, problem):
        # The program has just to _test_ a solution.
        # 
        # The intersection of the two rows named by the candidate needs to be
        # classified:
        #   empty -> cheater
        #   one element -> solution
        #   more than one in intersection  -> bad magician
        row_1 = problem.rows_1[problem.answer_1]
        row_2 = problem.rows_2[problem.answer_2]
        common = set(row_1).intersection(row_2)
        if len(common) == 0:
            solution = 'Volunteer cheated!'
        elif len(common) == 1:
            solution = common.pop()
        else:
            solution = 'Bad magician!'

        return solution

    def str_solution(self, solution):
        return str(solution)

if __name__ == "__main__":
    import sys
    a = Codejam_2014_A()
    a.run(sys.argv[1])
