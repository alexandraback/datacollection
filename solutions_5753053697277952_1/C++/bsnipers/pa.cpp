#include <stdio.h>

int p[30];

int find(int n)
{
	int ret=0,mmax=-1;
	for(int i=0; i<n; i++)
		if(p[i]>mmax)
			ret=i,mmax=p[i];
	return ret;
}

int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int n,sum=0;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&p[i]);
			sum+=p[i];
		}
		printf("Case #%d:",T);
		while(sum){
			int tar=find(n);
			printf(" %c",tar+'A');
			sum--;
			p[tar]--;
			tar=find(n);
			if(p[tar]*2>sum){
				printf("%c",tar+'A');
				p[tar]--;
				sum--;
			}
		}
		puts("");
	}
	return 0;
}
