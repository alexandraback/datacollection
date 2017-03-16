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
    num_of_lines=1

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
    problem=problem[0].split(" ")
    problem_variable=[]
    for i in xrange(len(problem)):
        problem_variable.append(int(problem[i]))
    solve(case_num, problem_variable)

def solve(case_num,problem_variable):
    R=min(problem_variable[0:2])
    C=max(problem_variable[0:2])
    N=problem_variable[2]

    solution=-1;
    if R*C==1:
        solution=1
    else:
        area=R*C
        if N<=((area+1)/2):
            solution=0
        else:
            if R==1:
                solution=(N-((area+1)/2))*2
                if area%2==0:
                    solution-=min(1,N-((area+1)/2))
            if R==2:
                solution=(N-((area+1)/2))*3
                solution-=min(2,N-((area+1)/2))
            if R==3:
                if area==9 and N==8:
                    solution=8
                else:
                    keliling=(R+C)*2-4
                    part2=2 if (area%2==0) else 0
                    part3=(keliling+1)/2-part2
                    part4=area-part2-part3
                    n=N-((area+1)/2)
                    if n<=part2:
                        solution=2*n
                    elif n<=part2+part3:
                        solution=2*part2
                        n-=part2
                        solution+=n*3
                    else :
                        solution=2*part2+3*part3
                        n-=(part2+part3)
                        solution+=n*4
            if R==4:
                keliling=(R+C)*2-4
                part2=2 if (area%2==0) else 0
                part3=(keliling+1)/2-part2
                part4=area-part2-part3
                n=N-((area+1)/2)
                if n<=part2:
                    solution=2*n
                elif n<=part2+part3:
                    solution=2*part2
                    n-=part2
                    solution+=n*3
                else :
                    solution=2*part2+3*part3
                    n-=(part2+part3)
                    solution+=n*4
    #print R,C,N
    print_ans(case_num, solution)












def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()