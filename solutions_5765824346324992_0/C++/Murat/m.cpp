#include<bits/stdc++.h>
  
using namespace std;

template<class T> inline T sqr(const T& a) { return a * a; }
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
constexpr ld EPS = 1e-9;
constexpr ld PI = 2 * acos(0.0);
constexpr int N = 100;

li Calc(const vector<int> &a, int b, li t) {
  li cnt = 0;
  for (int i = 0; i < b; ++i) {
    li cur = t / a[i] + 1;
    cnt += cur;
  }
  return cnt;
}

void naive(vector<int> &a, int b, int n) {
  int t = 0;
  while (1) {
    for (int i = 0; i < b; ++i) {
      if (t % a[i] == 0) {
        --n;
        if (n <= 0) {
          cerr << "naive: " << i + 1 << endl;
          return;
        }
      }
    }
    ++t;
  }
}

int main() {
  int ts;
  scanf("%d", &ts);
  for (int it = 1; it <= ts; ++it) {
    int b, n;
    scanf("%d%d", &b, &n);
    //--n;
    vector<int> a(b);
    for (int i = 0; i < b; ++i) {
      scanf("%d", &a[i]);
    }
    li lf = 0, rg = 1e15;
    int ans = -1;
    while (lf + 1 < rg) {
      li mid = (lf + rg) / 2;
      if (Calc(a, b, mid) < li(n))
        lf = mid;
      else
        rg = mid;
    }
    for (; lf <= rg; ++lf) {
      if (Calc(a, b, lf) >= n)
        break;
    }
    vector<int> ready;
    li count = 0;
    for (int i = 0; i < b; ++i) {
      li cur = (lf + a[i] - 1) / a[i];
      count += cur;
      if (lf % a[i] == 0) {
        ready.push_back(i);
      }
    }
    //cerr << "time " << lf << endl;
    //cout << count << ' ' << ready.size() << endl;
    assert(n - count <= li(ready.size()));
    ans = ready[n - count - 1];
    printf("Case #%d: %d\n", it, ans + 1);
    //naive(a, b, n);
  }
  return 0;
}
