#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  

int main() { 
	
	int T,i,j,k;
	int first, second;
	int a[5][5], b[5][5];
	
	scanf("%d",&T);

	for (i=1; i<=T; i++)
	{
		scanf("%d",&first);
		for (j=1;j<=4;j++)
			for (k=1;k<=4;k++)
				scanf("%d",&a[j][k]);
		scanf("%d",&second);
		for (j=1;j<=4;j++)
			for (k=1;k<=4;k++)
				scanf("%d",&b[j][k]);
		
		int counter=0;
		int number;
		for (j=1;j<=4;j++)
			for (k=1;k<=4;k++)
				if (a[first][j]==b[second][k]) {
					counter++;
					number=a[first][j];
				}
			
		printf("Case #%d: ",i);
		if (counter==1) printf("%d\n",number);
		if (counter>1) printf("Bad magician!\n");
		if (counter==0) printf("Volunteer cheated!\n");
		
	}
	
	return 0;
}