#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 1010;
int a[maxn];
int n;
void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans1 = 0;
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1])
			ans1 += a[i - 1] - a[i];
	int ans2 = 0, v = 0;
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1] && a[i - 1] - a[i] > v)
			v = a[i - 1] - a[i];
	for (int i = 0; i < n - 1; i++)
		ans2 += min(v, a[i]);
	printf("%d %d\n", ans1, ans2);
}
int main()
{
	freopen("t.in","r", stdin);
	freopen("t.out", "w", stdout);
	int  t;
	cin >> t;
	For(i,1, t)
	{
		printf("Case #%d: ", i);
		init();
	}
	return 0;
}
