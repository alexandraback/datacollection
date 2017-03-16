#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ci = 1; ci <= t; ++ci) {
    int n;
    cin >> n;
    vector<pair<int, char> > data;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int d;
      cin >> d;
      data.push_back(make_pair(d, 'A' + i));
      sum += d;
    }

    cout << "Case #" << ci << ": ";
    while (sum > 0) {
      int mx = 0;
      int mx_pos;
      for (int i = 0; i < n; ++i) {
        if (mx < data[i].first) {
          mx = data[i].first;
          mx_pos = i;
        }
      }

      --data[mx_pos].first;
      cout << data[mx_pos].second;
      --sum;

      if (sum == 0) break;

      for (int i = 0; i < n; ++i) {
        if (data[i].first * 2 > sum) {
          cout << data[i].second;
          --data[i].first;
          --sum;
          break;
        }
      }

      cout << " ";
    }

    cout << endl;
  }

  return 0;
}
