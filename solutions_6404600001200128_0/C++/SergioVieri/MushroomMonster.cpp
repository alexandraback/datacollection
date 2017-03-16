#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define INF (int)1e9
typedef long long LL;
using namespace std;

int arr[1005];

#define FMAX(a,b) ((a>b)?a:b)
#define FMIN(a,b) ((a<b)?a:b)

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t, n, no = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < n; i++ ){
			scanf("%d",&arr[i]);
		}
		int a1 = 0, a2 = 0, mx = -INF;
		for(int i = 1; i < n; i++ ){
			a1 += FMAX(arr[i-1]-arr[i],0);
			mx = FMAX(mx,arr[i-1]-arr[i]);
		}
		for(int i = 0; i < n-1; i++ ){
			a2 += FMIN(arr[i],mx);
		}
		printf("Case #%d: %d %d\n",++no,a1,a2);
	}
	return 0;
}


