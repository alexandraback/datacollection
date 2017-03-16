#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1010];
int main()
{
	int T,no=1;
	cin>>T;
	while(no<=T)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int a1=0,a2=0;
		for(int i=1;i<n;i++)
			if(a[i]<a[i-1])
				a1+=a[i-1]-a[i];
		int t=0;
		for(int i=1;i<n;i++)
			t=max(t,a[i-1]-a[i]);
		for(int i=0;i<n-1;i++)
			a2+=min(t,a[i]);
		printf("Case #%d: %d %d\n",no++,a1,a2);
	}
}
