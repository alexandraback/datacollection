#include <iostream>
#include <queue>
#include <string>

using namespace std;

void solve() {
  int n;
  cin >> n;
  priority_queue < pair < int, char > > q;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    q.push(make_pair(x, 'A' + i));
  }
  while(q.size() > 2){
    pair < int, char > cur = q.top();
    q.pop();
    cout << cur.second << ' ';
    --cur.first;
    if(cur.first)
      q.push(cur);
  }
  string now;
  int cnt;
  while(!q.empty()){
    cnt = q.top().first;
    now += q.top().second;
    q.pop();
  }
  for(int i = 0; i < cnt; ++i)
    cout << now << ' ';
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": ";
    solve();
  }
}
