#include<stdio.h>

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,N,M[10000];

	scanf("%d",&T);

	for(int c=1;c<=T;c++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",&M[i]);

		int first=0;
		for(int i=1;i<N;i++)
		{
			if(M[i] < M[i-1])
				first += (M[i-1] - M[i]);
		}

		int second=0;
		int rate=0;
		for(int i=1;i<N;i++)
		{
			int gap = M[i-1] - M[i];
			rate = gap>rate?gap:rate;
		}
		for(int i=0;i<N-1;i++)
		{
			if(M[i]<rate)
				second+=M[i];
			else
				second+=rate;
		}
		printf("Case #%d: %d %d\n",c,first,second);
	}
}