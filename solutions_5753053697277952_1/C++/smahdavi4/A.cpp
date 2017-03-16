// IN THE NAME OF ALLAH
#include<bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define F(i,a,b) for(ll i=(a) ; i<=(b) ; i++)
#define PI 3.1415926535897932384626433832795
#define eps 0.000001
using namespace std;
typedef long long ll;
typedef float ld;
const ll M=1e5+100;

ll a[26],n;

inline bool more(ll x){
	ll s=0;
	F(i,0,25) s+=a[i];
	if(s<(2*a[x])) return true;
	return false;
}

ll mx1(){
	ll mx=-1,po;
	F(i,0,25) {
		if(a[i]>mx) mx=a[i],po=i;
	}
	return po;
}

ll mx2(){
	ll mx=-1,d=a[mx1()],ct=0,po;
	F(i,0,25) if(a[i]==d) ct++,po=i;
	if(ct>=2) return po;
	F(i,0,25) if(a[i]!=d && a[i]>mx) mx=a[i],po=i;
	return po;
}

void in(){
	cin>>n;
	F(i,0,n-1) cin>>a[i];
}

void clr(){
	fill(a,a+26,0);
}

void solve(){
	ll s=0;
	F(i,0,25) s+=a[i];
	while(s){
		ll x=mx1(),y;
		a[x]--;
		bool c=false;
		F(i,0,25) if(more(i)) c=true;
		if(!c){
			cout<<char('A'+x)<<" ";
			s--;
		}
		else{
			a[x]++;
			y=mx2();
			a[x]--;
			a[y]--;
			cout<<char('A'+x)<<char('A'+y)<<" ";
			s-=2;
		}
	}
	cout<<endl;
}



int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//cout << setprecision(22) << fixed;
ios::sync_with_stdio(false);


ll tst; cin>>tst;
F(ii,1,tst){
	clr();
	in();
	cout<<"Case #"<<ii<<": ";
	solve();
}





return 0;   
}
