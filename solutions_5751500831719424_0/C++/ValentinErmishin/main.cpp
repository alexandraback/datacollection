#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <hash_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <float.h>
#include <time.h>
#include <queue>
#include <cstdint>
#define PI 3.14159265358979323846
#define ull unsigned long long int
#define ll long long int
#define EPS 1e-12
#define pb push_back
#define EOS(c) (c != EOF && c != '\0' && c != '\n' && c != ' ')
#define oo 1000000005
#define ALL(v) v.begin(), v.end()
#define mp make_pair
#define sqr(a) (a) * (a)

using namespace std;

#define FILE "sort"
//#define OUT "put.txt"

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

void swop(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int T;
int n;
string tmp;
pair<char, int> temp;
vector<pair<char, int> > mas[101];

int main()
{

#ifndef ONLINE_JUDGE
#ifdef OUT
	freopen("in"OUT, "r", stdin);
	freopen("out"OUT, "w", stdout); 
#endif

#ifdef FILE
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout); 
#endif
#endif

	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	time_t start = clock();

	scanf("%d", &T);

	for(int test = 1; test <= T; test++)
	{
		scanf("%d", &n);

		printf("Case #%d: ", T);

		int ans = 0;

		for(int k = 0; k < n; k++)
		{
			cin >> tmp;

			mas[k].clear();
			mas[k].push_back(temp);
			mas[k].back().first = tmp[0];
			mas[k].back().second = 1;

			for(int i = 1; i < tmp.size(); i++)
			{
				if(tmp[i] == tmp[i - 1])
				{
					mas[k].back().second++;
				}
				else
				{
					mas[k].push_back(temp);
					mas[k].back().first = tmp[i];
					mas[k].back().second = 1;
				}
			}
		}

		bool check = false;

		for(int i = 1; i < n; i++)
		{
			if(mas[i].size() != mas[i - 1].size())
				check = true;
		}

		if(check)
		{
			puts("Fegla Won");
			continue;
		}

		for(int i = 0; i < mas[0].size() && !check; i++)
		{
			int mi = mas[0][i].second;
			int ma = mas[0][i].second;

			for(int j = 1; j < n; j++)
			{
				if(mas[j][i].first != mas[j - 1][i].first)
				{
					check = true;
					break;
				}
				ma = max(ma, mas[j][i].second);
				mi = min(mi, mas[j][i].second);
			} 

			int at = 1e9;

			for(int k = mi; k <= ma; k++)
			{
				int t = 0;
				for(int j = 0; j < n; j++)
				{
					t += abs(mas[j][i].second - k);
				}
				at = min(at, t);
			}

			ans += at;
		}

		if(check)
		{
			puts("Fegla Won");
			continue;
		}

		printf("%d\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	fprintf(stderr, "\n%0.3lf\n", (clock() - start) * 1.0 / CLOCKS_PER_SEC);
#endif

	return 0;
}