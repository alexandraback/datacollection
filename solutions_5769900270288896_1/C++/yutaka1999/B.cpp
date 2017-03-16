#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

void print(int t,int ans)
{
	printf("Case #%d: %d\n",t,ans);
}
int solve1(int r,int c,int n)
{
	int two=0,thr=0;
	if(r*c%2==1) two=0;
	else two=2;
	thr+=(r-1)/2;
	thr+=(c-1)/2;
	if(c%2==1) thr+=(r-1)/2;
	else thr+=(r-2)/2;
	if(r%2==1) thr+=(c-1)/2;
	else thr+=(c-2)/2;
	int four=r*c/2-two-thr;
	int ans=0;
	if(n>=four)
	{
		ans+=four*4;
		n-=four;
	}
	else
	{
		ans+=n*4;
		n=0;
	}
	if(n>=thr)
	{
		ans+=thr*3;
		n-=thr;
	}
	else
	{
		ans+=n*3;
		n=0;
	}
	ans+=n*2;
	return ans;
}
int solve2(int r,int c,int n)
{
	int two=0,thr=0;
	if(r*c%2==1) two=4;
	else two=2;
	thr+=(r-2)/2;
	thr+=(c-2)/2;
	if(c%2==1) thr+=(r-2)/2;
	else thr+=(r-1)/2;
	if(r%2==1) thr+=(c-2)/2;
	else thr+=(c-1)/2;
	int four=(r*c+1)/2-two-thr;
	int ans=0;
	if(n>=four)
	{
		ans+=four*4;
		n-=four;
	}
	else
	{
		ans+=n*4;
		n=0;
	}
	if(n>=thr)
	{
		ans+=thr*3;
		n-=thr;
	}
	else
	{
		ans+=n*3;
		n=0;
	}
	ans+=n*2;
	return ans;
}
int ALL(int r,int c)
{
	return (r-1)*c+(c-1)*r;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int r,c,n;
		scanf("%d %d %d",&r,&c,&n);
		if(r>c) swap(r,c);//r<=c
		int oc=(r*c+1)/2;
		int ans;
		if(n<=oc) print(t,0);
		else
		{
			if(r==1)
			{
				n-=oc;
				if(c%2==0) print(t,1+(n-1)*2);
				else print(t,n*2);
			}
			else
			{
				n=r*c-n;
				print(t,ALL(r,c)-max(solve1(r,c,n),solve2(r,c,n)));
			}
		}
	}
	return 0;
}
