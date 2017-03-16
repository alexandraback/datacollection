#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
#define pb         push_back
#define all(a)     (a).begin(),(a).end()
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)
#define each(a,b)  for (__typeof((a).begin()) b=(a).begin(); b!=(a).end(); b++)

int dup(map<int, int> &h) {
  int r = 0;
  each(h, it) if (it->second==2) r++;
  return r;
}

int card(map<int, int> &h) {
  int r = 0;
  each(h, it) if (it->second==2) r = it->first;
  return r;
}

int main () {
  int T; cin >> T;
  rep (t, T) {
    map<int, int> x;
    rep (k, 2) {
      int a; cin >> a;
      rep (i, 4) rep (j, 4) {
        int d; cin >> d;
        if (i+1==a) x[d]++;
      }
    }

    int s = dup(x);
    if (s == 1) {
      cout << "Case #" << t+1 << ": " << card(x) << endl;
    } else if (s == 0) {
      cout << "Case #" << t+1 << ": Volunteer cheated!" << endl;
    } else {
      cout << "Case #" << t+1 << ": Bad magician!"<< endl;
    }
  }
  return 0;
}
