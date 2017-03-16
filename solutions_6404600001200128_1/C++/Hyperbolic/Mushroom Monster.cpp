#include <stdio.h>
void solve(int);
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
int x[1010];
void solve(int T)
{
	int a,sum1=0,sum2=0,max=0,i;
	scanf("%d",&a);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	for(i=1;i<a;i++) if(x[i+1]<x[i]) sum1+=(x[i]-x[i+1]);
	for(i=1;i<a;i++) max=max>x[i]-x[i+1]?max:x[i]-x[i+1];
	for(i=1;i<a;i++)
	{
		sum2+=x[i]<max?x[i]:max;
	}
	printf("Case #%d: %d %d\n",T,sum1,sum2);
}
