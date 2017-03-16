#include<cstdio>
int T;
int N;
int P[1010];
void tmain()
{
	scanf("%d",&N);
	int sum=0;
	for(int i=0; i<N; i++)
	{
		scanf("%d",P+i);
		sum += P[i];
	}
	while(sum--)
	{
		int maxv=-1;
		int maxi=0;
		bool overhalf=false;
		for(int i=0; i<N; i++)
		{
			if(P[i]>maxv)
			{
				maxv=P[i];
				maxi=i;
			}
			if(P[i]>(sum+1)/2)
			overhalf=true;
		}
		if(!overhalf) putchar(' ');
		printf("%c",'A'+maxi);
		P[maxi]--;
	}
}
int main()
{
	scanf("%d",&T);
	for(int i=1; i<=T; i++)
	{
		printf("Case #%d:",i);
		tmain();
		puts("");
	}
}
