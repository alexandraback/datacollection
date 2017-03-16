#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include "memory.h"

int n;
int t;

int pnum[100];

int main()
{
	scanf("%d",&t);
	int i,j,k,l;
	for (i=0;i<t;i++)
	{
		memset(pnum,0,sizeof(pnum));
		scanf("%d",&n);
		int max = 0;
		int total = 0;
		for (j=0;j<n;j++)
		{
			scanf("%d",&pnum[j]);
			if (pnum[j]>max)
			{
				max = pnum[j];
			}
			total += pnum[j];
		}
		j = max;
		printf("Case #%d:",i+1);
		while (j>0)
		{
			int x1 = -1;
			int x2 = -1;
			for (k=0;k<n;k++)
			{
				if (pnum[k] == j)
				{
					x1 = k;
					break;
				}
			}
			if (x1 == -1)
			{
				j--;
				continue;
			}
			total --;
			pnum[x1] --;
			printf(" %c",'A'+x1);
			if (total == 2) continue;
			k ++;
			while (k<n)
			{
				if (pnum[k] == j)
				{
					x2 = k;
					break;
				}
				k++;
			}
			if (x2 != -1)
			{
				total --;
				printf("%c",'A'+x2);
				pnum[x2] --;
			}
			else
			{
				j--;
			}
		}
		printf("\n");
	}
	return 0;
}
