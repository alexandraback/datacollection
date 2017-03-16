#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("B-small-attempt0.in.txt");
ofstream cout("out.txt");


int a[10],n,f[10],m;

int ggcd(int a, int b)
{
	int c=a%b;
	while (c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

int main()
{
	int t,i,j,k,l,caseNum;

	cin>>t;
	while (t--)
	{
		caseNum++;
		cin>>n>>m;
		for (i=1;i<=n;i++)
			cin>>a[i];

		k=a[1];
		for (i=2;i<=n;i++)
		{
			j=ggcd(k,a[i]);
			k=k*a[i]/j;
		}
		l=0;
		for (i=1;i<=n;i++)
		{
			l+=k/a[i];
		}
		//printf("%d\n",l);
		m=m%l;
		if (m==0) m=l;

		memset(f,0,sizeof(f));
		for (i=1;i<=m;i++)
		{
			k=0;
			for (j=1;j<=n;j++)
				if (k==0||f[j]<f[k])
					k=j;
			f[k]+=a[k];
			//printf("%d\n",k);
		}
		cout<<"Case #"<<caseNum<<": "<<k<<endl;
	}
	return 0;
}