#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int T, n, a[N];

int work()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	
	int s1(0), s2(0), s3(0);
	for(int i=2; i<=n; i++) if(a[i]<a[i-1]) s1 += a[i-1]-a[i], s2 = max(s2, a[i-1]-a[i]);
	for(int i=1; i<n; i++) s3 += min(s2, a[i]);
	
	printf("%d %d\n", s1, s3);
	return 1;
}

int main()
{
	freopen("eat.in", "r", stdin);
	freopen("eat.out", "w", stdout);
	
	scanf("%d", &T);
	for(int i=1; i<=T; i++) printf("Case #%d: ", i), work();
	
	return 0;
}
