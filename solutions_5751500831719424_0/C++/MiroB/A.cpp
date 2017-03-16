#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef pair<char, int> P;
vector<P> repr(string s) {
  vector<P> rval;
  REP(i,s.size()) {
    int a=rval.size();
    if(i==0 || s[i]!=s[i-1]) {
      rval.push_back(P(s[i],1));
    } else {
      rval[a-1].second++;
    }
  }
//  REP(i,rval.size()) cout<<rval[i].first<<" "<<rval[i].second<<" ";
 // cout<<endl;
  return rval;
}
bool bad() {
  cout<<"Fegla Won";
  return 0;
}
bool solve() {
  int count;
  cin>>count;
  vector<string> s(count);
  REP(i,count) cin>>s[i];
  vector<vector<P > > h(count);
  REP(i,count) h[i]=repr(s[i]);
  int n=h[0].size();
  REP(i,count) if ((int)h[i].size()!=n) return bad();
  REP(str,count) {
    REP(i,n) if(h[str][i].first!=h[0][i].first) return bad();
  }
  int rval=0;
  REP(j,n) {
    vector<int> a;
    REP(i,count) a.push_back(h[i][j].second);
    int mn=-1;
    REP(cmp, count) {
      int now=0;
      REP(i,count) {
        now+=abs(a[i]-a[cmp]);
      }
      if(mn==-1 || mn>now) mn=now;
    }
    rval+=mn;
  }
  cout<<rval;
  return 0;
}
int main() {
int T;cin>>T;
REP(i,T) {
  cout<<"Case #"<<(i+1)<<": ";
  solve();
  cout<<endl;
}
}
