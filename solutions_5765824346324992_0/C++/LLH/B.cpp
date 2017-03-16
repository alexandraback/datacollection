#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
using namespace std;
#define double long double
typedef long long int64;


const int maxn=1100;

int n,cnt;
int btime[maxn];
//int64 heap[maxn];
int64 enter_before(int64 t) {
	int64 ans=0;
	for(int i=1;i<=n;i++)
		ans+=(t+btime[i]-1)/btime[i];
	return ans;
}
void solve(int icase) {
	int cnt;
	scanf("%d%d",&n,&cnt);
	for(int i=1;i<=n;i++) {
		scanf("%d",btime+i);
	}
	
	int64 left=0, right=100000000000000LL;
	while(left<right) {
		int64 mid=(left+right+1)/2;
		if(enter_before(mid)<cnt)
			left=mid;
		else
			right=mid-1;
	}
	int ans=-1;
	int64 t=left;
	cnt-=enter_before(t);
	for(int i=1;i<=n;i++)
		if(t%btime[i]==0) {
			cnt--;
			if(cnt==0)
				ans=i;
		}
	
	printf("Case #%d: %d\n",icase,ans);
	
}
int main() {
	int T;
	//solve(1);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
	scanf("%*s");
	return 0;
}
/*
4
6
23 90 40 0 100 9
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
*/
