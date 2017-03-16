#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("C-small-attempt2.in.txt");
ofstream cout("out.txt");

typedef struct 
{
	long long x,y;
} node;
int n;
node a[20];

int main()
{
	int t,i,j,k,l,r,ans,caseNum=0;
	node p1,p2;

	cin>>t;
	while (t--)
	{
		caseNum++;
		cin>>n;
		for (i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y;
		cout<<"Case #"<<caseNum<<":"<<endl;
		for (i=1;i<=n;i++)
		{
			ans=-1;
			for (j=1;j<=n;j++)
			{
				if (i==j) continue;
				p1.x=a[j].x-a[i].x;
				p1.y=a[j].y-a[i].y;
				l=0;
				r=0;
				for (k=1;k<=n;k++)
					if (k!=i&&k!=j)
					{
						p2.x=a[k].x-a[i].x;
						p2.y=a[k].y-a[i].y;
						if (p1.x*p2.y-p2.x*p1.y>0) l++;
						if (p1.x*p2.y-p2.x*p1.y<0) r++;
					}
				if (r<l) l=r;
				if (ans==-1||l<ans) ans=l;
			}
			if (ans==-1) ans=0;
			cout<<ans<<endl;
		}
	}
}