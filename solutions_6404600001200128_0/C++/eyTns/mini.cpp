#include <stdio.h>
#include <stdlib.h>

int a[2000];

int main()
{
	FILE* fin=fopen("a.in", "r");
	FILE* fou=fopen("answer.out", "w");
	int t;

//	scanf("%d", &t);
	fscanf(fin, "%d", &t);

	for(int i=1; i<=t; i++)
	{
		int n;
		int m[2000];
//		scanf("%d", &n);
		fscanf(fin, "%d", &n);

		for(int j=0; j<n; j++)
//			scanf("%d", &m[j]);
			fscanf(fin, "%d", &m[j]);

		int x=0, y=0;
		int maxrate=0;

		for(int j=0; j<n-1; j++)
		{
			if(m[j]>m[j+1])
			{
				x+=m[j]-m[j+1];
				if(maxrate<m[j]-m[j+1])
					maxrate=m[j]-m[j+1];
			}
		}
		for(int j=0; j<n-1; j++)
		{
			if(m[j]>=maxrate)
				y+=maxrate;
			else
				y+=m[j];
		}

		printf("Case #%d: %d %d\n", i, x, y);
		fprintf(fou, "Case #%d: %d %d\n", i, x, y);

	}

	return 0;
}



