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
  vector<char> w;
  vector<int> c;
};
bool operator==(ST& a, ST& b){
  if(a.w.size() != b.w.size()) return false;
  rep(i,a.w.size()){
    if(a.w[i] != b.w[i]) return false;
  }
  return true;
}

ST calc(const string& str){
  ST ret;
  char c = '-';
  int cnt = 0;
  rep(i,str.length()){
    if(c != str[i]){
      if(i != 0){
        ret.w.push_back(c);
        ret.c.push_back(cnt);
      }
      c = str[i];
      cnt = 1;
    }else{
      cnt++;
    }
  }
  ret.w.push_back(c);
  ret.c.push_back(cnt);
  return ret;
}


int solve(vector<string>& str){
  vector<ST> st;
  rep(i,str.size()){
    st.push_back(calc(str[i]));
  }
  rep(i,st.size()){
    REP(j,i+1,st.size()){
      if(!(st[i] == st[j])) return -1;
    }
  }

  int ret = 0;

  rep(j,st[0].w.size()){
    int mn = 100000000, mx = -1;
    rep(i,st.size()){
      mn = min(mn, st[i].c[j]);
      mx = max(mx, st[i].c[j]);
    }

    int best = 1000000000;
    REP(k,mn,mx+1){
      int a = 0;
      rep(i,st.size()){
        a += abs(st[i].c[j]-k);
      }
      best = min(best, a);
    }
    ret += best;
  }

  return ret;
}


int main(){
  int T;
  
  cin >> T;

  for(int t=0; t<T; t++){
    int N;
    cin >> N;
    vector<string> str;
    string tmp;
    rep(i,N){
      cin >> tmp;
      str.push_back(tmp);
    }

    int ret = solve(str);
    if(ret < 0){
      cout << "Case #" << t+1 << ": Fegla Won" << endl;
    }else{
      cout << "Case #" << t+1 << ": " << ret << endl;
    }
  }
  return 0;
}
