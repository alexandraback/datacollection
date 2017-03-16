#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 100 + 10;

int a[N][N];
char c[N][N];
int testCases, n, m;
bool flag;

int main()
{
	scanf("%d", &testCases);
	for (int index = 1; index <= testCases; ++index) {
		memset(a, 0, sizeof a);
		m = -1;
		flag = false;
		
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			static char s[N];
			scanf("%s", s);
			int len = strlen(s);
			int cnt = 0;
			for (int j = 0; j < len; ++j) {
				++a[i][cnt];
				c[i][cnt] = s[j];
				if (j == len - 1 || s[j] != s[j + 1]) ++cnt;
			}
			if (m == -1) m = cnt;
			else
				if (m != cnt) flag = true;
		}
		
		if (! flag)
			for (int j = 0; j < m; ++j)
				for (int i = 1; i < n; ++i)
					if (c[i][j] != c[i - 1][j]) flag = true;
		
		if (flag) {
			printf("Case #%d: Fegla Won\n", index);
			continue;
		}
		
		vector<int> b;
		int ans = 0;
		for (int j = 0; j < m; ++j) {
			b.clear();
			for (int i = 0; i < n; ++i) b.push_back(a[i][j]);
			sort(b.begin(), b.end());
			int mid = b[n / 2];
			for (int i = 0; i < n; ++i) ans += abs(b[i] - mid);
		}
		printf("Case #%d: %d\n", index, ans);
	}
	return 0;
}