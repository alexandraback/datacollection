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
	const static int MAX_COST = 100000;
	int caseNum, caseIndex;
	int num, lineIndex;
	int cost[MAX_NUM];
	int result;
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
	scanf("%d%d", &num, &lineIndex);
	for(int i = 0; i < num; ++i)
		scanf("%d", cost + i);
}

void Solver::run()
{
	long long ed = ((long long)lineIndex) * MAX_COST;
	long long st = 0;
	while(st <= ed)
	{
		long long mid = (st + ed) >> 1;
		long long count = 0;
		for(int i = 0; i < num; ++i)
		{
			count += (mid / cost[i]) + 1;
		}
		if(count >= lineIndex)
		{
			ed = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
	}
	result = 0;
	vector<int> candidates;
	int finishedCount = 0;
	for(int i = 0; i < num; ++i)
	{
		if(st % cost[i] == 0)
		{
			candidates.push_back(i);
			finishedCount += st / cost[i];
		}
		else
		{
			finishedCount += st / cost[i] + 1;
		}
	}
	int index = lineIndex - finishedCount;
	result = candidates[index - 1] + 1;
}

void Solver::output()
{
	printf("Case #%d: %d\n", caseIndex, result);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\B.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\B.out", "w", stdout);
#endif

	instance.exe();
	return 0;
}

