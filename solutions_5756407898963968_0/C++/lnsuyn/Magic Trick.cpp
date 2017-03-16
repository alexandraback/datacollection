#include <stdio.h>

int main(void)
{
	int t ,i;
	int k1 ,k2;
	int a[5][5];
	int b[5][5];
	int j1 ,j2 ,j3;
	int nans ,ans;
	int z;
	
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		printf("Case #%d: " ,i);
		scanf("%d" ,&k1);	
		for (j1=1 ; j1<=4 ; j1++)
		{
			for (j2=1 ; j2<=4 ; j2++)
			{
				scanf("%d" ,&a[j1][j2]);
			}	
		}
		scanf("%d" ,&k2);	
		for (j1=1 ; j1<=4 ; j1++)
		{
			for (j2=1 ; j2<=4 ; j2++)
			{
				scanf("%d" ,&b[j1][j2]);
			}	
		}
		nans=0;
		for (j2=1 ; j2<=4 ; j2++)
		{
			z=0;
			for (j3=1 ; j3<=4 ; j3++)
			{
				if (a[k1][j2]==b[k2][j3])
				{
					z=1;
					break;	
				}
			}
			if (z)
			{
				nans++;
				ans=j2;	
			}
		}
		if (nans==0)
		{
			printf("Volunteer cheated!");
		}	
		else if (nans==1)
		{
			printf("%d" ,a[k1][ans]);
		}
		else
		{
			printf("Bad magician!");			
		}		
		printf("\n");
	}
	
	return 0;
}
