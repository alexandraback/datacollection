
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "A"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    int Result1;
    int Result2;

	int A1, A2;
	int C1[4][4];
	int C2[4][4];

    void Load();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
{
	Load();

    Run();
}

void TTestCase::Load()
{
    cin >> A1;
	FOR(i,0,4)
		FOR(j,0,4)
		{
			cin >> C1[i][j];
		}
    cin >> A2;
	FOR(i,0,4)
		FOR(j,0,4)
		{
			cin >> C2[i][j];
		}
}

void TTestCase::Run()
{
	Result1 = 0;
	Result2 = 0;
	set<int> set;
	FOR(i, 0, 4)
		set.insert(C1[A1-1][i]);

	FOR(i, 0, 4)
		if( set.count(C2[A2-1][i]) )
		{
			if(Result1 != 0)
			{
				Result2 = 1;
			}
			else
			{
				Result1 = C2[A2-1][i];
			}
		}

	if(Result1 == 0)
	{
		Result2 = 2;
	}
}


TTestCase::~TTestCase()
{
	switch(Result2)
	{
	case 0:
		cout << Result1 << endl;
		fsOut << Result1 << endl;
		break;
	case 1:
		cout << "Bad magician!" << endl;
		fsOut << "Bad magician!" << endl;
		break;
	case 2:
		cout << "Volunteer cheated!" << endl;
		fsOut << "Volunteer cheated!" << endl;
	}
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
