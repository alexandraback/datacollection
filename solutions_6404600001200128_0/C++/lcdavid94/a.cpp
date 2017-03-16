#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1100];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	cin>>T;
	for (int TT=1;TT<=T;++TT)
	{
		cin>>n;
		for (int i=0;i<n;++i)
			cin>>a[i];
		int ans1=0;
		for (int i=1;i<n;++i)
		  if (a[i-1]>a[i]) ans1+=a[i-1]-a[i];
		int m=0,ans2=0;
		for (int i=1;i<n;++i)
		  if (a[i-1]-a[i]>m) m=a[i-1]-a[i];
		for (int i=0;i<n-1;++i)
		  if (a[i]>m) ans2+=m; else ans2+=a[i];
		cout<<"Case #"<<TT<<": "<<ans1<<" "<<ans2<<endl;
	}
}
