#include <cstdio>
#include <algorithm>
#define ABS(x) ((x) < 0 ? -1*(x) : (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int arr[1010];

int main()
{
	int T,N,i,j, maxd, k;
	scanf("%d",&T);
	for(j = 1; j <= T; ++j)
	{
		scanf("%d", &N);
		for(i = 0; i < N; ++i)
			scanf("%d", &arr[i]);

		int ans = 0;
		for(i = 1; i < N; ++i)
			if(arr[i] < arr[i-1]) ans += (arr[i-1]-arr[i]);

		printf("Case #%d: %d ", j, ans);

		maxd = 0;
		for(i = 1; i < N; ++i)
		{
			if(arr[i] < arr[i-1])
			{
				k = arr[i-1] - arr[i];
				if(k > maxd) maxd = k;
			}
		}

		ans = 0;

		for(i = 0; i < N-1; ++i)
			ans += MIN(maxd, arr[i]);
		
		printf("%d\n", ans);
	}

	return 0;
}