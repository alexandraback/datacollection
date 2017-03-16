import argparse
from collections import defaultdict

def solve(case):
    '''
    Returns the solution 
    '''
    case1, case2 = case
    first_row = case1['rows'][case1['selected']]
    second_row = case2['rows'][case2['selected']]
    intersect = set(first_row)&set(second_row)
    if len(intersect) == 1:
        return str(intersect.pop())
    elif len(intersect) > 1:
        return "Bad magician!"
    else:
        return "Volunteer cheated!"
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        num_cases = int(inp.readline())
        for idx in range(num_cases):
            case = []
            for x in range(2):
                rows = []
                selected = int(inp.readline()) - 1
                for _ in range(4):
                    rows.append([int(x) for x in inp.readline().split()])
                case.append({
                    'selected': selected,
                    'rows': rows
                    })
            result = solve(case)
            solutions.append("Case #{0}: {1}".format(idx+1, result))
        pass
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
