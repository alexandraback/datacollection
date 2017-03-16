#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;
int dx[4]={1,0,-1,0};
int dy[4]={0,1, 0,-1};
int mp[20000][20000];

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    ll ans = 0;
    ll c,r,n;
    cin>>r>>c>>n;
    ll t = r*c/2 + (r*c)%2;
    if(t>=n) {
      printf("Case #%d: 0\n", times);
      continue;
    }
    rep(i, r){
      rep(j, c){
        mp[i][j]=0;
      }
    }
    vector<int> ev, od;
    rep(i, r){
      rep(j,c){
        int cnt=0;
        rep(d,4){
          int nx=i+dx[d];
          int ny=j+dy[d];
          if(0<=nx&&nx<r&&0<=ny&&ny<c)cnt++;
        }
        if((i+j)%2==0){
          ev.push_back(cnt);
        }else{
          od.push_back(cnt);
        }
      }
    }
    sort(ev.begin(), ev.end());
    sort(od.begin(), od.end());
    int evnum=n-od.size();
    int odnum=n-ev.size();
    int ans1 = 0, ans2=0;
    rep(i, evnum){
      ans1+=ev[i];
    }
    rep(i, odnum){
      ans2+=od[i];
    }
    printf("Case #%d: %d\n", times, min(ans1,ans2));
  }

}
