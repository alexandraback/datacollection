#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;
const int N = int(1e4);         
int T,n, m[N],mx,k;
ll ans1,ans2;
int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d",&n);
		ans1 = 0;
		ans2 = 0;
		mx = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&m[i]);
			k = max(0,m[i-1] - m[i]);
			mx = max(mx,k);
			ans1 += k;
		}
		for(int i=1;i<n;i++){
			ans2 += min(m[i],mx);
		}
		printf("%lld %lld\n",ans1,ans2 );
	}
return 0;
}
