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

class A
{
private:
	int caseNum, caseIndex;
	int answers[2];
	int cards[2][4][4];
	int result;
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
};

void A::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void A::Input()
{
	for(int i = 0; i < 2; ++i)
	{
		scanf("%d", answers + i);
		for(int row = 0; row < 4; ++row)
		{
			for(int col = 0; col < 4; ++col)
			{
				scanf("%d", &cards[i][row][col]);
			}
		}
	}
}

void A::Do()
{
	int num = 0, count = 0;
	--answers[0]; --answers[1];
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if(cards[0][answers[0]][i] == cards[1][answers[1]][j])
			{
				num = cards[0][answers[0]][i];
				++count;
				break;
			}
		}
	}
	
	if(count == 0) result = -2;
	else if(count > 1) result = -1;
	else result = num;
}

void A::Output()
{
	printf("Case #%d: ", caseIndex);
	if(result == -2) printf("Volunteer cheated!\n");
	else if(result == -1) printf("Bad magician!\n");
	else printf("%d\n", result);
}

A instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
