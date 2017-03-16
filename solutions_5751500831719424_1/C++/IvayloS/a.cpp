/*
 * a.cpp
 *
 *  Created on: May 3, 2014
 *      Author: istrandjev
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

vector<pair<char, int> > decompose(const std::string& s) {
  char cur = '\0';
  int num = 0;
  vector<pair<char, int> > res;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != cur) {
      if (num > 0) {
        res.push_back(make_pair(cur, num));
      }
      cur = s[i];
      num = 1;
    } else {
      num++;
    }
  }
  if (num > 0) {
    res.push_back(make_pair(cur, num));
  }
  return res;
}
bool same(const vector<pair<char, int> >& a,
    const vector<pair<char, int> >& b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i].first != b[i].first) {
      return false;
    }
  }
  return true;
}
inline int myabs(int x) {
  return x >= 0 ? x : -x;
}
int get(const vector<vector<pair<char, int> > >& d, int index) {
  int n = (int)d.size();
  int best = n * 128;
  for (int num = 1; num < 128; ++num) {
    int temp = 0;
    for (int i = 0; i < (int)d.size(); ++i) {
      temp += myabs(d[i][index].second - num);
    }
    best = min(best, temp);
  }
  return best;
}

int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n;
    cin >> n;
    vector<string> a(n);
    getline(cin, a[0]);
    for (int i = 0; i < (int)a.size(); ++i) {
      getline(cin, a[i]);
    }

    vector<vector<pair<char, int> > > d(n);
    for (int i = 0; i < (int)a.size(); ++i) {
      d[i] = decompose(a[i]);
    }
    bool can = true;
    for (int i = 1; i < (int)a.size(); ++i) {
      if (!same(d[0], d[i])) {
        can = false;
      }
    }
    if (!can) {
      cout << "Case #" << it << ": Fegla Won" << endl;
      continue;
    }
    int ans = 0;
    for (int i = 0; i < (int)d[0].size(); ++i) {
      ans += get(d, i);
    }
    cout << "Case #" << it << ": " << ans << endl;
  }
  return 0;
}

