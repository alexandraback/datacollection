#include <iostream>
using namespace std;

int n;
int m[1024];

int main(int argc, const char* argv[]) {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ": ";
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> m[j];
    }

    int64_t sum1 = 0, sum2 = 0;
    int dec = 0;
    for (int j = 1; j < n; ++j) {
      sum1 += max(0, m[j - 1] - m[j]);
      dec = max(dec, m[j - 1] - m[j]);
    }
    for (int j = 0; j + 1 < n; ++j) {
      sum2 += min(dec, m[j]);
    }
    cout << sum1 << ' ' << sum2 << endl;
  }

  return 0;
}
