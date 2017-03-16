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

int n;
vector<string> v;
void input() {
  cin >> n;
  v.resize(n);
  rep(i, n) cin >> v[i];
}

/*
void UNIQUE(string &s) {
  rep(i, s.size()-1) {
    if(s[i] == s[i+1]) {
      s = s.substr(0, i) + s.substr(i+2);
    }
  }
  }*/

void solve() {
  string s = v[0];

  UNIQUE(s);
  vector<int> idx(n);

  rep(i, n) {
    string tmp = v[i];
    UNIQUE(tmp);
    if(tmp != s) {
      cout << "Fegla Won";
      return;
    }
  }
  
  int ans = 0;
  rep(i, s.size()) {
    vector<int> cnt(n);
    rep(j, n) {
      while(idx[j] < v[j].size() && v[j][idx[j]] == s[i]) {
	cnt[j]++;
	idx[j]++;
      }
    }
    int tmp = 1000000;
    int lim = 0;
    rep(j, n) lim = max(lim, cnt[j]);

    rep(k, lim+1) {
      int sum = 0;
      rep(j, n) {
	sum += abs(cnt[j] - k);
      }
      tmp = min(tmp, sum);
    }
    ans += tmp;
  }
  cout << ans;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    input();
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
