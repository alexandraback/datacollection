#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert> 
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
int nb,nm;
int ind[1001];
long long hasbegin(long long it)
{
	if(it==-1)return 0;
	long long res=0;
	rep(i,nb)
	{
		res+=it/ind[i]+1;
	}
	return res;
}
void task()
{
	scanf("%d%d",&nb,&nm);
	rep(i,nb)scanf("%d",&ind[i]);
	long long tl=-1,tr=1000000000000000ll,tm;
	while(tl+1!=tr)
	{
		//cout<<tl<<","<<tr<<endl;
		tm=(tl+tr)/2;
		if(hasbegin(tm)>=nm)tr=tm;else tl=tm;
	}
	int tget=hasbegin(tl);
	rep(i,nb)
	{
		if(tr%ind[i]==0)++tget;
		if(tget==nm)
		{
			printf("%d\n",i);
			return;
		}
	}
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
