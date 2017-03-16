/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        AA.cpp
*  Create Date: 2014-05-04 01:19:32
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <cmath>
#include <cstdlib>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <sstream>
#include <utility>
#include <cctype>
using namespace std;
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi firsst
#define sd second
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 110;
int t, n, i, j, ans;
struct S {
	char str[N];
	int v;
} s[N];

bool check()
{
	for (int i = 0; i < n; i++) {
		if (s[i].v < strlen(s[i].str))
			return true;
	}
	return false;
}

bool judge()
{
	while (check()) {
		int save[N], i;
		memset(save, 0, sizeof(save));
		char c = s[0].str[s[0].v];
		for (i = 0; i < n; i++) {
			int num = 0;
			if (s[i].str[s[i].v] != c) return false;
			while (s[i].str[s[i].v] == c) {
				s[i].v++;
				num++;
			}
			save[i] = num;
		}
		sort(save, save + n);
		int mid = save[n / 2];
		for (i = 0; i < n; i++)
			ans += abs(save[i] - mid);
	}
	return true;
}

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		memset(s, 0, sizeof(s));
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", s[i].str);
			s[i].v = 0;
		}
		printf("Case #%d: ", cas);
		if (!judge())
			puts("Fegla Won");
		else
			printf("%d\n", ans);
	}
	return 0;
}

