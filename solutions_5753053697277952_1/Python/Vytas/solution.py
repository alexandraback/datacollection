import argparse
import itertools
import multiprocessing
import sys
import time


def global_solve(index):
    """A dirty way to get around pickling limitations when multiprocessing."""
    return global_solve.instance.solve_single(index)


class Problem(object):
    """
    A simple helper class for parsing Google Code Jam problem inputs and
    formatting solutions.

    It also allows paralellizing tasks by multiprocessing in order to work
    around Python's limited (due to GIL) threading.

    (C) Vytautas Liuolia 2016
    """

    SAMPLE = None

    def __init__(self):
        self.cases = []

    def parse_case(self, lines):
        raise NotImplementedError

    def solve(self, case):
        raise NotImplementedError

    def solve_single(self, index):
        start = time.time()
        result = str(self.solve(self.cases[index]))
        elapsed = time.time() - start
        return result, elapsed

    def read_cases(self, lines=None):
        if lines is None:
            lines = (line.strip() for line in sys.stdin)
        amount = int(lines.next())
        for index in xrange(amount):
            self.cases.append(self.parse_case(lines))

    def solve_all(self, processes=None, verbose=False):

        indices = xrange(len(self.cases))
        processes = processes or multiprocessing.cpu_count()

        if processes > 1:
            global_solve.instance = self
            pool = multiprocessing.Pool(processes=processes)
            results = pool.imap(global_solve, indices)
        else:
            results = itertools.imap(self.solve_single, indices)

        for index, (result, elapsed) in enumerate(results):
            if verbose:
                message = "Solved case #{0} in {1} s\n".format(
                    index + 1, round(elapsed, 6))
                sys.stderr.write(message)
                sys.stderr.flush()
            print "Case #{0}: {1}".format(index + 1, result)
            sys.stdout.flush()

    @classmethod
    def main(cls):
        parser = argparse.ArgumentParser(
            description='Reads Code Jam problem input and outputs solutions.')
        parser.add_argument(
            '-s', '--sample', action='store_true',
            help='run the predefined sample instead of input')
        parser.add_argument(
            '-v', '--verbose', action='store_true',
            help='print progress information in stderr')
        parser.add_argument(
            '-p', '--processes', type=int, default=0,
            help='amount of processes to use (default: CPU count)')
        args = parser.parse_args()

        lines = None
        if args.sample:
            if cls.SAMPLE is None:
                raise NotImplementedError
            lines = iter(cls.SAMPLE.splitlines())

        problem = cls()
        problem.read_cases(lines)
        problem.solve_all(processes=args.processes, verbose=args.verbose)


class Solution(Problem):

    SAMPLE = """4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1"""

    def solve(self, case):

        def evacuate(counts):
            choices = {}
            parties = [None] + counts.keys()

            for first in parties:
                for second in parties:
                    if first is None and second is None:
                        continue
                    if first == second:
                        if counts[first] < 2:
                            continue
                    if first:
                        if counts[first] < 1:
                            continue
                    if second:
                        if counts[second] < 1:
                            continue

                    plan = ''.join(sorted([first or '', second or '']))
                    if plan in choices:
                        continue

                    after = counts.copy()
                    for party in plan:
                        after[party] -= 1
                    values = sorted(after.itervalues(), reverse=True)
                    total = sum(after.itervalues())
                    if total == 0:
                        return plan
                    violation = values[0] * 2 > total
                    choices[plan] = (violation, values, plan)

            best = min((value, key) for key, value in choices.iteritems())
            assert not best[0][0]
            return best[1]

        counts = {chr(ord('A') + index): count
                  for index, count in enumerate(case)}
        result = []
        while sum(counts.itervalues()) > 0:
            plan = evacuate(counts)
            result.append(plan)
            for party in plan:
                counts[party] -= 1
        return ' '.join(result)

    def parse_case(self, lines):
        parties = int(lines.next())
        counts = tuple(map(int, lines.next().split()))
        assert parties == len(counts)
        return counts


if __name__ == '__main__':
    Solution.main()
