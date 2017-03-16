#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1010
using namespace std;
int n,ans1,ans2;
void read()
{
	ans1=ans2=0;
	static int a[maxn];
	int maxv=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(i>1)
			ans1+=max(0,a[i-1]-a[i]),maxv=max(maxv,a[i-1]-a[i]);
	}
	for(int i=1;i<n;++i)
		ans2+=min(maxv,a[i]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,C=0;
	for(cin>>T;T;--T)
	{
		read();
		printf("Case #%d: %d %d\n",++C,ans1,ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
