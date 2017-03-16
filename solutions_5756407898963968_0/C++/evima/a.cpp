// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;



void main2(){
	int r,a[5][5],s,b[5][5];
	cin>>r;
	rep(i,4)rep(j,4)cin>>a[i][j];
	cin>>s;
	rep(i,4)rep(j,4)cin>>b[i][j];
	vi v;
	rep(i,4)rep(j,4){
		if(a[r-1][i] == b[s-1][j])v.pb(a[r-1][i]);
	}
	if(sz(v)>=2)cout<<"Bad magician!"<<endl;
	else if(sz(v)==0)cout<<"Volunteer cheated!"<<endl;
	else cout<<v[0]<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		main2();
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
