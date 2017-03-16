#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int test,m,n,cnt,num;
    int a[4][4],b[4][4];
    int i,j,k;
    scanf("%d",&test);
    k=0;
    while(test--)
	{
	    scanf("%d",&m);
	    for(i=0;i<4;i++)
		{
	     	for(j=0;j<4;j++) 
			 scanf("%d",&a[i][j]);
    	}
    	scanf("%d",&n);
    	for(i=0;i<4;i++)
		{
    		for(j=0;j<4;j++) 
			scanf("%d",&b[i][j]);
    	}
	    cnt=0;
	    for(i=0;i<4;i++)
		{
		    for(j=0;j<4;j++)
			{
			    if(a[m-1][i]==b[n-1][j])
				{
				    cnt++;
				    num=a[m-1][i];
		        }
		    }
	    }
	    if(cnt>1) 
		printf("Case #%d: Bad magician!\n",k+1);
	    else
		{
		    if(cnt) 
			printf("Case #%d: %d\n",k+1,num);
		    else 
			printf("Case #%d: Volunteer cheated!\n",k+1);
	    }
	    k++;
    }
    return 0;
}
