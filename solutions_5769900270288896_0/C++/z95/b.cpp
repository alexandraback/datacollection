#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define FOR(i,n) for(int i=0;i<n;++i)

#include <unordered_set>

using namespace std;


int min(int a,int b) {
	return a<b?a:b;
}

int reverse(int x) {
	int ans=0;
	while(x) {
		ans*=10;
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int pole[47][47];

int R,C,N;

int solve(int i,int j,int n) {
	if(j==C) return solve(i+1,0,n);
	if(n==0) return 0;
	if(i==R) return 1<<28;
	int x,y;
	// daj
	pole[i][j] = 1;
	int ans=0;
	if(i>0 && pole[i-1][j]==1) ++ans;
	if(j>0 && pole[i][j-1]==1) ++ans;
	x = solve(i,j+1,n-1)+ans;
	pole[i][j] = 0;
	y = solve(i,j+1,n);
	return min(x,y);
}


int main(void) {
	int t;
	scanf("%d",&t);
	FOR(k,t) {
		scanf("%d%d%d",&R,&C,&N);
		FOR(i,47) FOR(j,47) pole[i][j]=0;
		printf("Case #%d: %d\n",k+1,solve(0,0,N));
	}
}