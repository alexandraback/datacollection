import math


def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)


def lcmm(*args):
    """Return lcm of args."""
    return reduce(lcm, args)


def started_by_t(t, M):
    return sum(int(math.ceil(float(t)/k)) for k in M)


def solve(problem_input):
    B, N, M = problem_input
    barbers = range(1, B + 1)
    slowest = max(M)
    smallest_step = min(M)
    overall_rate = started_by_t(lcmm(*M), M)

    # start t just before we should be getting started
    t = ((N / overall_rate) * lcmm(*M))

    while True:
        started = started_by_t(t, M)
        openings = [not (t % k) for k in M]
        if started == N:
            t -= smallest_step
            continue
        if started + sum(openings) < N:
            t += 1
            continue
        else:
            # we started at time t. now to figure out which barber we had
            x = N - started
            for k, is_open in zip(barbers, openings):
                if is_open:
                    x -= 1
                if x == 0:
                    return k


def separate_problems(lines):
    problem_inputs = []
    problems = int(lines[0].strip())
    for i in range(1, (problems * 2) + 1, 2):
        B, N = map(int, lines[i].split())
        M = map(int, lines[i+1].split())
        problem_inputs.append((B, N, M))
    return problem_inputs


if __name__ == "__main__":
    import sys
    import os
    filename = sys.argv[1]
    with open(filename, "r") as inputfile:
        lines = inputfile.readlines()
    problem_inputs = separate_problems(lines)

    solution_rows = []
    for i, problem_input in enumerate(problem_inputs):
        solution_rows.append("Case #%s: %s" % (i + 1, solve(problem_input)))

    solution_filename = os.path.join("solutions",
        os.path.basename(filename) + ".solution")

    with open(solution_filename, "w+") as solutionfile:
        solutionfile.write("\n".join(solution_rows))
