#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <list>
#include <ctime>

using namespace std;

#define mp make_pair
#define sqr(a) ((a)*(a))

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 30;
const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		int n; scanf("%d", &n);
		pair<int, char> p[MAXN];

		for (int j = 0; j < n; ++j) {
			p[j].second = 'A' + j;
			scanf("%d", &p[j].first);
		}

		sort(p, p+n, greater<pair<int, char>>());

		printf("Case #%d: ", i);
		while (p[0].first > p[1].first) {
			printf("%c ", p[0].second);
			--p[0].first;
		}

		for (int i = 2; i < n; ++i)
			for (int j = 0; j < p[i].first; ++j)
				printf("%c ", p[i].second);

		for (int i = 0; i < p[0].first; ++i)
			printf("%c%c ", p[0].second, p[1].second);

		printf("\n");
	}

	return 0;
}