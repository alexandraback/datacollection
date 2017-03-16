#include<cstdio>
#define ll long long

ll L,R;

int n,b[1100],B;

ll Fun(ll Time)
{
	ll p(0);
	for(int i=0;i<B;i++)
		p+=(Time+b[i]-1)/b[i];
	return p;
}

int main()
{
	int i,Case,TestCase;
//	freopen("b.in","rb",stdin);
//	freopen("b.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d",&B,&n);
		for(i=0;i<B;i++)
			scanf("%d",b+i);
		L=-1;
		R=100000ll*1000000000ll;
		for(;L+1<R;)
			if(Fun((L+R)/2)>=n)
				R=(L+R)/2;
			else L=(L+R)/2;
		n-=Fun(L);
		for(i=0;i<B;i++)
			if(!(L%b[i]))
			{
				n--;
				if(n<=0)break;
			}
		printf("Case #%d: %d\n",Case,i+1);
	}
	return 0;
}
