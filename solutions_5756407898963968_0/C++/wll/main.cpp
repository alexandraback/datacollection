#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
    int t;
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;i++)
	{
        int d[5][5];
		int j,k,c;
		scanf("%d",&c);
		for(j=1;j<=4;j++)
			for(k=1;k<=4;k++)
			{
			   scanf("%d",&d[j][k]);
			}

		int a[5];
		a[1]=d[c][1];
		a[2]=d[c][2];
		a[3]=d[c][3];
	    a[4]=d[c][4];

		scanf("%d",&c);
		for(j=1;j<=4;j++)
			for(k=1;k<=4;k++)
			{
			   scanf("%d",&d[j][k]);
			}
	    int b[5];
        b[1]=d[c][1];
		b[2]=d[c][2];
		b[3]=d[c][3];
	    b[4]=d[c][4];

		int con=0;
		int ans=0;
        for(j=1;j<=4;j++)
			for(k=1;k<=4;k++)
			{
				if(a[j]==b[k])
				{
					con++;
				    ans=a[j];
				}
			}
        if(con==1)
		   printf("Case #%d: %d\n",i,ans);
		else if(con==0)
           printf("Case #%d: Volunteer cheated!\n",i);
		else
		   printf("Case #%d: Bad magician!\n",i);

	}
    return 0;
}