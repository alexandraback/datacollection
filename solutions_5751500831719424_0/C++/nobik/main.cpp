#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

string toGood(string s){
  string res = "";
  int it = 0;
  forn(i, s.size()){
    res += s[i];
    int j = i;
    while(j < s.size() && s[i] == s[j]) ++j;
    i = j - 1;
  }
  return res;
}

vector<int> rep(string s){
  vector<int> res;
  int it = 0;
  forn(i, s.size()){
    int j = i;
    while(j < s.size() && s[i] == s[j]) ++j;
    res.pb(j - i);
    i = j - 1;
  }
  return res;
}

vector<int> g[105];

void Solve(){
  int n; cin >> n;
  forn(i, 105) g[i].clear();
  string good = "";
  forn(i, n){
    string s; cin >> s;
    string now = toGood(s);
    if(!good.empty() && good != now){
      cout << "Fegla Won" << "\n";
      return;
    }
    good = now;
    vector<int> r = rep(s);
    forn(i, r.size()) g[i].pb(r[i]);
  }
  int res = 0;
  forn(i, good.size()){
    sort(all(g[i]));
    int m = g[i].size() / 2;
    forn(j, g[i].size()){
      res += abs(g[i][j] - g[i][m]);
    }
  }
  cout << res << "\n";
}

int main(void){
  #ifdef nobik
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  forn(i, t){
    cout << "Case #" << i + 1 << ": ";
    Solve();
  }
  return 0;
}
