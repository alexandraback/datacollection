#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1200;
int n;
int m[MAXN];

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int cas = 1; cas <= dat; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &m[i]);
		int s1 = 0, s2 = 0, rate = 0;
		for (int i = 1; i < n; ++i) {
			s1 += max(0, m[i - 1] - m[i]);
			rate = max(rate, m[i - 1] - m[i]);
		}
		for (int i = 0; i < n - 1; ++i) {
			s2 += min(rate, m[i]);
		}
		printf("Case #%d: %d %d\n", cas, s1, s2);
	}
}
