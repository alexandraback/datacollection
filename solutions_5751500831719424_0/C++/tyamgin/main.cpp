#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <sstream> 
#include <fstream>
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

#define N 109

string s[N];

int getMin(vector<int> A)
{
	int mx = *max_element(A.begin(), A.end());
	int res = INF;
	for (int a = 1; a <= mx; a++)
	{
		int cnt = 0;
		for (auto b : A)
			cnt += abs(b - a);
		res = min(res, cnt);
	}
	return res;
}

int solve()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		cin >> s[i];
	int res = 0;
	for (; s[0].size();)
	{
		char ls = s[0].back();
		vector<int> c(n);
		for (i = 0; i < n; i++)
		{
			if (s[i].empty() || s[i].back() != ls)
				return -1;
			while (s[i].size() && s[i].back() == ls)
				c[i]++, s[i].pop_back();
			
		}
		res += getMin(c);
	}
	for (i = 0; i < n; i++)
		if (s[i].size())
			return -1;
	return res;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		auto res = solve();
		printf("Case #%d: ", test);
		if (res == -1)
			puts("Fegla Won");
		else
			printf("%d\n", res);
	}
}