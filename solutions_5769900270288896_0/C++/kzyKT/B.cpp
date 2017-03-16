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
  REP(tt,1,T+1) {
    int r,c,n;
    cin >> r >> c >> n;
    int ans=MAX;
    rep(t,1<<(r*c)) {
      if(__builtin_popcount(t)!=n) continue;
      int k=0;
      int a[r][c];
      memset(a,0,sizeof(a));
      rep(i,r) {
	rep(j,c) {
	  if(t&(1<<k)) a[i][j]=1;
	  k++;
	}
      }
      int cnt=0;
      rep(i,r) {
	rep(j,c) {
	  if(j<c-1 && a[i][j] && a[i][j+1]) cnt++;
	  if(i<r-1 && a[i][j] && a[i+1][j]) cnt++;
	}
      }
      ans=min(ans,cnt);
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }
  return 0;
}
