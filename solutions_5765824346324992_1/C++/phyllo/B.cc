#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
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
  int i;
  ll st;
};
bool operator<(const ST& a, const ST& b){
  if(a.st == b.st) return a.i > b.i;
  return a.st > b.st;
}

bool C(ll x, ll N, const vector<ll>& v){
  ll num = 0;
  rep(i,v.size()){
    ll cnt = x / v[i] + 1;
    num += cnt;
  }
  //cerr << x << " " << num << endl;
  return num < N;
}

ll solve(ll N, const vector<ll>& v){
  ll ret = 0;

  if(v.size() >= N) return N;
  
  rep(i,v.size()){
    ll cnt = N/v[i];
    ll rem = N - cnt * v[i];
  }
  ll lb = 0, ub = 10000000000000000LL;
  while(ub-lb>1){
    ll mid = (lb+ub)/2LL;
    if(C(mid, N, v)) lb = mid;
    else ub = mid;
  }
  ll tm = lb;
  //cerr << tm << endl;
  
  ll num = 0;
  priority_queue<ST> que;
  rep(i,v.size()){
    ST st;
    st.i = i+1;
    ll cnt = tm / v[i] + 1;
    num += cnt;
    st.st = v[i] * cnt;
    que.push(st);
  }


  //cerr << N << " " << num << endl;
  while(true){
    ST st = que.top(); que.pop();
    num++;
    if(num == N) return st.i;
    st.st += v[st.i-1];
    que.push(st);
  }
  return 0;
}

int main(){
  int T;

  cin >> T;
  rep(t,T){
    ll N, B, tmp;
    vector<ll> v;
    cin >> B >> N;
    rep(i,B){
      cin >> tmp;
      v.push_back(tmp);
    }
    cout << "Case #" << t+1 << ": " << solve(N, v) << endl;
  }
  
  return 0;
}
