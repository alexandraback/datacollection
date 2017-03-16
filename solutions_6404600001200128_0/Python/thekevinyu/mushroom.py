def solve_method_1(problem_input):
    """Solve if she can eat any amount at once"""
    eaten = 0
    for i in range(1, len(problem_input)):
        difference = problem_input[i] - problem_input[i-1]
        if difference < 0:
            eaten += abs(difference)
    return eaten


def solve_method_2(problem_input):
    """Solve if she must eat at a constant rate"""
    max_difference = 0
    for i in range(1, len(problem_input)):
        max_difference = max([max_difference, problem_input[i-1] - problem_input[i]])

    eaten = 0
    for i, mushrooms in enumerate(problem_input[:-1]):
        eaten += min(max_difference, mushrooms)
    return eaten


def solve(problem_input):
    return "%s %s" % (solve_method_1(problem_input), solve_method_2(problem_input))


def separate_problems(lines):
    # return map(lambda row: [int(x) for x in row.split()[1]], lines)
    return [map(int, row.split()) for row in lines[2::2]]


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
