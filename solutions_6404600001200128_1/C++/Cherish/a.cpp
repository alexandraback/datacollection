#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

int a[1010];

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		int n;
		cin>>n;
		Rep(i,n) scanf("%d",a+i);
		int ans1=0, ans2=0, ma=-1;
		for(int i=1;i<n;++i) {
			if(a[i]>a[i+1]) ans1 += a[i]-a[i+1];
			if(a[i]-a[i+1]>ma)ma=a[i]-a[i+1];
		}
		for(int i=1;i<n;++i){
			if(a[i]<ma)ans2+=a[i];
			else ans2+=ma;
		}
		printf("Case #%d: %d %d\n", cas, ans1, ans2);
	}
	return 0;
}

