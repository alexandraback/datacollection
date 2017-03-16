#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
#define gc getchar_unlocked
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int ans[2000010];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,n,v,a[10],cur[10],mincur,c,mini,k,b,i;
	bool f;
	sd(t);
	for(k=1;k<=t;++k)
	{
		sd(b);
		sd(n);
		for(i=0;i<b;++i)
			sd(a[i]);
		for(i=0;i<b;++i)
			cur[i]=0;
		c=1;
		cur[0]=a[0];
		ans[1]=0;
		while(true)
		{
			f=0;
			mincur=1000000000;
			for(i=0;i<b;++i)
			{
				if(cur[i]<mincur)
				{
					mincur=cur[i];
					mini=i;
				}
			}
			for(i=0;i<b;++i)
				cur[i]=cur[i]-mincur;
			for(i=0;i<b;++i)
				if(cur[i]!=0)
					f=1;
			if(!f)
				break;
			cur[mini]=a[mini];
			c++;
			ans[c]=mini;
		}
		n=n%c;
		if(n==0)
			n=c;
		printf("Case #%d: %d\n",k,ans[n]+1);
	}
	
}