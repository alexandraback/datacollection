
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
    long long B, N;
    vector< long long> M;
    int y;

#ifdef CHECK_RESULTS
    int check_y;
#endif

     long long pass( long long t);

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

 long long TTestCase::pass( long long t)
{
     long long res = 0;
    for (int i = 0; i < B; ++i)
    {
        res += t / M[i];
    }
    return res;
}


void TTestCase::Run()
{
     long long T = 0;
    /*for (unsigned long long t = 0;; t += 1000000000)
    {
        if (pass(t) < N)
            T = t;
        else
            break;
    }
    for (unsigned long long t = T;; t += 1000000)
    {
        if (pass(t) < N)
            T = t;
        else
            break;
    }*/
    for ( long long t = T;; t += 1000)
    {
        if (pass(t) < N - B - 1)
            T = t;
        else
            break;
    }

    long long n = pass(T);

    for (int i = 0; i < B; ++i)
    {
        if (T % M[i] != 0)
        {
            ++n;
        }
    }

    for (long long t = T;; t += 1)
    {
        for (int i = 0; i < B; ++i)
        {
            if (t % M[i] == 0)
            {
                ++n;
                if (n == N)
                {
                    y = i + 1;
                    return;
                }
            }
        }
    }

}

void TTestCase::Load()
{
    cin >> B >> N;
    M.resize(B);
    for (int i = 0; i < B; ++i)
        cin >> M[i];
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
