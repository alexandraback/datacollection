#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 16

using namespace std;

int px[SIZE],py[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int a,b;
		scanf("%d",&a);a--;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				int x;
				scanf("%d",&x);x--;
				px[x]=i;
			}
		}
		scanf("%d",&b);b--;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				int x;
				scanf("%d",&x);x--;
				py[x]=i;
			}
		}
		int cnt=0,pos=-1;
		for(int i=0;i<SIZE;i++)
		{
			if(px[i]==a&&py[i]==b)
			{
				cnt++;
				pos=i;
			}
		}
		printf("Case #%d: ",t);
		if(cnt==0) printf("Volunteer cheated!");
		else if(cnt>1) printf("Bad magician!");
		else printf("%d",pos+1);
		puts("");
	}
	return 0;
}
