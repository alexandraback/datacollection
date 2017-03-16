#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int a[20][20];
int r,c,n,ans;

void dfs(int x,int y,int s,int sum) {
	if (sum>=ans) return;
	if (y==c) x++,y=0;
	if (x==r) {
		if (s==n) ans=sum;
		return;
	}
	if (s+1<=n) {
		a[x][y]=1;
		int t=0;
		if (x && a[x-1][y]) t++;
		if (y && a[x][y-1]) t++;
		dfs(x,y+1,s+1,sum+t);
		a[x][y]=0;
	}
	dfs(x,y+1,s,sum);
}

int main() {
	int tt;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		scanf("%d%d%d",&r,&c,&n);
		ans=INF;
		memset(a,0,sizeof(a));
		dfs(0,0,0,0);
		printf("Case #%d: %d\n",te,ans);
	}
}
