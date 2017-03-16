#include <stdio.h>
#include <stdlib.h>

long long int m[2000]={0};
long long int b, n;

long long int calc(long long int l)
{
	long long int sum=0;
	for(int j=1; j<=b; j++)
	{
		sum+=l/m[j]+1;
	}
	return sum;
}

int main()
{
	FILE* fin=fopen("b.in", "r");
	FILE* fou=fopen("answer.out", "w");
	long long int t;

//	scanf("%d", &t);
	fscanf(fin, "%lld", &t);

	for(int i=1; i<=t; i++)
	{
		long long int x;
		long long int le, ri, mid;
		long long int leser;
		long long int riser;
		long long int midser;

//		scanf("ll%dll%d", &b, &n);
		fscanf(fin, "%lld%lld", &b, &n);
		for(int j=1; j<=b; j++)
		{
//			scanf("%lld", &m[j]);
			fscanf(fin, "%lld", &m[j]);
		}

		if(n<=b)
		{
			le=999, ri=999;
			x=n;
		}
		else
		{
			le=0;
			ri=10000000000000ll;
			leser=0;
			riser=0;
			midser=0;

			while(ri-le>1)
			{
				mid=(le+ri)/2;
				midser=calc(mid);
				if(midser>=n)
					ri=mid;
				else
					le=mid;
			}

			leser=calc(le);
			riser=calc(ri);

			for(int j=1; leser<n; j++)
			{
				if(ri%m[j]==0)
					x=j, leser++;
			}
		}

		printf("Case #%d: %lld\n", i, x);
		fprintf(fou, "Case #%d: %lld\n", i, x);
	}

	return 0;
}



