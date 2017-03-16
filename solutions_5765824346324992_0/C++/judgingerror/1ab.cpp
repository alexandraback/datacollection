#include<bits/stdc++.h>
using namespace std;
struct BB
{
	int no,m,o;
}bb[1005];
bool cmp(BB x,BB y)
{
	if(x.m!=y.m)return x.m < y.m;
	return x.no < y.no;
}
vector<int>seq;
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int T,cse,i,b,n,ans,t,cx,sz;
	scanf("%d",&T);
	for(cse=1;cse<=T;cse++)
	{
		scanf("%d%d",&b,&n);
		memset(bb,0,sizeof bb);
		for(i=1;i<=b;i++){scanf("%d",&bb[i].o);bb[i].m=bb[i].o;bb[i].no=i;}
		if(n<=b)
		{
			printf("Case #%d: %d\n",cse,n);
			continue;
		}
		seq.clear();
		for(i=1;i<=b;i++)seq.push_back(i);
		cx=0;
		while(cx<b)
		{
			cx=0;
			sort(bb+1,bb+b+1,cmp);
			t=bb[1].m;
			for(i=1;i<=b;i++)
			{
				bb[i].m-=t;
				if(bb[i].m==0)
				{
					cx++;
					seq.push_back(bb[i].no);
					bb[i].m=bb[i].o;
				}
			}
		}
		sz=seq.size()-cx;
		ans=seq[(n-1)%sz];
		P:printf("Case #%d: %d\n",cse,ans);
	}
	return 0;
}
