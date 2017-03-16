#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data,from;
}p[111];
bool cmp(node a,node b)
{return a.data>b.data;
}
int test,n;
int main()
{
	freopen("A-large (1).in","r",stdin);
	freopen("111111111.out","w",stdout);
	cin>>test;
	for (int kk=1;kk<=test;kk++)
	{
		cin>>n;
		printf("Case #%d: ",kk); 
		for (int i=0;i<n;i++)
		scanf("%d",&p[i].data),p[i].from=i;
		sort(p,p+n,cmp);
		while (p[0].data-p[1].data) printf("%c ",p[0].from+'A'),p[0].data--;
		for (int i=2;i<n;i++)
		for (int j=1;j<=p[i].data;j++) printf("%c ",p[i].from+'A');
		for (int i=1;i<=p[0].data;i++) printf("%c%c ",p[0].from+'A',p[1].from+'A');
		cout<<endl;
	}
	return 0;
}
