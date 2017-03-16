 
/* ========================================

   * File Name : B.cpp

   * Creation Date : 02-05-2015

   * Last Modified : Sat 02 May 2015 07:07:46 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

int solve(int r, int c, int n) {
  int res = 2 * r * c;
  int unhappinness = 0;
  REP(d, 1<<(r*c)) {
    if (__builtin_popcountll(d) == n) {
      unhappinness = 0;

      // verts
      REP(a,r) REP(b,c-1) {
        unhappinness += ( ((d >> (a * c + b)) & 1) & ((d >> (a * c + b + 1)) & 1) );
      }

      // horz
      REP(a,r-1) REP(b,c) {
        unhappinness += ( ((d >> (a * c + b)) & 1) & ((d >> (a * c + b + c)) & 1) );
      }
      res = min(res, unhappinness);
    }
  }

  return res;
}

int main() {
  int t,r,c,n;
  cin >> t;
  REP(i,t) {
    cin >> r >> c >> n;
    printf("Case #%d: %d\n", i+1, solve(r,c,n));
  }
  return 0;
}
