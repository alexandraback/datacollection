#include<stdio.h>

int GCD(int a, int b)
{
	if(b==0) return a;
	return GCD(b, a%b);
}

int LCM(int a, int b)
{
	return (a*b)/GCD(a,b);
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,N,B,M[1000],UM[1000];
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%d %d",&B, &N);
		for(int i=0;i<B;i++)
		{
			scanf("%d",&M[i]);
			UM[i] = 0;
		}

		int kpk=1;
		for(int i=0;i<B;i++)
			kpk=LCM(kpk,M[i]);

		int cycle = 0;
		for(int i=0;i<B;i++)
			cycle += (kpk/M[i]);

		int queue = N%cycle;
		if(queue==0)
			queue=cycle;

		int ans = 0;
		for(int n=0;n<queue;n++)
		{
			int min = 1000;
			for(int i=0;i<B;i++)
				min = min<UM[i]?min:UM[i];
			for(int i=0;i<B;i++)
				UM[i]-=min;
			for(int i=0;i<B;i++)
			{
				if(UM[i]==0)
				{
					UM[i]=M[i];
					ans = i;
					break;
				}
			}
		}

		printf("Case #%d: %d\n",c,ans+1);
	}
}