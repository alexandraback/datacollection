// -*- compile-command: "g++ -g -Wno-return-type -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG a.cpp -oa && ./a " -*-
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
#define int LL
#define vc vector
#define pb push_back
#define pr pair
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define f(i,n) for(int i=0;i<(n);i++)
#define fv(i,v) f(i,sz(v))

bool check(vc<int>& p){
	int mx=0,sum=0;
	fv(i,p){
		if(p[i]<0) return false;
		if(p[i]>p[mx]) mx=i;
		sum+=p[i];
	}
	if(p[mx]>sum/2) return false;
	return true;
}

void solve(){
	int n;
	cin>>n;
	vc<int> p(n);
	bool done=true;
	f(i,n) cin>>p[i], done&=!p[i];
	bool first=true;
	while(!done){
		int mx=0,smx=0;
		f(i,n) if(p[i]>p[mx]) mx=i;
		if(!mx) smx++;
		f(i,n) if(i!=mx&&p[i]>p[smx]) smx=i;
		bool ok=true;
		p[mx]--;
		p[smx]--;
		if(!check(p)){
			ok=false;
			p[smx]++;
		}
		assert(check(p));
		cout<<(first?"":" ");
		first=false;
		if(ok){
			cout<<(char)('A'+mx)<<char('A'+smx);
		}else cout<<(char)('A'+mx);
		done=true;
		f(i,n) done&=!p[i];
	}
	cout<<'\n';
}

main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	for(int t=1,x;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
}
