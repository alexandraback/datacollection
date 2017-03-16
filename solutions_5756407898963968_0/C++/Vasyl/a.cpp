//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int SolveTest(int test)
{
	int i, j, k;

	int a[16];
	CLEAR(a, 0);

	FOR(i, 0, 2)
	{
		int r;
		scanf("%d", &r);
		FOR(j, 0, 4)
			FOR(k, 0, 4)
			{
				int v;
				scanf("%d", &v);
				if (j == r - 1)
					++a[v - 1];
			}
	}

	int cnt = 0;
	int res = 0;
	FOR(i, 0, 16)
	if (a[i] == 2)
	{
		++cnt;
		res = i;
	}

	printf("Case #%d: ", test + 1);
	if (cnt == 0)
		printf("Volunteer cheated!\n");
	else if (cnt == 1)
		printf("%d\n", res + 1);
	else
		printf("Bad magician!\n");
	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
