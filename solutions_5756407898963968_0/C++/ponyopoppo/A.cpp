#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define reprit(i, v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define to_str(v) #v
using namespace std;
typedef long long ll;

template<class X>
ostream& operator<<(ostream& os, const vector<X> &v) {
  repit(itr, v) cout << *itr << " ";
  cout << " size : " << v.size();;
  return os;
}

int c[4][4];
bool fst[17], scd[17];

int solve() {
  int f, s;
  memset(fst, 0, sizeof(fst));
  memset(scd, 0, sizeof(scd));
  cin >> f; f--;
  rep(i, 4) rep(j, 4) {
    cin >> c[i][j];
    if(i == f) fst[c[i][j]] = true;
  }
  cin >> s; s--;
  rep(i, 4) rep(j, 4) {
    cin >> c[i][j];
    if(i == s) scd[c[i][j]] = true;
  }

  int cnt = 0;
  int ret = -2;
  rep(i, 17) if(fst[i] && scd[i]) {
    if(cnt) return -1;
    ret = i;
    cnt++;
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    int ans = solve();
    if(ans == -1) cout << "Bad magician!";
    else if(ans == -2) cout << "Volunteer cheated!";
    else cout << ans;
    cout << endl;
  }
  return 0;
}
