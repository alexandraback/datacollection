// Author : dstorm
// Problem A : Magic Trick
// Compiler : Mingw (Gcc)
#include<stdio.h>
int main()
{	int i,j,k,l,t,ans[2],grid[2][4][4];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{	int map[17]={0};
		int cnt2=0,card=0;
		for(j=0;j<2;j++)
		{	scanf("%d",&ans[j]);
			for(k=0;k<4;k++)
			{	for(l=0;l<4;l++)
				{	scanf("%d",&grid[j][k][l]);	
					if(k==ans[j]-1)
						map[grid[j][k][l]]++;
				}
			}
		}
		for(j=1;j<=16;j++)
		{	if(map[j]==2)
			{	cnt2++;
				card=j;
			}
		}
		printf("Case #%d: ",i);
		if(cnt2==1)
			printf("%d\n",card);
		else if(cnt2>1)
			printf("Bad magician!\n");
		else
			printf("Volunteer cheated!\n");
	}
	return 0;
}