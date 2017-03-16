#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
  os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
  os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<int N,class Tuple> void out(ostream&,const Tuple&) {}
template<int N,class Tuple,class,class ...Ts> void out(ostream &os,const Tuple &t) {
	if(N)os<<","; os<<get<N>(t); out<N+1,Tuple,Ts...>(os,t);
}
template<class ...Ts> ostream& operator<<(ostream &os, const tuple<Ts...> &t) {
  os<<"("; out<0,tuple<Ts...>,Ts...>(os,t); os<<")"; return os;
}
template<class T>void output(T *a, int n) {REP(i,n){if(i)cout<<",";cout<<a[i];}cout<<endl;}
template<class T>void output(T *a, int n,int m) { REP(i,n) output(a[i],m);}

int solve() {
  int n;
  cin >> n;
  string s[100];
  REP(i,n) {
    cin >> s[i];
  }
  string t = s[0];
  t.erase(unique(ALL(t)), t.end());
  vector<vector<int> > v;
  REP(i,n) {
    string tmp = s[i];
    tmp.erase(unique(ALL(tmp)), tmp.end());
    if (tmp != t) return -1;
    int cnt = 0;
    char pre = ' ';
    vector<int> tv;
    REP(j,s[i].size()) {
      if (s[i][j] != pre) {
        if (cnt) {
          tv.push_back(cnt);
        }
        cnt = 1;
        pre = s[i][j];
      } else {
        cnt++;
      }
    }
    tv.push_back(cnt);
    // cout << s[i] << endl;
    // cout << tv << endl;
    v.push_back(tv);
  }
  int ans = 0;
  REP(i,v[0].size()) {
    int tt = INF;
    for (int k=1; k<=100; ++k) {
      int tmp = 0;
      REP(j,v.size()) {
        tmp += abs(v[j][i]-k);
      }
      chmin(tt, tmp);
    }
    ans += tt;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    int ans = solve();
    printf("Case #%d: ", cs+1);
    if (ans == -1) { puts("Fegla Won"); }
    else {
      cout << ans << endl;
    }
  }
}
