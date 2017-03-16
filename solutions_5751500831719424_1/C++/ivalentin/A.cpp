#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}
/*

typedef struct
{
	int dist;
	int length;
} vine;

vine v[10000];
int d;
int pos;
int n;
typedef pair<int, int> State;
map<State, int> dp;

int travel(int cpos, int cv)
{
	State s = make_pair(cpos,cv);
	if (dp.find(s) != dp.end())
	{
		return 0;
	}
}
*/

char* str[100];
int strl[100];
int comp[100][100];

void append(char* s, char c)
{
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

char* reduce(int index, int len)
{
	int charCpt = 0;
	comp[index][charCpt] = 0;
	
	char* s = str[index];

	char* res = (char*)malloc(len * sizeof(char));
	memset(res, '\0', len);

	char lastChar = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != lastChar)
		{
			append(res, s[i]);
			lastChar = s[i];
			comp[index][charCpt]++;
			charCpt++;
			comp[index][charCpt] = 0;
		}
		else
		{
			comp[index][charCpt - 1]++;
		}
	}
	return res;
}



int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	for (int i = 0; i <= 100; i++)
	{
		str[i] = (char*)malloc(100 * sizeof(char));
	}

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1; case_id<=testcase; case_id++)
	{
		int nbStrings;
		int res = 0;
		int bestRes = 0;
		int total = 0;

		printf("Case #%d: ",case_id);

		scanf("%d", &nbStrings);
		for (int i = 0; i < nbStrings; i++)
		{
			scanf("%s", str[i]);
			strl[i] = strlen(str[i]);
		}

		char* red = reduce(0, strl[0]);
		for (int i = 1; i < nbStrings; i++)
		{
			char* cmpRed = reduce(i, strl[i]);
			int cmp = strcmp(red, cmpRed);
			if (cmp != 0)
			{
				bestRes = -1;
				break;
			}
		}

		if (bestRes != -1)
		{
			bestRes = -1;

			int redLen = strlen(red);

			for (int i = 0; i < redLen; i++)
			{
				int minComp = -1;
				int maxComp = 0;

				for (int j = 0; j < nbStrings; j++)
				{
					int min = comp[j][i];
					if ((minComp == -1) || (min < minComp))
					{
						minComp = min;
					}

					int max = comp[j][i];
					if (max > maxComp)
					{
						maxComp = max;
					}
				}

				bestRes = -1;
				for (int j = minComp; j <= maxComp; j++)
				{
					res = 0;
					for (int k = 0; k < nbStrings; k++)
					{
						res += abs(comp[k][i] - j);
					}
					if ((bestRes == -1) || (res < bestRes))
					{
						bestRes = res;
					}
				}

				total += bestRes;
			}
		}

		if (bestRes == -1)
		{
			printf("Fegla Won\n");
		}
		else
		{
			printf("%d\n", total);
		}

		fflush(stdout);
	}
	return 0;
}

