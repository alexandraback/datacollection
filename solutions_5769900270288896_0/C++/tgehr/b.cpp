// -*- compile-command: "g++ -g -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG b.cpp -ob && ./b " -*-
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define sz(v) ((in)(v).size())
#define all(v) (v).begin(),(v).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using LL=long long;
using in=LL;
using D=long double;
using vi=vector<int>;
using pi=pair<int,int>;
using pd=pair<D,D>;
using ti3=tuple<int,int,int>;
using vvi=vector<vi>;
using vpi=vector<pi>;
using vvpi=vector<vpi>;

int d[4][2]={{-1,0},{0,1},{0,-1},{1,0}};

void solve(){
	int r,c,n;
	cin>>r>>c>>n;
	vector<vector<bool>> v(r,vector<bool>(c));
	int res=10*c*r;
	forn(i,1<<r*c){
		int cnt=0;
		for(int cr=0,cc=0,t=i;;cc++,t>>=1){
			if(cc==c){cr++; cc=0; }
			if(cr==r) break;
			v[cr][cc]=t&1;
			cnt+=t&1;
		}
		if(cnt!=n) continue;
		int x=0;
		forn(cr,r){
			forn(cc,c){
				if(!v[cr][cc]) continue;
				forn(t,4){
					int nr=cr+d[t][0],nc=cc+d[t][1];
					if(nr<0||nr>=r||nc<0||nc>=c) continue;
					if(v[nr][nc]) x++;
				}
			}
		}
		res=min(res,x/2);
	}
	cout<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
}
