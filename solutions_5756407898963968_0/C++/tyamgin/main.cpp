#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <sstream> 
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

int main()
{
	int tests, row1, row2, i, j, a[4][4], b[4][4];
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d", &row1);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &a[i][j]);
		scanf("%d", &row2);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &b[i][j]);
		row1--, row2--;
		set<int> answers;
		for (j = 0; j < 4; j++)
			if (count(a[row1], a[row1] + 4, b[row2][j]))
				answers.insert(b[row2][j]);
		printf("Case #%d: ", test);
		if (answers.empty())
			puts("Volunteer cheated!");
		else if (answers.size() == 1)
			printf("%d\n", *answers.begin());
		else
			puts("Bad magician!");
	}
}