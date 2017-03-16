#include<stdio.h>

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		int N, M[1100], c1 = 0, c2 = 0, max = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++){
			scanf("%d", &M[i]);
		}
		for(int i = 2; i <= N; i++){
			if(M[i] > M[i-1]) continue;
			c1 += M[i-1]-M[i];
			if(max < M[i-1]-M[i]) max = M[i-1]-M[i];
		}
		if(max == 0){
			printf("Case #%d: 0 0\n", tc);
			continue;
		}
		//int rate = max/10;
		//if(max%10 != 0) rate++;
		//rate = rate * 10;
		int rate = max;
		for(int i = 2; i <= N; i++){
			if(M[i-1] > rate) c2 += rate;
			else c2 += M[i-1];
		}
		printf("Case #%d: %d %d\n", tc, c1, c2);
	}
	return 0;
}