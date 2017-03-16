#include<cstdio>
#include<bitset>

using namespace std;

int t,x,y;
bitset<20> bo;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++)
	{
		bo.reset();
		
		scanf("%d",&x);
		
		for(int i1=1;i1<=4;i1++)
			for(int j1=1;j1<=4;j1++)
			{
				scanf("%d",&y);
				if(i1==x)bo.set(y);
			}
		
		int ans=0,ans1=0;
		
		scanf("%d",&x);
		
		for(int i1=1;i1<=4;i1++)
			for(int j1=1;j1<=4;j1++)
			{
				scanf("%d",&y);
				if(i1==x&&bo.test(y))
				{
					ans1++;
					ans=y;
				}
			}
		
		printf("Case #%d: ",i); 
		
		if(ans1==1)
			printf("%d\n",ans);
		else
			if(ans1==0)
				printf("Volunteer cheated!\n");
			else
				printf("Bad magician!\n");
	}
	
	return 0;
}
