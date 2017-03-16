#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin>>n;
  priority_queue<pair<int,char> > pq;
  for(int i = 0;i < n;i++) {
    int t; cin>>t;
    if(t)
      pq.push({t,char('A' + i)});
  }
  while(!pq.empty()) {
    pair<int,char> a = pq.top(); pq.pop();
    pair<int,char> b = pq.top(); pq.pop();
    if(a.first == 1 && !pq.empty()) {
      cout<<a.second<<' ';
      pq.push(b);
    }
    else {
      cout<<a.second<<b.second<<' ';
      a.first--;
      b.first--;
      if(a.first) pq.push(a);
      if(b.first) pq.push(b);
    }
  }
  cout<<endl;
}

int main() {
  assert(freopen("input.txt","r",stdin));
  assert(freopen("output.txt","w",stdout));
  int t; cin>>t;
  for(int i = 1;i <= t;i++) {
    cerr<<"Executing Case #"<<i<<endl;
    cout<<"Case #"<<i<<": ";
    solve();
  }

}
