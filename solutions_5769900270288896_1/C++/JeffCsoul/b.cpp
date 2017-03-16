/*
User:JeffCsoul
Time:
No.:
Everything will be better.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;i++)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();i++)
#define PII pair
#define m_p make_pair
using namespace std;

map<PII<int,int>,bool > M;
int r,c,n;
int rst_c,rst_l,rst_s,rst_white;
int main()
{ 
	//freopen("in.txt","r",stdin);
	//freopen("sout.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int nT=1;nT<=T;nT++)
	{
		rst_white=rst_c=rst_l=rst_s=0;
		scanf("%d%d%d",&r,&c,&n);
		for (int i=1;i<=r;i++)
			for (int j=1;j<=c;j++)
			{
				if ((i+j)%2==0)
				{
					if ((i==1&&j==1) || (i==1&&j==c) || (i==r&&j==1) || (i==r&&j==c))
						rst_c++;
					else
					{
						if (i==1 || i==r || j==1 || j==c)
							rst_l++;
						else
							rst_s++;
					}
				}
				else
				{
					rst_white++;
				}
			}
//		cout<<rst_white<<' '<<rst_c<<' '<<rst_l<<' '<<rst_s<<endl; 
		int ans=0;
		int delt=0;
		if (r==1 || c==1)	delt=1;
		for (int i=1;i<=n;i++)
		{
			if (rst_white>0)
			{
				rst_white--;
				continue;
			}
			if (rst_c>0)
			{
				rst_c--;
				ans+=2-delt;
				continue;
			}
			if (rst_l>0)
			{
				rst_l--;
				ans+=3-delt;
				continue;
			}
			rst_s--;
			ans+=4-delt; 
		}
		printf("Case #%d: %d\n",nT,ans);
	}
}


