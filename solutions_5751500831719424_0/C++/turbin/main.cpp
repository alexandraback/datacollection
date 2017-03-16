#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cfloat>

using namespace std;

typedef long long ll;
typedef long long li;
typedef unsigned int uint;
typedef unsigned long long ull;

#define TASKNAME "prob"

int n, qt[110][110];
char s[110][110], let[110][110];


int main()
{
#ifdef DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	//ios_base::sync_with_stdio(0);
#endif

	int tests; scanf("%d\n", &tests);
	for (int ts = 0; ts < tests; ts++)
	{
		scanf("%d\n", &n);
		int sz = 0; bool bad = false;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
			int len = strlen(s[i]);
			qt[i][0] = 1; let[i][0] = s[i][0]; int last = 1;
			for (int j = 1; j < len; j++)
				if (s[i][j] == s[i][j - 1]) qt[i][last - 1]++;
				else qt[i][last] = 1, let[i][last] = s[i][j], last++;
				if (sz == 0) sz = last;
				else if (sz != last) bad = true;
		}
		printf("Case #%d: ", ts + 1);
		if (bad) {
			printf("Fegla Won\n"); continue;
		}
		for (int j = 0; j < sz; j++)
		for (int i = 1; i < n; i++)
		if (let[i][j] != let[0][j]) bad = true;
		if (bad) {
			printf("Fegla Won\n"); continue;
		}
		int ans = 0;
		for (int j = 0; j < sz; j++)
		{
			int best = 1000000000;
			for (int i = 0; i < n; i++)
			{
				int cur = 0;
				for (int k = 0; k < n; k++)
					cur += (qt[i][j] > qt[k][j] ? qt[i][j] - qt[k][j] : qt[k][j] - qt[i][j]);
				if (cur < best) best = cur;
			}
			ans += best;
		}
		printf("%d\n", ans);
	}
	
}
