#include<stdio.h>
#include<windows.h>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		long long int l,r,mid;
		int N, M[1100]={0,}, B, ans=0;
		scanf("%d%d", &B, &N);
		for(int i = 1; i <= B; i++)
			scanf("%d", &M[i]);
		l = 0;
		r = 2000000000000001;
		while(l+1 != r){
			mid = (l+r)/2;
			long long int c = 0;
			for(int i = 1; i <= B; i++){
				c += (mid-1)/M[i]+1;
			}
			if(c < N) l = mid;
			else r = mid;
		}
		if(l == 0){
			printf("Case #%d: %d\n", tc, N);
			continue;
		}
		int c = 0;
		for(int i = 1; i <= B; i++){
			c += (l-1)/M[i]+1;
		}
		N -= c;
		for(int i = 1; i <= B; i++){
			if(l%M[i]==0){
				N--;
				if(N == 0){
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}