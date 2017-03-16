#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#include <string.h>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)

int flatten(vector<int> v)
{
	int n = v.size();
	int best = MAXVAL;
	for (int t = 1; t <= 100; t++)
	{
		int d = 0;
		for (int i = 0; i < n; i++)
		{
			d += abs(v[i]-t);
		}
		best = min(best, d);
	}
	return best;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;
		cin >> N;
		vector<string> v(N);

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		string s = v[0];
		s.erase(unique(s.begin(), s.end()), s.end());
		bool poss = true;
		for (int i = 0; i < N; i++)
		{
			string t = v[i];
			t.erase(unique(t.begin(), t.end()), t.end());
			if (t != s)
			{
				poss = false;
			}
		}
		if (!poss)
		{
			printf("Case #%d: Fegla Won\n", testCase);
			continue;
		}
		vector<vector<int>> vc;
		for (int i = 0; i < N; i++)
		{
			int M = s.size();
			vector<int> w(M, 0);
			int p = 0;
			for (int j = 0; j < M; j++)
			{
				while (p < v[i].size() && v[i][p] == s[j])
				{
					w[j]++;
					p++;
				}
			}
			vc.push_back(w);
		}
		int num = 0;
		for (int j = 0; j < s.size(); j++)
		{
			vector<int> vf(N);
			for (int i = 0; i < N; i++)
			{
				vf[i] = vc[i][j];
			}
			num += flatten(vf);
		}
		printf("Case #%d: %d\n", testCase, num);
	}
	return 0;
}
