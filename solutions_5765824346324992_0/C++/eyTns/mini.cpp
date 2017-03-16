#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) { return y? gcd(y, x%y) : x; }
int lcm(int x, int y) { return x/gcd(x,y)*y; }

int main()
{
	FILE* fin=fopen("b.in", "r");
	FILE* fou=fopen("answer.out", "w");
	int t;

//	scanf("%d", &t);
	fscanf(fin, "%d", &t);

	for(int i=1; i<=t; i++)
	{
		int m[2000]={0};
		int cut[2000]={0};
		int b, n;
		int L=1;
		int period=0;
		int pas=0;
		int going=0;
		int x;
//		scanf("%d%d", &b, &n);
		fscanf(fin, "%d%d", &b, &n);
		for(int j=1; j<=b; j++)
		{
//			scanf("%d", &m[j]);
			fscanf(fin, "%d", &m[j]);
			L=lcm(L, m[j]);
		}

		for(int j=1; j<=b; j++)
		{
			period+=L/m[j];
		}

		n%=period;
		if(n==0) n=period;

		while(going<n)
		{
			for(int j=1; j<=b; j++)
			{
				if(cut[j]==0)
				{
					going++;
					x=j;
					if(going==n)
						break;
					cut[j]=m[j]-1;
				}
				else
				{
					cut[j]--;
				}
			}
		}

		printf("Case #%d: %d\n", i, x);
		fprintf(fou, "Case #%d: %d\n", i, x);

	}

	return 0;
}



