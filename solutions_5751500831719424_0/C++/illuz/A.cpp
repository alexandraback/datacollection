/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-05-04 00:06:02
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

const int N = 2;
int t, n;
string s[N];

int main()
{
	scanf("%d", &t);
	for (int cas = 0; cas < t; cas++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		int i = 0, j = 0, cnt = 0;
		bool flag = true;
		while (i < s[0].length() && j < s[1].length()) {
			if (s[0][i] == s[1][j]) {
				i++;
				j++;
			}
			else {
				if (i == 0 && j == 0) {
					flag = false;
					break;
				}
				if (i != 0 && s[0][i - 1] == s[0][i]) {
					cnt++;
					i++;
					continue;
				}
				if (j != 0 && s[1][j - 1] == s[1][j]) {
					cnt++;
					j++;
					continue;
				}
				flag = false;
				break;
			}
		}
		while (i != s[0].length()) {
			if (s[0][i] != s[0][i - 1])
				flag = false;
			i++, cnt++;
		}
		while (j != s[1].length()) {
			if (s[1][j] != s[1][j - 1])
				flag = false;
			j++, cnt++;
		}
		printf("Case #%d: ", cas + 1);
		if (flag) {
			printf("%d\n", cnt);
		}
		else puts("Fegla Won");
	}
	return 0;
}

