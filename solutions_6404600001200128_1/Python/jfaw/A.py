import math
import sys

def print_ans(case_num,solution):
    print("Case #"+str(case_num)+":"),
    print_solution(solution)

def print_solution(solution):
    """TO DO"""
    print solution

def input_processor(filename):
    f=open(filename)
    data=f.read().split("\n")
    case_nums=int(data[0])

    """Insert number of lines per test case here"""
    num_of_lines=2

    """Edit start_index here"""
    start_index=1
    case_num=1
    
    """constant line num"""
    for i in xrange(0,case_nums):
        start=(i*num_of_lines)+start_index
        problem=data[start:start+num_of_lines]
        process_input_case(case_num,problem)
        case_num+=1

    """ non constant line num"""

    """
    cur_line=start_index
    for i in xrange(0,case_nums):
        num_of_lines=
        start=
        problem=data[start:start+num_of_lines]
        process_input_case(case_num,problem)
        case_num+=1
        cur_line=start+num_of_lines
    """


def process_input_case(case_num,problem):
    """Process raw input into apropriate type"""
    problem_variable=problem[1].split(" ")
    for i in xrange(len(problem_variable)):
        problem_variable[i]=int(problem_variable[i])
    solve(case_num, problem_variable)

def solve(case_num,problem_variable):
    sol1=0
    sol2=0
    maxdiff=0
    for i in xrange(len(problem_variable)-1):
        diff=problem_variable[i]-problem_variable[i+1]
        if (diff>0):
            sol1+=diff
            if diff>maxdiff:
                maxdiff=diff
    #speed=int(math.ceil(maxdiff/10.0))
    for i in xrange (len(problem_variable)-1):
        eaten= min(problem_variable[i],maxdiff)
        sol2 += eaten
    solution=str(sol1)+" "+str(sol2)
    print_ans(case_num, solution)


def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()
