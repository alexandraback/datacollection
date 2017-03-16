#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

int TC;
int n,a[1010];

int main(){
    cin>>TC;
    rep(tc,TC){
	printf("Case #%d: ",tc+1);
	cin>>n;
	rep(i,n)cin>>a[i];


	int mi=0,y=0,z=0;
	rep(i,n-1)y+=max(0,a[i]-a[i+1]);
	rep(i,n-1)mi=max(mi,a[i]-a[i+1]);
	rep(i,n-1)z+=min(a[i],mi);
	printf("%d %d\n",y,z);
    }
    return 0;
}
