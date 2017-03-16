#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define pb(a) push_back(a)
#define pr(a) cout<<(a)<<endl
#define PR(a,b) cout<<(a)<<" "<<(b)<<endl
#define R cin>>
#define F first
#define S second
#define ll long long
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

int main() {
  int T;
  R T;
  REP(t,1,T+1) {
    int n,b;
    cin >> b >> n;
    int a[b];
    rep(i,b) R a[i];
    int d=1;
    rep(i,b) d=a[i]/__gcd(d,a[i])*d;
    vector<int> v;
    rep(i,b) v.pb(i+1);
    REP(i,1,d) {
      rep(j,b) {
	if(i%a[j]==0) v.pb(j+1);
      }
    }
    n--;
    int ans=v[n%v.size()];
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
