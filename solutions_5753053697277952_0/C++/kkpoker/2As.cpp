#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1050;
int n;
struct per
{
	int x;int id;
} p[30];

bool cmp(per A,per B)
{
	return A.x>B.x; 
}

int stk[N],top;

int main()
{
	freopen("A2-small-attempt0.in","r",stdin);
	freopen("A2-small-attempt0.out","w",stdout);
	int T;
	cin>>T;

	for(int kk=1;kk<=T;kk++)
	{
		printf("Case #%d: ",kk);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			p[i].x=0;p[i].id=i;
		}
		top=0;
		int now=0;
		for(int i=1;i<=n;i++) {scanf("%d",&p[i].x);now+=p[i].x;}
		sort(p+1,p+1+n,cmp);
		while(now>0)
		{
			stk[++top]=p[1].id;p[1].x--;
			sort(p+1,p+1+n,cmp);
			now--;
		}
		//cout<<top<<' ';
		if(top%2==1)
		{
			printf("%c ",stk[1]+'A'-1);
			for(int i=2;i<=top;i++)
			{
				printf("%c",stk[i]+'A'-1);
				if(i%2==1) printf(" ");
			}
			printf("\n");
		}
		else 
		{
			for(int i=1;i<=top;i++)
			{
				printf("%c",stk[i]+'A'-1);
				if(i%2==0) printf(" ");
			}
			printf("\n");
		}
	}

	return 0; 
}

