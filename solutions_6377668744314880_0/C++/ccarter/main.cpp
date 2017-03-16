#include <iostream>
#include <cstdio>
struct point{
	int x;
	int y;
}p[3000];
using namespace std;
int s(point p1,point p2, point p3)
{
	long long r=(p1.x-p3.x)*(long long)(p2.y-p3.y)-(p1.y-p3.y)*(long long)(p2.x-p3.x);
	if (r<0)
		return -1;
	else if (r==0)
		return 0;
	else return 1;
}
int main()
{
    int tt,tc;
    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			p[i]=(struct point){a,b};

		}
		printf("Case #%d:\n",tc);
		for (int i=0;i<n;i++)
		{
			int ans=1000000;
			for (int j=0;j<n;j++)
			{
				if (j==i)
					continue;
				int cnt1=0,cnt2=0;
				for (int k=0;k<n;k++)
				{
					if (k==i || k==j)
						continue;
					int r=s(p[i],p[j],p[k]);
					if (r==-1)
						cnt1++;
					else if (r==1)
						cnt2++;
				}
				int m=cnt1<cnt2?cnt1:cnt2;
				if (m<ans)
					ans=m;
			}
			if (ans==1000000)
				ans=0;
			printf("%d\n",ans);
		}
	}
    return 0;
}
