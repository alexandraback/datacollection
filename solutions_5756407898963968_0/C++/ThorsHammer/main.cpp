#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>

////////////////////////////////////////////////////////////
// Input
// Output
////////////////////////////////////////////////////////////

namespace
{
    static std::ofstream &GetOut()
    {
        static std::ofstream C_OUT("out.txt", std::ofstream::out);
        return C_OUT;
    }

    static std::ifstream &GetIn()
    {
        static std::ifstream C_IN;
        return C_IN;
    }
}

////////////////////////////////////////////////////////////
// Problem specific data
////////////////////////////////////////////////////////////

typedef std::vector<int> RowNbs;

////////////////////////////////////////////////////////////
// Problem
////////////////////////////////////////////////////////////

class Problem
{
public:
    Problem();
    ~Problem();

    const std::string& getSolution();
private:
    int         r_rowNb;
    RowNbs      r_row1;
    RowNbs      r_row2;
    std::string r_solution;

    void solveProblem();
};

Problem::Problem() 
 : r_rowNb(-1),
   r_row1(),
   r_row2(),
   r_solution("")
{
    //would read the problem data from input file
    GetIn() >> r_rowNb;
    int value = -1;
    std::cout << "row: " << r_rowNb << std::endl;
    for(int rowCount = 1; rowCount <= 4; ++rowCount)
    {
        for(int lineCount = 0; lineCount < 4; ++lineCount)
        {
            GetIn() >> value;

            if(rowCount == r_rowNb)
            {
                std::cout << value << " ";
                r_row1.push_back(value);
            }
        }

        
    }
    std::cout << "\n";

    GetIn() >> r_rowNb;
    std::cout << "row: " << r_rowNb << std::endl;
    for(int rowCount = 1; rowCount <= 4; ++rowCount)
    {
        for(int lineCount = 0; lineCount < 4; ++lineCount)
        {
            GetIn() >> value;

            if(rowCount == r_rowNb)
            {
                std::cout << value << " ";
                r_row2.push_back(value);
            }
        }

        
    }
    std::cout << "\n";
}

Problem::~Problem()
{
}

const std::string& Problem::getSolution()
{
    solveProblem();
    return r_solution;
}

void Problem::solveProblem()
{
    int nbOfMatches = 0;
    int solution = 0;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(r_row1[i] == r_row2[j])
            {
                solution = r_row1[i];
                ++nbOfMatches;
            }
        }
    }

    if(0 == nbOfMatches)
    {
        r_solution = "Volunteer cheated!";
    }else if(1 == nbOfMatches)
    {
        r_solution = std::to_string(solution);
    }else
    {
        r_solution = "Bad magician!";
    }
}
////////////////////////////////////////////////////////////
// Test case
////////////////////////////////////////////////////////////

class TestCase
{
public:
    TestCase(int iCaseNumber)
    {
        std::cout << "\t\t -- Process Test Case: " << iCaseNumber 
            << " --"<<std::endl;

        auto solution = Problem().getSolution();

        std::cout << "Case #" << iCaseNumber << ": "
            << solution.c_str() << std::endl;

        GetOut() << "Case #" << iCaseNumber << ": "
            << solution.c_str() << std::endl;
    }
    ~TestCase(){}
};

////////////////////////////////////////////////////////////
// The problem solver
////////////////////////////////////////////////////////////

class ProblemSolver
{
public:
    ProblemSolver(const std::string &iInputFile)
    {
        GetIn().open(iInputFile, std::ifstream::in);

        if(false == GetIn().good())
        {
            std::cout << "read file failed\n";
            return;
        }
        else
        {
            int nbOfTestCases = 0;
            GetIn() >> nbOfTestCases;

            std::cout << "Test cases: " << nbOfTestCases << std::endl;

            for(int i = 1; i <= nbOfTestCases; ++i)
            {
                TestCase t(i);
            }
        }
    }

    ~ProblemSolver() 
    {
        GetIn().close();
        GetOut().close();
    }

private:
};

void readInput();
void openOutput();
void findItems(TestCase testCase);
void closeOutput();

////////////////////////////////////////////////////////////
// main function
////////////////////////////////////////////////////////////

void main()
{
    //ProblemSolver("test.txt");
    ProblemSolver("A-small-attempt2.in");
    //ProblemSolver("A-large-practice.in");
    getchar();
}
