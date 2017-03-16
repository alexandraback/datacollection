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
	const static int MAX_STR_NUM = 100;
	const static int MAX_STR_LEN = 100;
	int caseNum, caseIndex;
	int num;
	char words[MAX_STR_NUM][MAX_STR_LEN + 1];
	pair<char, int> parts[MAX_STR_NUM][MAX_STR_LEN];
	int partLen[MAX_STR_NUM];
	int counts[MAX_STR_NUM];
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
	scanf("%d", &num);
	for(int i = 0; i < num; ++i)
		scanf("%s", words[i]);
}

void A::Do()
{
	for(int i = 0; i < num; ++i)
	{
		partLen[i] = 0;
		char pre = 0;
		for(char *p = words[i]; *p; ++p)
		{
			if(*p == pre)
			{
				++parts[i][partLen[i] - 1].second;
			}
			else
			{
				parts[i][partLen[i]] = pair<char, int>(*p, 1);
				++partLen[i];
			}
			pre = *p;
		}
		if(i > 0)
		{
			if(partLen[i] != partLen[0])
			{
				result = -1;
				return;
			}
			for(int j = 0; j < partLen[0]; ++j)
			{
				if(parts[i][j].first != parts[0][j].first)
				{
					result = -1;
					return;
				}
			}
		}
	}
	
	result = 0;
	int len = partLen[0];
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < num; ++j)
		{
			counts[j] = parts[j][i].second;
		}
		sort(counts, counts + num);
		int mid = counts[num >> 1];
		for(int j = 0; j < num; ++j)
		{
			result += abs(counts[j] - mid);
		}
	}
}

void A::Output()
{
	printf("Case #%d: ", caseIndex);
	if(result < 0) printf("Fegla Won\n");
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
