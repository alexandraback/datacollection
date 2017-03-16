#include <cstdio>
#include <vector>
#include<cmath>
#include<ctime>
#include<sstream>
#include <algorithm>
#include<iostream>
#include<set>
#include <cstring>
#include<string>
#include<map>
#include<queue>
#include <cassert>
using namespace std;
typedef unsigned long long ull;
int nextint(){int a;scanf("%d",&a);return a;}
const double EPS = 1e-6;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		int n = nextint();
		vector<string> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];

		vector<vector<pair<char, int> > > q(n);
		for(int i = 0; i < n; i++)
		{
			pair<char, int> cur(v[i][0], 0);
			for(int j = 0; j < v[i].size(); j++)
			{
				if(v[i][j] == cur.first)
					cur.second++;
				else
				{
					q[i].push_back(cur);
					cur = make_pair(v[i][j], 1);
				}
			}
			q[i].push_back(cur);
		}

		bool ok = true;
		for(int i = 0; i < n; i++)
		{
			if(q[i].size() != q[0].size())
			{
				ok = false;
				break;
			}
			for(int j = 0; j < q[i].size(); j++)
			{
				if(q[i][j].first != q[0][j].first)
				{
					ok = false;
					break;
				}
			}
			if(!ok)
				break;
		}
		if(ok)
		{
			int res = 0;
			for(int i = 0; i < q[0].size(); i++)
			{
				vector<int> c;
				for(int j = 0; j < q.size(); j++)
				{
					c.push_back(q[j][i].second);
				}
				sort(c.begin(), c.end());
				int mid = c[c.size()/2];
				for(int j = 0; j < q.size(); j++)
				{
					res += abs(q[j][i].second-mid);
				}
			}
			printf("Case #%d: %d\n", test, res);
		}
		else
		{
			printf("Case #%d: Fegla Won\n", test);
		}
	}

	return 0;
}