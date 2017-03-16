#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#define REP(it,end) for (int it = 1; it <= (end); it++)
#define FOR(it,begin,end) for (int it = (begin); it <= (end); it++)
#define ROF(it,begin,end) for (int it = (begin); it >= (end); it--)
using namespace std;
typedef long long ll;
ll r,c,sum,pos,tr,tc,num3,num2;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void check(int x,int y)
{
	int tx,ty,con=0;
	//cout <<x<<" "<<y<<endl;
	for(int i=0;i<4;i++)
	{
		tx=x+dx[i];
		ty=y+dy[i];
		if(tx<0||tx>=r||ty<0||ty>=c)continue;
		if((tx+ty)&1)con++;
	}
	if(con==3)num3++;
	if(con==2)num2++;
}
void check1(int x,int y)
{
	int tx,ty,con=0;
	//cout <<x<<" "<<y<<endl;
	for(int i=0;i<4;i++)
	{
		tx=x+dx[i];
		ty=y+dy[i];
		if(tx<0||tx>=r||ty<0||ty>=c)continue;
		if(!((tx+ty)&1))con++;
	}
	if(con==3)num3++;
	if(con==2)num2++;
}
ll case1(ll n)
{
	int i,tmp;
	sum=r*(c-1)+(r-1)*c;
	num3=num2=0;
	tr=max(r-2,0ll);
	tc=max(c-2,0ll);
	pos=(tr*tc+1)/2;
	//cout <<pos<<" "<<n<<endl;
	if(n>=pos)
	{
		sum-=pos*4;
		n-=pos;
	}
	else 
	{
		sum-=n*4;
		n=0;
	}
	for(i=0;i<c;i+=2)check(0,i);
	if(i==c+1)tmp=2;
	else tmp=1;
	for(i=tmp;i<r;i+=2)check(i,c-1);
	if(i==r+1)tmp=c-3;
	else tmp=c-2;
	for(i=tmp;i>=0;i-=2)check(r-1,i);
	if(i==-2)tmp=r-3;
	else tmp=r-2;
	for(i=tmp;i>0;i-=2)check(i,0);
	//cout <<sum<<" "<<n<<" "<<num3<<" "<<num2<<" "<<pos<<endl;
	if(n>=num3)
	{
		sum-=num3*3;
		n-=num3;
	}
	else
	{
		sum-=n*3;
		n=0;
	}
	//cout <<sum<<" "<<n<<" "<<num3<<" "<<num2<<" "<<pos<<endl;
	if(n>=num2)
	{
		sum-=num2*2;
		n-=num2;
	}
	else
	{
		sum-=n*2;
		n=0;
	}
	//cout <<sum<<" "<<n<<" "<<num3<<" "<<num2<<" "<<pos<<endl;
	return sum;
}
ll case2(ll n)
{
	int i,tmp;
	sum=r*(c-1)+(r-1)*c;
	num3=num2=0;
	tr=max(r-2,0ll);
	tc=max(c-2,0ll);
	pos=tr*tc-(tr*tc+1)/2;
	//cout <<pos<<" "<<n<<" "<<sum<<endl;
	if(n>=pos)
	{
		sum-=pos*4;
		n-=pos;
	}
	else 
	{
		sum-=n*4;
		n=0;
	}
	//cout <<pos<<" "<<n<<" "<<sum<<endl;
	for(i=1;i<c;i+=2)check1(0,i);
	if(i==c+1)tmp=2;
	else tmp=1;
	for(i=tmp;i<r;i+=2)check1(i,c-1);
	if(i==r+1)tmp=c-3;
	else tmp=c-2;
	for(i=tmp;i>=0;i-=2)check1(r-1,i);
	if(i==-2)tmp=r-3;
	else tmp=r-2;
	for(i=tmp;i>=0;i-=2)check1(i,0);
	//cout <<sum<<" "<<n<<" "<<num3<<" "<<num2<<" "<<pos<<endl;
	if(n>=num3)
	{
		sum-=num3*3;
		n-=num3;
	}
	else
	{
		sum-=n*3;
		n=0;
	}
	if(n>=num2)
	{
		sum-=num2*2;
		n-=num2;
	}
	else
	{
		sum-=n*2;
		n=0;
	}
	//cout <<sum<<" "<<n<<" "<<num3<<" "<<num2<<" "<<pos<<endl;
	return sum;
}
int main()
{
	int T,i,tmp;
	ll n;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%lld %lld %lld",&r,&c,&n);
		pos=(r*c+1)/2;	
		if(n<=pos)printf("Case #%d: %lld\n",cas,0ll);
		else
		{
			printf("Case #%d: %lld\n",cas,min(case1(r*c-n),case2(r*c-n)));
		}
	}
	return 0;
}
