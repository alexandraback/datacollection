#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<bitset>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)

void solve() {
int set1=0,set2=0;
int answer1,answer2;
cin>>answer1;
REP(i,4) REP(j,4) {
  int a;cin>>a;
  if(i==answer1-1) {
    set1|=1<<a;
  }
}
cin>>answer2;
REP(i,4) REP(j,4) {
  int a;cin>>a;
  if(i==answer2-1) {
    set2|=1<<a;
  }
}
int s=set1 & set2;
if(!s) {
  cout<<"Volunteer cheated!";
  return;
}
bitset<17> bs(s);
if(bs.count()>1) {
  cout<<"Bad magician!";return;
}
REP(i,17)if(i && bs[i]) {cout<<i;return;} 
}
int main() {
int T;cin>>T;
REP(i,T) {
  cout<<"Case #"<<(i+1)<<": ";
  solve();
  cout<<endl;
}
}
