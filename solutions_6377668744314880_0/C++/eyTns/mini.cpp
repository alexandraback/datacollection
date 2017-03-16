#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fin=fopen("c.in", "r");
	FILE* fou=fopen("answer.out", "w");
	int t;

//	scanf("%d", &t);
	fscanf(fin, "%d", &t);

	for(int i=1; i<=t; i++)
	{
		int n;
		long long int x[3200]={0};
		long long int y[3200]={0};
		int mincut;
//		scanf("%d", &n);
		fscanf(fin, "%d", &n);
		for(int j=0; j<n; j++)
		{
//			scanf("%lld%lld", &x[j], &y[j]);
			fscanf(fin, "%lld%lld", &x[j], &y[j]);
		}

		printf("Case #%d:\n", i);
		fprintf(fou, "Case #%d:\n", i);

		for(int j=0; j<n; j++)
		{
			if(n<=3)
				mincut=0;
			else
			{
				mincut=1000000000;
				for(int k=0; k<n; k++)
				{
					if(j==k)
						continue;
					int lcut=0, rcut=0;
					for(int l=0; l<n; l++)
					{
						if(j==l || k==l)
							continue;
						if((y[l]-y[j])*(x[k]-x[j])>(x[l]-x[j])*(y[k]-y[j]))
							lcut++;
						else if((y[l]-y[j])*(x[k]-x[j])<(x[l]-x[j])*(y[k]-y[j]))
							rcut++;
					}
					if(lcut<mincut)
						mincut=lcut;
					if(rcut<mincut)
						mincut=rcut;
				}
			}

			printf("%d\n", mincut);
			fprintf(fou, "%d\n", mincut);
		}
	}

	return 0;
}



