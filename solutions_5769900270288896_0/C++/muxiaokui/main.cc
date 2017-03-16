#include <cstdio>
#include <cstring>

const int MAXINT=10000000;
int r,c,n;
int ans;
int a[16][16];

int check() {
	int i,j,ans=0;
	for (i=1;i<r;i++)
		for (j=0;j<c;j++)
			if (a[i][j]==1&&a[i-1][j]==1) ans++;
	for (i=0;i<r;i++)
		for (j=1;j<c;j++)
			if (a[i][j]==1&&a[i][j-1]==1) ans++;
	return ans;
}
int dfs(int i,int j,int n) {
	if (n==0) return check();
	if (i>=r) return MAXINT;
	int ii,jj;
	if (j+1>=c) {
		ii=i+1;jj=0;
	} else {
		ii=i;jj=j+1;
	}
	int ans1=dfs(ii,jj,n);
	a[i][j]=1;
	int ans2=dfs(ii,jj,n-1);
	a[i][j]=0;
	if (ans1<ans2) return ans1;
	return ans2;
}

int main() {
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%d%d",&r,&c,&n);
		ans=MAXINT;
		memset(a,0,sizeof(a));
		printf("Case #%d: %d\n",tt,dfs(0,0,n));
	}
	return 0;
}
