#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("A-large.in.txt");
ofstream cout("out.txt");

int n,a[1005];

int main()
{
	int t,i,j,k,caseNum=0;
	int ans1,ans2;

	cin>>t;
	while (t--)
	{
		caseNum++;
		cin>>n;
		for (i=1;i<=n;i++)
			cin>>a[i];
		ans1=0;
		for (i=2;i<=n;i++)
			if (a[i]<a[i-1])
				ans1+=a[i-1]-a[i];
		
		k=0;
		ans2=0;
		for (i=2;i<=n;i++)
			if (a[i]<a[i-1])
			{
				if (a[i-1]-a[i]>k)
					k=a[i-1]-a[i];
			}
		for (i=1;i<=n-1;i++)
			if (a[i]<k)
				ans2+=a[i];
			else
				ans2+=k;
		cout<<"Case #"<<caseNum<<": "<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}