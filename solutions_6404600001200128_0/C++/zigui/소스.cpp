#include<stdio.h>
#include<algorithm>

using namespace std;

const int MX = 1000;

int D[MX];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++)
	{
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", D+i);
		int ans = 0, ans2 = 0, mx = 0;
		for(int i = 1; i < N; i++){
			if( D[i-1] > D[i] ) ans += D[i-1] - D[i];
		}
		for(int i = 1; i < N; i++){
			mx = max(mx, D[i-1] - D[i]);
		}
		for(int i = 0; i < N-1; i++){
			if( D[i] > mx ) ans2 += mx;
			else ans2 += D[i];
		}
		printf("Case #%d: ",t);
		printf("%d %d\n", ans, ans2);
	}
	return 0;
}