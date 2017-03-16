#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int ll;
void solve() {
int n,t;cin>>n>>t;
vector<long long int> a(n);
REP(i,n) cin>>a[i];
long long start=0;
long long end=100000000000ll;
while(start<end) {
  long long int mid=(start+end)/2;
  long long int cnt=0;
  REP(i,n) cnt+=mid/a[i]+1;
  if(cnt<t) start=mid+1;else end=mid;
}
long long int Z=end;
//cout<<"time="<<Z<<endl;
long long x=t;
REP(i,n) x-=(Z-1)/a[i]+1;
//cout<<"x="<<x<<endl;
REP(i,n) if(Z%a[i]==0) {
  --x;
  if(!x) {
    cout<<(i+1);
    return;
  }
}

}
int main() {
int T;cin>>T;
REP(i,T) {
  cout<<"Case #"<<(i+1)<<": ";
  solve();
  cout<<endl;
}
}
