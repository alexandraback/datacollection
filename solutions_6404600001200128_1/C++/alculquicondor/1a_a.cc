#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 10001

using namespace std;

int n;
int A[MAXN];

int first_method() {
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (A[i] < A[i-1])
      ans += A[i-1] - A[i];
  }
  return ans;
}

int second_method() {
  int dif = 0;
  for (int i = 1; i < n; ++i)
    dif = max(dif, A[i-1] - A[i]);
  int ans = 0;
  for (int i = 0; i < n - 1; ++i)
    ans += min(A[i], dif);
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  cout << first_method() << ' ' << second_method();
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int cs = 1; cs <= tc; ++cs) {
    cout << "Case #" << cs << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
