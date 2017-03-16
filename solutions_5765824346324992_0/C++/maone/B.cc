#include <iostream>
using namespace std;

int64_t n, b;
int64_t m[1024];

int64_t hm(int64_t mid) {
  int64_t count = 0;
  for (int i = 0; i < b; ++i) {
    count += (mid + m[i]) / m[i];
  }
  return count;
}

int run() {
  int64_t left = -1, right = n * m[0];
  while (left + 1 < right) {
    int64_t mid = (left + right) / 2;
    int64_t count = hm(mid);
    if (count >= n) {
      right = mid;
    } else {
      left = mid;
    }
  }

  n -= hm(right - 1);
  for (int i = 0; i < b; ++i) {
    if (right % m[i] == 0) {
      --n;
      if (!n) return i + 1;
    }
  }
  return -1;
}

int main(int argc, const char* argv[]) {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ": ";
    cin >> b >> n;
    for (int j = 0; j < b; ++j) {
      cin >> m[j];
    }
    cout << run() << endl;
  }
  return 0;
}
