#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define iter(a) __typeof(a.begin())
#define FOR(it,a) for(iter(a)it=a.begin();it!=a.end();++it)
#define F first
#define S second
#define SZ(a) (int)((a).size())
#define sz(a) SZ(a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ALL(a) (a).begin(),(a).end()
using namespace std;

typedef long long ll;
typedef pair<int,int> PI;
typedef unsigned long long ull;

#ifdef ONLINE_JUDGE
#define PR(...) (void(0))
#else
#define PR(...) do{cerr << "line : " << __LINE__ << endl; pr(#__VA_ARGS__, __VA_ARGS__);}while(0)
template<class T>
void pr(const string& name, T t){
  cerr << name << ": " << t << endl;
}
template<typename T, typename ... Types>
void pr(const string& names, T t, Types ... rest) {
  auto comma_pos = names.find(',');
  cerr << names.substr(0, comma_pos) << ": " << t << ", ";
  auto next_name_pos = names.find_first_not_of(" \t\n", comma_pos + 1);
  pr(string(names, next_name_pos), rest ...);
}
#endif

template<class T,class U> ostream& operator<< (ostream& o, const pair<T,U>& v){return o << "(" << v.F << ", " << v.S << ")";}
template<class T> ostream& operator<< (ostream& o, const vector<T>& v){o << "{";rep(i,SZ(v)) o << (i?", ":"") << v[i];return o << "}";}
template<class T,class U> ostream& operator<< (ostream& o, const map<T,U>& v){o << "{";for(const auto& e : v) o << e << ", ";return o << "}";}
template<class T> string to_s(const T& v){ostringstream is;is << v;return is.str();}
//                 <  ^  >  V
const int dx[] = { 0,-1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
#define endl '\n'

void solve(int ca){
  ll n;
  int m;
  cin >> m >> n;
  vector<ll> in(m);
  rep(i, m) cin >> in[i];
  //PR(in);
  ll low =0, up = 1LL << 60LL;
  while(low + 1 < up){
    ll mid = (low + up) / 2;
    ll en = 0;
    rep(i, m) en += mid / in[i] + 1;
    //PR(mid, en);
    if(en >= n) up = mid;
    else low = mid;
  }
  
  //PR(low);
  ll ans = 0;
  
  priority_queue<pair<ll, ll> > bar;
  ll end = 0;
  rep(i, m){
    end += (low - 1 + in[i]) / in[i];
    bar.push(mp(- (low - 1 + in[i]) / in[i] * in[i], -i));
  }
  
  while(end < n){
    auto p = bar.top();
    bar.pop();
    //PR(end, p);
    ans = -p.S;
    bar.push(mp(p.F - in[-p.S], p.S));
    ++end;
  }
  
  printf("Case #%d: %lld\n", ca, ans + 1);
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  rep(i, t) solve(i + 1);
  return 0;
}
