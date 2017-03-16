#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long ll;

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
		int N, T;
		scanf("%d%d", &N, &T);
		for(int i = 0; i < N; i++) scanf("%d", D+i);
		ll st = 0, en = 20000000000000000ll, mi, ans = 0;
		while(st <= en){
			mi = (st+en)/2;
			ll tot = 0;
			for(int i = 0; i < N; i++){
				tot += (mi+D[i]) / D[i];
			}
			if( tot >= T ){
				en = mi-1;
				ans = mi;
			}
			else st = mi+1;
		}
		ll bef = 0;
		for(int i = 0; i < N; i++){
			bef += (ans+D[i]-1) / D[i];
		}
		printf("Case #%d: ", t);
		for(int i = 0; i < N; i++){
			if( ans % D[i] == 0 ) bef++;
			if( bef == T){
				printf("%d\n", i+1);
				break;
			}
		}
	}
	return 0;
}