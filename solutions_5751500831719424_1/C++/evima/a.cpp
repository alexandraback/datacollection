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

int N;
string s[111];
vector<pair<char,int>> v[111];

void main2(){
	cin>>N;
	rep(i,N)cin>>s[i];
	rep(i,N){
		v[i].clear();
		string &t = s[i];
		char c=0;
		int l = 0;
		rep(j,sz(t)){
			if(t[j] != c){
				if(c!=0){
					v[i].pb(mp(c,l));
				}
				l = 1;
				c = t[j];
			}
			else l++;
		}
		v[i].pb(mp(c,l));
	}
	int m = sz(v[0]);
	rep(i,N){
		if(sz(v[i]) != m){
			cout<<"Fegla Won"<<endl;
			return;
		}
	}
	int ans = 0;
	rep(j,m){
		char c = v[0][j].fir;
		vi w;
		rep(i,N){
			if(v[i][j].fir != c){
				cout<<"Fegla Won"<<endl;
				return;
			}
			w.pb(v[i][j].sec);
		}
		int res = INF;
		rep(fix,sz(w)){
			int res2 = 0;
			rep(i,N){
				res2 += abs(v[i][j].sec - v[fix][j].sec);
			}
			res = min(res, res2);
		}
		ans += res;
	}
	cout << ans << endl;
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
