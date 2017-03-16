#include "stdafx.h" 
#include "wchar.h"
#include "conio.h"
#include "iostream"
#include "string.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "limits.h"
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <queue>
#define PI 3.14159265358979323846
#define ull unsigned long long int
#define ll long long int
#define EPS 1e-11
#define pb push_back
#define EOS(c) (c != EOF && c != '\0' && c != '\n' && c != ' ')
#define oo 1000000005
#define ALL(v) v.begin(), v.end()
#define mp make_pair
#define win return 0 

//#define FILE "brackets"

using namespace std;

template<class telem>telem MAX(telem a, telem b)
{
	return (a > b) ? a : b;
}

template<class telem>telem MIN(telem a, telem b)
{
	return (a < b) ? a : b;
}

template<class telem>telem GCD(telem a, telem b)
{
	return b ? GCD(b, a % b) : a;
}

template<class telem>telem LCM(telem a, telem b)
{
	return a / GCD(a, b) * b;
}

template<class telem>telem UNSIGNED(telem a)
{
	return (a > 0) ? a : a * (-1);
}

template<class telem>void bez_swop(telem &a, telem &b)
{
	telem c = a;
	a = b;
	b = c;
}

char check[17];
vector<int> ans;
int Case;
int T;
int a;

int main()
{  
	//freopen(FILE".in", "r", stdin);
	//freopen(FILE".out", "w", stdout);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//time_t start = clock();

	scanf("%d", &T);
	Case = T;

	while(T --> 0)
	{
		printf("Case #%d: ", Case - T);

		memset(check, 0, sizeof(check));
		ans.clear();

		scanf("%d", &a);

		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1, tmp; j <= 4; j++)
			{
				scanf("%d", &tmp);
				if(i == a)
					check[tmp] = 1;
			}
		}

		scanf("%d", &a);

		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1, tmp; j <= 4; j++)
			{
				scanf("%d", &tmp);
				if(i == a && check[tmp])
					ans.pb(tmp);
			}
		}

		if(ans.size() > 1)
			printf("Bad magician!\n");
		if(ans.size() < 1)
			printf("Volunteer cheated!\n");
		if(ans.size() == 1)
			printf("%d\n", ans[0]);
	}

	//printf("\n%0.3lf", (clock() - start) * 1.0 / CLOCKS_PER_SEC);

	win;
}