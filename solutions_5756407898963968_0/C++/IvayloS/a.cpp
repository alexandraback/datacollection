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
int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int test_number = 1; test_number <= nt; test_number++) {
    set<int> possible1, possible2;
    int r;
    vector<vector<int> > a(4, vector<int>(4));
    cin >> r;

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> a[i][j];
      }
    }
    for (int j = 0; j < 4; ++j) {
      possible1.insert(a[r - 1][j]);
    }

    cin >> r;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> a[i][j];
      }
    }
    for (int j = 0; j < 4; ++j) {
      possible2.insert(a[r - 1][j]);
    }
    set<int> total;
    for(set<int>::iterator it = possible1.begin(); it != possible1.end(); ++it) {
      if (possible2.count(*it)) {
        total.insert(*it);
      }
    }

    cout << "Case #" << test_number << ": ";
    if (total.size() > 1) {
      cout << "Bad magician!\n";
    } else if (total.size() < 1) {
      cout << "Volunteer cheated!\n";
    } else {
      cout << *total.begin() << endl;
    }
  }
  return 0;
}
