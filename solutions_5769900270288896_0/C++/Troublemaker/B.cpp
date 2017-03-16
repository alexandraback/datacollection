
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdint.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "B"
//#define DATASET "practice"
//#define CHECK_RESULTS
#define DATASET "small"
//#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET ".in.txt");
ofstream fsOut(TASKNUM "-" DATASET ".out.txt");

class TTestCase
{
private:
    int R, C, N;
    int y;

    vector<vector<bool>> f;

    int go(int N, int i, int j);
    int evaluate();

#ifdef CHECK_RESULTS
    int check_y;
#endif

    void Load();
    void Init();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
{
    Load();
    Init();
    Run();
}

int TTestCase::evaluate()
{
   int res = 0;
   for(int i = 0; i < R; ++i)
   {
      for(int j = 0; j < C - 1; ++j)
         if(f[i][j] && f[i][j + 1])
            ++res;
   }
   for(int j = 0; j < C; ++j)
   {
      for(int i = 0; i < R - 1; ++i)
         if(f[i][j] && f[i+1][j])
            ++res;
   }
   return res;
}

int TTestCase::go(int N, int i, int j)
{
   if(N == 0)
      return evaluate();
   if(j == C)
      return go(N, i + 1, 0);
   if(i == R)
      return R*C*4;
   f[i][j] = true;
   int res1 = go(N - 1, i, j + 1);
   f[i][j] = false;
   int res2 = go(N, i, j + 1);
   return min(res1, res2);
}

void TTestCase::Run()
{
   y = 0;
   if(N == 0)
      return;
   if(R * C / N >= 2)
      return;
   f.resize(R);
   for(int i = 0; i < R; ++i)
   {
      f[i].resize(C);
      fill(f[i].begin(), f[i].end(), false);
   }
   y = go(N, 0, 0);
}

void TTestCase::Load()
{
    cin >> R >> C >> N;
#ifdef CHECK_RESULTS
    cin >> check_y;
#endif
}

void TTestCase::Init()
{
}

TTestCase::~TTestCase()
{
//    cout << std::fixed << std::setprecision(10) << X << endl;
//    fsOut << std::fixed << std::setprecision(10) << X << endl;
    cout << y;
#ifdef CHECK_RESULTS
    cout << "  " << check_y;
#endif
    cout << endl;
    fsOut << y;
    fsOut << endl;

}

void TTestCase::Print()
{
#ifndef PRINT
    return;
#endif
}








int main()
{
    if(!fsIn.is_open())
    {
        cout << "No input file found";
    }
    cin.rdbuf( fsIn.rdbuf() );

    int numberOfCases;
    cin >> numberOfCases;

    for( int caseNum = 1; caseNum <= numberOfCases; ++caseNum )
    {
        TTestCase testCase;

        
        cout << "Case #" << caseNum << ": ";
        fsOut << "Case #" << caseNum << ": ";
    }
	
    cout << "Finished";
    for(;;);
    return 0;
}
