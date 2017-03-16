#include<bits/stdc++.h>
using namespace std;
int m[20],n[20][20],p,q,r,num,ans;
void gen(int a,int b)
{
	if(a==b)
	{
		num=0;
		int c,d;
		memset(n,0,sizeof(n));
		for(c=0;c<b;c++)
		{
			n[c/q][c%q]=m[c];
			if(m[c]==1)num++;
		}
		if(num==r)
		{
			num=0;
			for(c=0;c<p;c++)
			{
				for(d=0;d<q;d++)
				{
					if(n[c][d]==1&&n[c+1][d]==1)num++;
					if(n[c][d]==1&&n[c][d+1]==1)num++;
				}
			}
			ans=min(num,ans);
		}
	}
	else
	{
		m[a]=0;
		gen(a+1,b);
		m[a]=1;
		gen(a+1,b);
	}
	
}
main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out-B-small.txt","w",stdout);
	int a,b;
	scanf("%d",&a);
	for(b=0;b<a;b++)
	{
		scanf("%d %d %d",&p,&q,&r);
		ans=1000;
		gen(0,p*q);
		printf("Case #%d: %d\n",b+1,ans);
	}
}
