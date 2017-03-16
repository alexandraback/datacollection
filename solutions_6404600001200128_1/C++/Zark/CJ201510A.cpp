#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <memory>

#pragma comment(linker, "/STACK:104857600,104857600")

using namespace std;

//#define FILE_IO

class Solver
{
public:
	void exe();
	
private:
	void input();
	void run();
	void output();
	
private:
	const static int MAX_NUM = 1000;
	int caseNum, caseIndex;
	int num;
	int count[MAX_NUM];
	int result0, result1;
};

void Solver::exe()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		input();
		run();
		output();
	}
}

void Solver::input()
{
	scanf("%d", &num);
	for(int i = 0; i < num; ++i)
		scanf("%d", count + i);
}

void Solver::run()
{
	result0 = 0;
	int rate = 0;
	for(int i = 1; i < num; ++i)
	{
		int delta = count[i - 1] - count[i];;
		if(delta < 0) delta = 0;
		result0 += delta;
		rate = max(rate, delta);
	}
	
	result1 = 0;
	for(int i = 0; i < num - 1; ++i)
	{
		result1 += min(rate, count[i]);
	}
}

void Solver::output()
{
	printf("Case #%d: %d %d\n", caseIndex, result0, result1);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\A.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\A.out", "w", stdout);
#endif

	instance.exe();
	return 0;
}

