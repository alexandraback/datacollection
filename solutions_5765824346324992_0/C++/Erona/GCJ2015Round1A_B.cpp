#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1005;
int m[N];
struct Barber
{
	int id;
	long long time;
	bool operator<(const Barber &rhs) const
	{
		if(time==rhs.time)return id>rhs.id;
		return time>rhs.time;
	}
};
/*
Case #1: 1
Case #2: 3
Case #3: 2
Case #4: 5
Case #5: 2
Case #6: 5
Case #7: 1
*/
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
int gj(int n)
{
	int x=m[n];
	for(int i=1;i<n;i++)x=lcm(x,m[i]);
	int z=0;
	for(int i=1;i<=n;i++)z+=x/m[i];
	//printf("gj:%d\n",z);
	return z;
}
int main()
{
	freopen("/Users/Erona/Downloads/B-small-attempt1 (1).in","r",stdin);
	freopen("/Users/Erona/Downloads/B-small-attempt1 (1).out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		int b,n;
		scanf("%d%d",&b,&n);
		for(int i=1;i<=b;i++)scanf("%d",m+i);
		priority_queue<Barber> barber;
		for(int i=1;i<=b;i++)barber.push({i,0});
		int wtf=gj(b);
		n=n%wtf;
		if(!n)n=wtf;
		for(int i=1;i<n;i++)
		{
			Barber t=barber.top();barber.pop();
			//printf("%d:%d\n",i,t.id);
			t.time+=m[t.id];
			barber.push(t);
		}
		printf("Case #%d: %d\n",cs,barber.top().id);
	}
	return 0;
}