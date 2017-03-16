#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.1415926535897932
#define inf 10000000000000000
int ar[50];
int main()
{   
	int t,y;
	scanf("%d",&t);
	y=0;
	while(t--)
	{
		y++;
		int n,i,j;
		printf("Case #%d: ",y);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);
		while(1)
		{

			for(i=0;i<n;i++)
			{
				if(ar[i]!=0)
				break;
			}
			if(i==n)
			break;
			int c1=0;
			for(i=0;i<n;i++)
			{
				if(ar[i]!=0)
				{
					c1++;
				}
			}
			if(c1==2)
			{
				while(1)
				{
					int c=0;
					for(i=0;i<n;i++)
					{
						if(ar[i]!=0)
						{
							printf("%c",i+'A');
							c++;
							ar[i]--;
						}
					}
					if(c==0)
					break;
					printf(" ");
				}
				break;
			}
			int lar=0,ff=ar[0];
			for(i=1;i<n;i++)
			{
				if(ar[i]>ff)
				{
					lar=i;
					ff=ar[i];
				}
			}
			printf("%c ",lar+'A');
			ar[lar]--;
		}
		printf("\n");
	}
	return 0;
}