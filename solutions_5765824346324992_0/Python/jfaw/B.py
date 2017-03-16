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
    N=int(problem[0].split(" ")[1])
    B=int(problem[0].split(" ")[0])
    time_variable=problem[1].split(" ")
    for i in xrange(len(time_variable)):
        time_variable[i]=int(time_variable[i])
    problem_variable=[]
    problem_variable.append(B)
    problem_variable.append(N)
    problem_variable.append(time_variable)
    solve(case_num, problem_variable)


def solve(case_num,problem_variable):
    B=problem_variable[0]
    N=problem_variable[1]

    time_variable=problem_variable[2]
    if (N<=B):
        print_ans(case_num, N)
        return
    total_speed=0
    for i in xrange (len(time_variable)):
        total_speed+=(1.0/time_variable[i])
    time =int((N-1)/total_speed)
    current=[0]*len(time_variable)
    #print N
    #print time
    position=0
    for i in xrange(len(time_variable)):
        n=time/time_variable[i]
        if (time>0 and n==0):
            n=1
        if n>1:
            n=n-1
        position+=n
        current[i]=n*time_variable[i]
    solution=-1
    for i in xrange(N-position):
        #print current

        a=min(current)
        if (a!=0):
            for j in xrange (len(current)):
                current[j]-=a
        for j in xrange(len(time_variable)):
                if (current[j]==0):
                    current[j]=time_variable[j]
                    solution=j+1
                    break


    print_ans(case_num, solution)

def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()
