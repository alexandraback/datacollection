#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
string a[1000];
int b[1000],c[1000];
bool check(int n)
{
	int i;
	for(i=1;i<=n;i++)
		if (b[i]!=a[i].length()) return false;
	return true;
}
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);

	int ii,tt,n,mid,tot,i,t1;
	char x;
	bool d;
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d",&n);
	//	printf("%d\n",n);
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		//	cout<<a[i]<<endl;
			b[i]=0;
		}
		d=true;
		tot=0;
		while(1)
		{
			if (check(n)) break;
			x=a[1][b[1]];
			for(i=1;i<=n;i++)
			{
				if (a[i][b[i]]!=x) d=false;
				t1=b[i];
				while(1)
				{
					if (b[i]>=a[i].length()) break;
					b[i]++;
				    if (a[i][b[i]]!=x) break;
				}
				c[i]=b[i]-t1;
			}
			sort(c+1,c+1+n);
			if (c[1]==0) {d=false;break;}
			mid=n/2+1;
			for(i=1;i<=n;i++)
				tot+=abs(c[i]-c[mid]);
		}
		if (d==false) printf("Case #%d: Fegla Won\n",ii);
		else
			printf("Case #%d: %d\n",ii,tot);
	}
	return 0;
}