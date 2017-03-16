#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n; cin >> n;
    vector<int> plate(n);
    for (int i = 0; i < n; ++i) {
      cin >> plate[i];
    }

    int part_a = 0;
    int max_rate = 0;
    for (int i = 0; i < n - 1; ++i) {
      part_a += max(0, plate[i] - plate[i+1]);
      max_rate = max(max_rate, plate[i] - plate[i+1]);
    }

    int part_b = 0;
    for (int i = 0; i < n - 1; ++i) {
      part_b += min(max_rate, plate[i]);
    }
    cout << "Case #" << test << ": " << part_a << " " << part_b << endl;
  }
  return 0;
}