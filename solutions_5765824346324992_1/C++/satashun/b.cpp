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

#define INF (1LL<<60)
int TC;
int B;
ll N,m[1010];

bool ok(ll x){
    ll s=0;
    rep(i,B)s+=(x+m[i]-1)/m[i];
    return s>=N;
}

int main(){
    cin>>TC;
    rep(tc,TC){
	printf("Case #%d: ",tc+1);
	cin>>B>>N;
	rep(i,B)cin>>m[i];
	ll lo=0,hi=INF;
	while(hi-lo>1){
	    ll mid=(hi+lo)/2;
	    if(ok(mid))hi=mid;
	    else lo=mid;
	}
	vector<pair<ll,int> > vec;
	rep(i,B){
	    N-=lo/m[i];
	    vec.push_back(mp(lo/m[i]*m[i],i+1));
	}
	sort(vec.begin(),vec.end());
	printf("%d\n",vec[N-1].se);
    }
    return 0;
}

/*
3
2 4
10 5
3 12
7 7 7
3 8
4 2 1
*/
