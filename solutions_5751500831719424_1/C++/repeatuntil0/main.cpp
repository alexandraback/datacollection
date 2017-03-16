/*
#include "template.h"
#include "point.h"
#include "math.h"
#include "line.h"
#include "edge.h"
#include "graph.h"
#include "distance.h"
#include "dsu.h"
#include "mst.h"
#include "convex hull.h"
*/
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;

#define mp make_pair
#define pb push_back
#define det(a, b, c, d) a * d - b * c

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int inf = 1234567890;
#endif

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int N;
		scanf("%d", &N);
		vector<string> vs(N+1);
		vector<vector<pii>> C(N+1);
		for (int i = 1; i <= N; ++i)
		{
			cin >> vs[i];
			for (int j = 1; j <= vs[i].size(); ++j)
			{
				if(C[i].size() && C[i].back().first == vs[i][j-1] - 'a')
					C[i].back().second++;
				else
					C[i].push_back(make_pair(vs[i][j-1] - 'a', 1));
			}
		}
		bool same = true;
		for (int i = 2; i <= N; ++i)
		{
			if(C[i].size() != C[1].size()) same = false;
			for (int j = 1; j <= C[1].size() && same; ++j)
			{
				if(C[i][j-1].first != C[1][j-1].first) same = false;
			}
		}
		printf("Case #%d: ", t);
		if(!same) printf("Fegla Won");
		else
		{
			int answer = 0;
			for (int i = 1; i <= C[1].size(); ++i)
			{
				ll maximum = 1;
				for (int j = 1; j <= N; ++j)
				{
					maximum = max(maximum, C[j][i-1].second);
				}
				int g_add = -1;
				for (int j = 1; j <= maximum; ++j)
				{
					int l_add = 0;
					for (int k = 1; k <= N; ++k)
					{
						l_add += abs(j - C[k][i-1].second);
					}
					if(g_add == -1 || g_add > l_add)
						g_add = l_add;
				}
				answer += g_add;
			}
			printf("%d", answer);
		}
		printf("\n");
	}
	return 0;
}