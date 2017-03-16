#include <cstdio>
using namespace std;

const int N = 1000 + 100;
int a[N];

int main()
{
	int T;
	scanf("%d", &T);
	
	for(int ca = 1; ca <= T; ++ca) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);

		int ans1 = 0;
		for(int i = 2; i <= n; ++i)
			if(a[i - 1] - a[i] > 0)
				ans1 += a[i - 1] - a[i];

		int ans2 = 0, speed = 0;
		for(int i = 2; i <= n; ++i)
			if(a[i - 1] - a[i] > speed)
				speed = a[i - 1] - a[i];
		for(int i = 2; i <= n; ++i)
			if(a[i - 1] > speed)
				ans2 += speed;
			else ans2 += a[i - 1];

		printf("Case #%d: %d %d\n", ca, ans1, ans2);
	}
}