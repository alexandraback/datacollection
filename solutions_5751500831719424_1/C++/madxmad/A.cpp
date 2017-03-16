#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string diff(string &s){
  string ans; ans += s[0];
  REP(i,s.size()) if(s[i] != ans[ans.size()-1]){
    ans += s[i];
  }
  return ans;
}

int solve(vs &v){
  int n = v.size();
  
  string s = diff(v[0]);
  REP(i,n) if(diff(v[i]) != s) return -1;
  
  int M[n][s.size()];
  memset(M,0,sizeof M);

  REP(i,n){
    int j = 0;
    REP(k,s.size()) {
      int cnt = 0;
      while(j < v[i].size() and v[i][j] == s[k]){
        M[i][k]++;
        j++;
      }
    }
  }

  // REP(i,n){
  //   REP(j,s.size()) cout << M[i][j] << " ";
  //   cout << endl;
  // }

  int ans = 0;
  REP(k,s.size()){
    int mn = INT_MAX;
    rep(cnt,1,105){
      int sum = 0;
      REP(i,n) sum += abs(M[i][k] - cnt);
      mn = min(mn,sum);
    }
    ans += mn;
  }
  return ans;
}

int main(){ IO;
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int n;
    cin >> n;

    vs v(n);
    REP(i,n) cin >> v[i];

    int ans = solve(v);
    if(ans == -1) cout << "Fegla Won" << endl;
    else cout << ans << endl;
  }

  return 0;
}
