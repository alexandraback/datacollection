#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int maxn=1100;

int n;
int m[maxn];
void solve(int icase) {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",m+i);
	
	int ans1=0, ans2=0;
	for(int i=2;i<=n;i++)
		if(m[i]<m[i-1])
			ans1+=m[i-1]-m[i];
	
	int r=0;
	for(int i=2;i<=n;i++)
		if(m[i]<m[i-1])
			r=max(r,m[i-1]-m[i]);
	for(int i=2;i<=n;i++)
		ans2+=m[i-1]-max(m[i-1]-r,0);

	//printf("%d\n",r);
	printf("Case #%d: %d %d\n",icase,ans1,ans2);
}
int main() {
	int T;
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
