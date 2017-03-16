#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

struct ST {
  int v;
  char c;
};
bool operator<(const ST& a, const ST& b){
  return a.v < b.v;
}

void solve(const vector<int>& v){
  priority_queue<ST> que;
  rep(i,v.size()){
    que.push((ST){v[i], 'A'+i});
  }

  while(true){
    ST x = que.top(); que.pop();
    ST y = que.top(); que.pop();
    if(que.empty()){
      int mn = min(x.v, y.v);
      while(x.v != mn){
        cout << " " << x.c;
        x.v--;
      }
      while(y.v != mn){
        cout << " " << y.c;
        y.v--;
      }
      while(x.v > 0){
        cout << " " << x.c << y.c;
        x.v--;
      }
      break;
    }else{
      if(que.size() == 1){
        ST z = que.top(); que.pop();
        if(y.v == 1 && z.v == 1){
          cout << " " << x.c;
          x.v--;
          if(x.v > 0) que.push(x);
          que.push(y);
          que.push(z);
        }else{
          cout << " " << x.c;
          x.v--;
          if(y.v > 0){
            cout << y.c;
            y.v--;
          }
          if(x.v > 0) que.push(x);
          if(y.v > 0) que.push(y);
          que.push(z);
        }
      }else{
        cout << " " << x.c << y.c;
        x.v--;
        y.v--;
        if(x.v > 0) que.push(x);
        if(y.v > 0) que.push(y);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    ll N;
    cin >> N;
    vector<int> v;
    rep(i,N){
      int a;
      cin >> a;
      v.push_back(a);
    }
    cout << "Case #" << t+1 << ":";
    solve(v);
    cout << endl;
  }
  
  return 0;
}

