#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int t;
	cin>>t;
	rep(x,0,t){
		int n;
		cin>>n;
		vi d(n);
		int sum=0;
		pair<int,char> p[27];
		rep(i,0,n){
			cin>>d[i];
			p[i].se='A'+i;
			p[i].fi=d[i];
			sum+=d[i];
		}
		cout<<"Case #"<<x+1<<":";
		while(sum>0) {
			sort(p,p+n);
			reverse(p,p+n);
			cout<<" "<<p[0].se;
			p[0].fi--;
			sum--;
			sort(p,p+n);
			reverse(p,p+n);
			if(p[0].fi>sum/2){
		    	cout<<p[0].se;
		    	p[0].fi--;
		    	sum--;
		    }
		}
		cout<<endl;
	}
}