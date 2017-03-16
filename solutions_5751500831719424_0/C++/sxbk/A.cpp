#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <algorithm>

#define			OK			std::cout << "------------" << std::endl;
#define			DEBUG(x)		std::cout << #x << " = " << x << std::endl;

using namespace std;

const int maxn = 108;

char a[maxn][maxn];
char s[maxn][maxn];
int top[maxn];
int cnt[maxn][maxn];

int st[maxn][maxn];

int main()
{
	int TT;
	scanf("%d", &TT);
	for (int _ = 1;_ <= TT;_ ++) {
		printf("Case #%d: ", _);
		int N;
		scanf("%d", &N);
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0;i < N;i++) {
			scanf("%s", a[i]);
		//	cout << a[i] << endl;
		}
		for (int i = 0;i < N;i++) {
			int len = strlen(a[i]);
			top[i] = 1;
			s[i][0] = a[i][0];
			cnt[i][0] = 1;
			for (int j = 1;j < len;j++) {
				if (a[i][j] != a[i][j-1]) {
					s[i][top[i]] = a[i][j];
					cnt[i][top[i]] = 1;
					top[i] ++;
				} else {
					cnt[i][top[i]-1] ++;
				}
			}
		}
		int M = strlen(s[0]);
		int ans = 0;
		for (int i = 1;i < N;i++) {
			if (strcmp(s[i-1], s[i]) != 0) {
				puts("Fegla Won");
				goto OUT;
			}
		}
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				st[j][i] = cnt[i][j];
			}
		}
		for (int i = 0;i < M;i++) {
			sort(st[i], st[i] + N);
			int xi = st[i][N/2];
			for (int j = 0;j < N;j++) {
				ans += abs(st[i][j] - xi);
			}
		}
		printf("%d\n", ans);
OUT:		;
	}
	return 0;
}
