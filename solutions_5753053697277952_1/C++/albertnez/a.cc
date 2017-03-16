#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using PII = pair<int,int>;
using VPII = vector<PII>;

bool init;
int ncase;
void f(int a, int b = -1) {
  if (!init) {
    init = true;
    cout << "Case #" << ++ncase << ":";
  }
  cout << " " << char('A'+a);
  if (b >= 0) cout << char('A'+b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  ncase = 0;
  while (T--) {
    init = false;
    int n; cin >> n;
    VPII v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first;
      v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    while (v[0].first > v[1].first) {
      f(v[0].second);
      --v[0].first;
    }
    for (int i = 2; i < n; ++i) {
      while (v[i].first) {
        --v[i].first;
        f(v[i].second);
      }
    }
    while (v[0].first) {
      --v[0].first;
      f(v[0].second, v[1].second);
    }
    cout << endl;
  }
}
