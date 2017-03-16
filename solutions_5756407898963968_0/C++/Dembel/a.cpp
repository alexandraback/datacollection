#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

using namespace std;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	const int n = 4;

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		vector <int> used(n * n);
		int row1;
		scanf("%d", &row1);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				int a;
				scanf("%d", &a);
				if (i == row1 - 1)
					used[a - 1] |= 1;
			}
		int row2;
		scanf("%d", &row2);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				int a;
				scanf("%d", &a);
				if (i == row2 - 1)
					used[a - 1] |= 2;
			}

		int cnt = 0;
		int ans;
		for (int i = 0; i < n * n; ++i)
			if (used[i] == 3)
			{
				++cnt;
				ans = i;
			}

		if (cnt == 0)
			printf("Volunteer cheated!\n");
		else if (cnt == 1)
			printf("%d\n", ans + 1);
		else
			printf("Bad magician!\n");
	}

	return 0;
}
