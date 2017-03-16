#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
struct node
{
	ll n;
	ll t;
	node *nx;
};
ll b,n;
ll k[1100];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		scanf("%lld%lld",&b,&n);
		for (int i=0;i<b;++i)
		  scanf("%lld",&k[i]);
		ll mcm=k[0];
		for (int i=1;i<b;++i)
		  mcm=mcm/(gcd(mcm,k[i]))*k[i];
		ll cnt=0ll;
		for (int i=0;i<b;++i)
		   cnt+=mcm/k[i];
		n%=cnt;
		if (n==0) n=cnt;
		node *head=new node;
		head->n=head->t=-1;
		head->nx=NULL;
		for (int i=0;i<b;++i)
		{
			node *p=head;
			for (ll j=0;j<=mcm;j+=k[i])
			{
				
				while (p->nx!=NULL&&p->nx->t<=j) p=p->nx;
				node *q=new node;
				q->n=i;q->t=j;q->nx=p->nx;p->nx=q;
			}
		}
		node *ans=head;
		while (n--) ans=ans->nx;
		printf("Case #%d: %d\n",TT,ans->n+1);
		
	}
}
