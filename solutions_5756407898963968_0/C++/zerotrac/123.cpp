#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

int p[20];
int T,x,y,cs=0;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(p,0,sizeof(p));
		scanf("%d",&x);
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				scanf("%d",&y);
				if(i==x)p[y]++;
			}
		scanf("%d",&x);
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				scanf("%d",&y);
				if(i==x)p[y]++;
			}
		int ans=0,w=0;
		for(int i=1;i<=16;i++)if(p[i]==2)ans++,w=i;
		printf("Case #%d: ",++cs);
		if(!ans)
			printf("Volunteer cheated!\n");
		else if(ans==1)
			printf("%d\n",w);
		else
			printf("Bad magician!\n");
	}
	return 0;
}
