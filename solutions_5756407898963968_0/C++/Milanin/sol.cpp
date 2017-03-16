#include <stdio.h>
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		int u[17], r;
		for(int i=0; i<17; u[i]=0, i++);
		for(int k=0; k<2; k++)
		{
			scanf("%d", &r);
			for(int i=1; i<=4; i++)
				for(int j=0; j<4; j++)
				{
					int a;
					scanf("%d", &a);
					if(i==r) u[a]++;
				}
		}
		printf("Case #%d: ", t);
		int j=0;
		for(int i=1; i<=16; j+=u[i]==2, i++);
		if(j>1) printf("Bad magician!\n");
		else if(j<1) printf("Volunteer cheated!\n");
		else
		{
			for(j=1; j<=16 && u[j]!=2; j++);
			printf("%d\n", j);
		}
	}
	return 0;
}
