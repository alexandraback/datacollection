#include <cstdio>
#include <iostream>
using namespace std;

int n;
int row;
int war[20];
int wut;
int pom;

int main()
{
	scanf("%d", &n);
	for (int t=1; t<=n; t++)
	{
		for (int i=1; i<=16; i++)
		war[i]=0;
		wut=0;
		scanf("%d", &row);
		for (int i=1; i<=4; i++)
		{
			for (int j=1; j<=4; j++)
			{
				scanf("%d", &pom);
				if (i==row)
				war[pom]++;
			}
		}
		scanf("%d", &row);
		for (int i=1; i<=4; i++)
		{
			for (int j=1; j<=4; j++)
			{
				scanf("%d", &pom);
				if (i==row)
				war[pom]++;
			}
		}
		for (int i=1; i<=16; i++)
		{
			if (war[i]==2)
			{
				if (!wut)
				wut=i;
				else
				wut=30;
			}
		}
		printf("Case #");
		printf("%d:  ", t);
		if (wut>0 && wut<20)
		printf("%d\n", wut);
		if (!wut)
		printf("Volunteer cheated!\n");
		if (wut==30)
		printf("Bad magician!\n");
		
	}
	return 0;
}
