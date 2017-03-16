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
  int n;
  cin >> n;
  vector<int> m(n);
  rep(i, n) cin >> m[i];
  long long a = 0, b = 0;
  rep(i, n - 1) a += max(0, m[i] - m[i + 1]);
  int inc = 0;  
  rep(i, n - 1)
    inc = max(inc, m[i] - m[i + 1]);
  //PR(inc, m);
  rep(i, n - 1){
    b += min(inc, m[i]);
  }
  
  printf("Case #%d: %lld %lld\n", ca, a, b);
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  rep(i, t) solve(i + 1);
  return 0;
}
