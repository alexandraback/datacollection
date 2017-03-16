#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
void solve() {
  int n;cin>>n;
  vector<int> a(n);REP(i,n) cin>>a[i];
  int rval1=0;
  int rval2=0;
  vector<int> b;
  int md=0;

  REP(i,n) if(i) {
    int delta=a[i]-a[i-1];
    md=max(md, -delta);
    if(delta<0) rval1-=delta;
  }
  REP(i,n-1) {
    rval2+=min(md,a[i]); 
  }
  cout<<rval1<<" "<<rval2;
}
int main() {
int T;cin>>T;
REP(i,T) {
  cout<<"Case #"<<(i+1)<<": ";
  solve();
  cout<<endl;
}
}
